#include <stdlib.h>
#include <stdio.h>
#include "main.h"


// calcul de la génération suivante
int nextGen(char*gen1, char*gen2, int sizeX, int sizeY) {
    int nbLives = 0;
    // on crée dans gen2 les êtres vivants à partir de l'état du tableau Gen1
    for(int l = 0; l < sizeY; l++) {
        // les variables letc représentent la position d’une case en (ligne, colonne)
        for(int c = 0; c < sizeX; c++) {
            *(gen2+(l*sizeX + c)) = lifeState(countNeighbours(gen1,sizeX,sizeY,c,l), *(Gen2+(l*sizeX + c)));
            if(*(gen2+(l*sizeX + c))==Alive) 
                nbLives++;
            }
        }
    return(nbLives); };

int init(char*life, int sizeX, int sizeY){
    // creation d'un tableau de taille sizeX x sizeY
    for (int i = 0; i < sizeX; i++)
    {
        for (int j = 0; i < sizeY; i++)
        {
            printf("%d",life[(i*LifeSizeX)+j] = 0);
        }
        
    }
    return life;
}
initLife(Gen1, 30, 30)
