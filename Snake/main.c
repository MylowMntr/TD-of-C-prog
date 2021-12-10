#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "ConsoleTools.c"

#define TAILLEMAX 9
#define pomme '@'
#define snake '*'
#define free ' '


int initLife(char*game, int sizeX, int sizeY, int snakesize){
    // creation d'un tableau de taille sizeX x sizeY
    for (int i = 0; i <= sizeX; i++)
    {
        for (int j = 0; j <= sizeY; j++)
        {
            int k = (i*TAILLEMAX)+j;
            // printf("%d\n",k);
            game[k] = free;
        } 
    }

    // add pomme
    srand(time(NULL));
    for (int i = 0; i < (sizeX/3); i++)
    {
        int pos = (rand() % (TAILLEMAX*TAILLEMAX)); 
        // pos = 7;
        // printf("%d\n",pos);
        game[pos] = pomme;
    }

    // add snake

    for (int i = 0; i <= snakesize; i++){
        game[i] = snake;
    }
    

    return 0;
};


void displayGen(char*game, int sizeX, int sizeY){
    // printf("%c\n", game[16]);
    
    openConsole();
    clearScreen();
    moveCursor(0,0);
    for (int i = 0; i <= sizeX; i++)
    {
        for (int j = 0; j <= sizeY; j++)
        {
            if (j == 0){
                printf("\n");
            }
            else{
                if (game[(i*TAILLEMAX)+j] == pomme){
                    plotChar(pomme);
                }
                else if (game[(i*TAILLEMAX)+j] == snake){
                    plotChar(snake);
                }
                else{
                    plotChar(free);
                }
            }
        } 
    }
    closeConsole();
};

int main() {
    char* game = malloc(TAILLEMAX*TAILLEMAX*sizeof(char));
    int snakesize = 5;
    initLife(game,TAILLEMAX,TAILLEMAX,snakesize);
    displayGen(game,TAILLEMAX,TAILLEMAX);

    return 0;
} 