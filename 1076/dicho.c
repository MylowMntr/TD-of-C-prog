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

int dicho(int tab[],int i, int j, int X){
    if (X > tab[j]){
        return j+1;
    }
    while (i!=j){
        int k = (i+j) / 2;
        if (X<=tab[k]){
            j=k;
        }
        else{
            i = k+1;
        }
    }
    return i;
}


int tri_insert(int tab[]){
    int tmp;
    int permu = 0;
    int comp = 0;
    for (int i = 1; i < taille; i++)
    {
        for (int j = 0; j < taille -1; j++)
        {        
            comp ++;
            if (tab[i]< tab[i-1]){
                int k = dicho(tab,0,i-1,tab[i]);
                tmp = tab[i];
                tab[i] = tab[k];
                tab[k] = tmp;
                permu ++;
            }
        }
    }
    printf("Conversion: %lld, Permutation: %lld, n: %lld, n2: %lld\n",comp,permu,taille,(taille*taille));
    return 0;
    
}

int main(){    
    srand((unsigned)time(NULL));
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