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
void affichage(int tab[])
{
    for (int i = 0; i < taille; i++)
    {
        printf("%d-", tab[i]);
    }
    printf("\n");
}

int tri_insert(int tab[]){
    int j,tmp;
    int comp,permu = 0;
    for (int i = 1; i <= taille - 1; i++)
    {
        j = i;
        comp ++;
        while (j > 0 && tab[j - 1] > tab[j])
        {
            tmp = tab[j];
            tab[j] = tab[j - 1];
            tab[j - 1] = tmp;
            permu ++;
            j--;
        }
    }
    printf("Conversion: %lld, Permutation: %lld, n: %lld, n2: %lld\n",comp,permu,taille,(taille*taille));
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

    tri_insert(tab);

    affichage(tab);

    return 0;
}