#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "fonc.h"
#include "ConsoleTools.c"


int initLife(char*life, int sizeX, int sizeY){
    // creation d'un tableau de taille sizeX x sizeY
    for (int i = 0; i <= sizeX; i++)
    {
        for (int j = 0; j <= sizeY; j++)
        {
            int k = (i*LifeSizeX)+j;
            // printf("%d\n",k);
            life[k] = Dead;
        } 
    }
    srand(time(NULL));
    for (int i = 0; i < (sizeX*3); i++)
    {
        int pos = (rand() % (LifeSizeX*LifeSizeY)); 
        // pos = 7;
        // printf("%d\n",pos);
        life[pos] = Alive;
    }

    return 0;
};

int countNeighbours(char*life, int sizeX, int sizeY, int posX, int posY){
    int nbvoisins = 0;
    for (int i = (posX-1); i <= (posX+1); i++)
    {
        for (int j = (posY-1); j <= (posY+1); j++)
        {
            if ((life[i*sizeX+j] == Alive) && ( (i != posX) || (j != posY) ) ){
                nbvoisins++;
            }
        }   
    }
    return nbvoisins;
};

char lifeState(int nbNeighbours, char state){
    if (nbNeighbours == 3){
        state = Alive;
    }
    else if ((nbNeighbours == 2 || nbNeighbours == 3) && (state == Alive)){
        state = Alive;
    }
    else{
        state = Dead;
    }
    return state;
};

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
    return(nbLives); 
};

void displayGen(char*life, int sizeX, int sizeY){
    // printf("%c\n", life[16]);

    openConsole();
    moveCursor(0,0);
    for (int i = 0; i <= sizeX; i++)
    {
        for (int j = 0; j <= sizeY; j++)
        {
            if (j == 0){
                printf("\n");
            }
            else{
                if (life[(i*LifeSizeX)+j] == Alive){
                    plotChar(Alive);
                }
                else{
                    plotChar(Dead);
                }
            }
        } 
    }
    closeConsole();
};

int main() {
    Gen1 = malloc(LifeSizeX*LifeSizeY*sizeof(char));
    Gen2 = malloc(LifeSizeX*LifeSizeY*sizeof(char));
    initLife(Gen1,LifeSizeX,LifeSizeY);
    displayGen(Gen1,LifeSizeX,LifeSizeY);

    
    // for (int i = 0; i <= LifeSizeX; i++)
    // {
    //     for (int j = 0; j <= LifeSizeY; j++)
    //     {
    //         if (j == 0){
    //             printf("\n");
    //         }
    //         else{
    //             printf("%d", countNeighbours(Gen1,LifeSizeX,LifeSizeY,i,j));
    //         }
    //     } 
    // }
    for (int i = 0; i < 4; i++)
    {   
        printf("\n");
        nextGen(Gen1,Gen2,LifeSizeX,LifeSizeY);
        Gen1 = Gen2;
        displayGen(Gen1,LifeSizeX,LifeSizeY);
        sleep(1);
    }

    return 0;
} 