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
    int comp,permu = 0;
    for (int i = 0; i < (taille - 1); i++)
    {
        index = i;

        for (int j = i + 1; j < taille; j++)
        {
            comp ++;
            if (tab[index] > tab[j])
                index = j;
        }
        if (index != i)
        {   
            tmp = tab[i];
            tab[i] = tab[index];
            tab[index] = tmp;
            permu ++;
        }
    }
    printf("Conversion: %lld, Permutation: %lld, n: %lld, n2: %lld\n",comp,permu,taille,(taille*taille));
    return 0;
}


int main(){
    int tab[taille];
    char type = 'a';
    if (type == 'a'){
        // Création d'un tableau de valeur aléatoire
        for( int i = 0; i < taille; i++){
            tab[i] = (int)((double)rand() / ((double)RAND_MAX + 1) * ((double)1000 - (double)0)) + 0;
        }
    }
    if (type == 'c')
        // Création d'un tableau de valeur ordonné croissant
        for (int i = 0; i < taille; i++)
        {
            tab[i] = i;
        }
    if (type == 'd')
        // Création d'un tableau de valeur ordonné décroissant
        for (int i = 0; i < taille; i++)
        {
            tab[i] = taille-i;
        }
    affichage(tab);

    tri_selec(tab);

    affichage(tab);

    return 0;
}