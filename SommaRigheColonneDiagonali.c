#include <stdio.h>
#include <stdlib.h>
#define MAX 10

//INIZIO PROTOTIPI
int inputdim(); //Input Dimensione Matrice
int inputmenu(); //Input per il menu
void inputmat(int matrice[][MAX], int x, int y); //Input Matrice
void sommarighe(int matrice[][MAX], int x, int y); //Somma delle righe
void sommacolonne(int matrice[][MAX], int x, int y); //Somma delle colonne
void sommadiagonale(int matrice[][MAX], int x, int y); //Somma delle diagonali
//FINE PROTOTIPI

int main() {

    int mat[MAX][MAX];
    int rig;
    int col;
    int menu;
    int fine;
    fine = 0;

    printf("INSERISCI IL NUMERO DI RIGHE: ");
    rig=inputdim();
    printf("INSERISCI IL NUMERO DI COLONNE: ");
    col=inputdim();

    inputmat(mat, rig, col);
    printf("\nCosa vuoi fare?\n1) Somma delle righe\n2) Somma delle colonne\n3) Somma delle diagonali\n4) FINE\n");
    do{
        menu=inputmenu();
        switch(menu){
            case 1:
                sommarighe(mat, rig, col);
                break;

            case 2:
                sommacolonne(mat, rig, col);
                break;

            case 3:
                sommadiagonale(mat, rig, col);
                break;
            case 4:
                fine = 1;
                break;
            default:
                printf("INPUT NON VALIDO\n");
                break;
        }
    }while(fine == 0);
    return 0;
}

int inputdim(){
    int val;
    val = 0;
    do{                                                                      
        scanf("%d", &val);
    }while(val < 0 || val > MAX);
    return val;
}

void inputmat(int matrice[][MAX], int x, int y){
    int i;
    int j;
    for(i = 0; i < x; i++){                                                              
        for(j = 0; j < y; j++){
            printf("Inserisci elemento nelle coordinate [%d;%d]: ",i , j);
            scanf("%d", &matrice[i][j]);
        }
    }
}

int inputmenu(){
    int num;
    num = 0;
    printf("Inserisci la tua scelta qui: ");                         
    scanf("%d", &num);
    return num;
}

void sommarighe(int matrice[][MAX], int x, int y){
    int i;
    int j;
    int somma;
    somma = 0;
    for(i = 0; i < x; i++){                                                                
        for(j = 0; j < y; j++){
            somma = somma + matrice[i][j];
        }
        printf("\nLa somma della riga numero %d e' %d\n", i + 1, somma);
        somma = 0;
    }
}
void sommacolonne(int matrice[][MAX], int x, int y){
    int i;
    int j;
    int somma;
    somma = 0;
    for(j = 0; j < y; j++){                                                              
        for(i = 0; i < x; i++){
            somma = somma + matrice[i][j];
        }
        printf("\nLa somma della cononna numero %d e' %d\n", j+1, somma);
        somma=0;
    }
}


void sommadiagonale(int matrice[][MAX], int x, int y){
    int somma;
    int i;
    int j;
    somma = 0;
    j = 0;
    if(x == y){
        for(i = 0; i < x; i++, j++){
            somma = somma + matrice[i][j];
        }
        printf("\nLa somma della prima diagonale e' %d\n", somma);
        j = y - 1;
        somma = 0;
        for(i = 0; i < x; i++, j--){
            somma = somma + matrice[i][j];
        }
        printf("\nLa somma della seconda diagonale e': %d\n", somma);
    }
    else{
        printf("\nNon e' possibile individuare le diagonali\n");
    }
}
