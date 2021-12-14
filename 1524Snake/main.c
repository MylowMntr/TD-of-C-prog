#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "ConsoleTools.c"

#define TAILLEMAX 20
#define pomme '@'
#define snake '*'
#define free ' '


int initLife(char*game, int sizeX, int sizeY, int snakesize, int snakestart, int pos[]){
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
    for (int i = 0; i < (20); i++)
    {
        int pom = (rand() % (TAILLEMAX*TAILLEMAX)); 
        // pos = 7;
        // printf("%d\n",pos);
        game[pom] = pomme;
    }

    // add snake
    for (int i = 0; i < snakesize; i++)
    {
        pos[i] = snakestart+i;
    }
    
    possnake(game,snakestart,snakesize, pos);

    return 0;
};

int possnake(char*game,int snakestart, int snakesize, int pos[]){
    for (int i = 0; i <= snakesize ; i++){
        game[pos[i]] = snake;
    }
}

int up(char*game, int snakestart, int snakesize, int pos[]){
    game[pos[0]] = free;
    for (int i = 0; i < snakesize; i++)
    {
        pos[i] = pos[i+1];
    }
    pos[snakesize] = pos[snakesize]-TAILLEMAX;
    if (game[pos[snakesize]] == pomme){
        snakesize++;
    }
    possnake(game,snakestart,snakesize, pos);
    return snakesize;
}

int right(char*game, int snakestart, int snakesize , int pos[]){
    game[pos[0]] = free;
    for (int i = 0; i < snakesize; i++)
    {
        pos[i] = pos[i+1];
    }
    pos[snakesize] = pos[snakesize]+1;
    if (game[pos[snakesize]] == pomme){
        snakesize++;
    }
    possnake(game,snakestart,snakesize, pos);
    return snakesize;
}

int down(char*game, int snakestart, int snakesize, int pos[]){
    game[pos[0]] = free;
    for (int i = 0; i < snakesize; i++)
    {
        pos[i] = pos[i+1];
    }
    pos[snakesize] = pos[snakesize]+TAILLEMAX;
    if (game[pos[snakesize]] == pomme){
        snakesize++;
    }
    possnake(game,snakestart,snakesize, pos);
    return snakesize;
}

int left(char*game, int snakestart, int snakesize, int pos[]){
    game[pos[0]] = free;
    for (int i = 0; i < snakesize; i++)
    {
        pos[i] = pos[i+1];
    }
    pos[snakesize] = pos[0]-1;
    if (game[pos[snakesize]] == pomme){
        snakesize++;
    }
    possnake(game,snakestart,snakesize, pos);
    return snakesize;
}

int next(char*game, int snakesize, int snakestart, int pos[]){
    // printf("%d",snakestart);
    srand(time(NULL));
    int dir = (rand() % (4))+1;
    // dir = 2;
    switch (dir){
        case 1:
            snakesize = up(game, snakestart, snakesize, pos);
            break;
        case 2:
            snakesize = right(game, snakestart, snakesize, pos);
            break;
        case 3:
            snakesize = down(game, snakestart, snakesize, pos);
            break;
        case 4:
            snakesize = left(game, snakestart, snakesize, pos);
            break;
        
        default:
            break;
    }
    return snakesize;    
}

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
    int snakestart = 50;
    int pos[TAILLEMAX] = {0};
   
    initLife(game,TAILLEMAX,TAILLEMAX,snakesize,snakestart, pos);
    displayGen(game,TAILLEMAX,TAILLEMAX);
    for (int i = 0; i < 50; i++)
    {
        Sleep(300);
        snakesize = next(game,snakesize,snakestart, pos);

        // for (int i = 0; i < TAILLEMAX; i++)
        // {
        //     printf("%d-",pos[i]);
        // }
        // printf("%d\n",snakesize);

        displayGen(game,TAILLEMAX,TAILLEMAX);
        
    }
    printf("\n ------- La chenille a manger %d pommes. ------- ", (snakesize-5));

    return 0;
} 