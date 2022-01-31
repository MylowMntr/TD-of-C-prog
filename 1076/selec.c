#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#define taille 10

void swap(int *xp, int *yp)
{
    int tmp = *xp;
    *xp = *yp;
    *yp = tmp;
}
void affichage(int tab[]){
    for( int i = 0; i < taille; i++){
		printf("%d-",tab[i]);
	}
    printf("\n");
}

int tri_selec(int tab[]){
    int tmp, index;
    for (int i = 0; i < (taille - 1); i++)
    {
        index = i;

        for (int j = i + 1; j < taille; j++)
        {
            if (tab[index] > tab[j])
                index = j;
        }
        if (index != i)
        {   
            tmp = tab[i];
            tab[i] = tab[index];
            tab[index] = tmp;
        }
    }
    return 0;
}


int main(){
    int tab[taille] = {3, 2, 7, 10, 5, 22, 1, 27, 25, 30};

    affichage(tab);

    tri_selec(tab);

    affichage(tab);

    return 0;
}