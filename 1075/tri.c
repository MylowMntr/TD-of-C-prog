#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#define taille 10000

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void affichage(int tab[]){
    for( int i = 0; i < taille; i++){
		printf("%d-",tab[i]);
	}
    printf("\n");
}

int tri_naif(char type){
    int tab[taille];
    if (type == "a")
        // Création d'un tableau de valeur aléatoire
        for( int i = 0; i < taille; i++){
            tab[i] = (int)((double)rand() / ((double)RAND_MAX + 1) * ((double)1000 - (double)0)) + 0;
        }
    if (type == "c")
        // Création d'un tableau de valeur ordonné croissant
        for (int i = 0; i < taille; i++)
        {
            tab[i] = i;
        }
    if (type == "d")
        // Création d'un tableau de valeur ordonné décroissant
        for (int i = 0; i < taille; i++)
        {
            tab[i] = taille-i;
        }
    
    // Nombre d'iteration
    int comp = 0;
    long long permu = 0;
    // affichage(tab);
    for (int j = taille-1; j >= 1; j--)
    {   
        for (int i = 0; i <= j-1; i++)
        {   
            comp++;     
            if (tab[i] > tab[i+1]){
                swap(&tab[i+1], &tab[i]);
                permu++;
            }
        }
    }
    // affichage(tab);
    (printf("Comparaison : %d, Permutation: %d\navec n = %d, et n2= %d\n",comp,permu, taille, taille^2));
    return 0;
}
int tri_bulle(char type){    
    int tab[taille];
    if (type == "a")
        // Création d'un tableau de valeur aléatoire
        for( int i = 0; i < taille; i++){
            tab[i] = (int)((double)rand() / ((double)RAND_MAX + 1) * ((double)1000 - (double)0)) + 0;
        }
    if (type == "c")
        // Création d'un tableau de valeur ordonné croissant
        for (int i = 0; i < taille; i++)
        {
            tab[i] = i;
        }
    if (type == "d")
        // Création d'un tableau de valeur ordonné décroissant
        for (int i = 0; i < taille; i++)
        {
            tab[i] = taille-i;
        }

    // Nombre d'iteration
    int comp = 0;
    long long permu = 0;
    // affichage(tab);
    for (int j = taille-1; j >= 1; j--)
    {   
        bool tabtri = true;
        for (int i = 0; i <= j-1; i++)
        {     
            comp++;   
            if (tab[i] > tab[i+1]){
                swap(&tab[i+1], &tab[i]);
                tabtri = false;
                permu++;
            }
        }
        if (tabtri = true);
            break;
    }
    // affichage(tab);
    return (printf("Comparaison : %d, Permutation: %d\navec n = %d, et n2= %d\n",comp,permu,(taille),(taille)*(taille)));
}

int main(){
    srand((unsigned)time(NULL));
    printf("Nbr d'iterations \n");

    // tri avec un tableau:  a = aleatoire, c = croissant, d = decroissant
    char type = "a";


    //https://openclassrooms.com/forum/sujet/calcul-temps-execution-84649
    int time1 = 0;
    printf("Naif: \n");
    tri_naif(type);
    time1 = clock();
    printf("Temps d'execution = %d ms\n", time1);
    
    printf("-------\n");
    int time2 = 0;
    printf("Bulle: \n");
    tri_bulle(type);
    time2 = clock();
    printf("Temps d'execution = %d ms\n", time2);
    return 0;
}