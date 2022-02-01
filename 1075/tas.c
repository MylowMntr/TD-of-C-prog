#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#define taille 10

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

// https://isen.junia.ovh/cir1/slides.html?presentation=algo/tris/tri_par_tas#11
int insert(int tab[], int pos,int*permu, int*comp){
    int currentNode,tmp;
    int father;
    currentNode = pos;
    father = (currentNode-1)/2;
    while ((currentNode > 0) && (tab[currentNode] > tab[father])){
        comp ++;
        tmp = tab[currentNode];
        tab[currentNode] = tab[father];
        tab[father] = tmp;
        permu ++;
        currentNode = father;
        father = (currentNode -1)/2;
    }
}

int remo(int tab[], int pos, int*permu, int*comp){
    int tmp,currentChild, leftChild, rightChild, maxChild;
    bool stop;
    currentChild = 0;
    stop = false;
    tmp = tab[0];
    tab[0] = tab[pos];
    tab[pos] = tmp;
    permu++;
    leftChild = 2*currentChild + 1;
    rightChild = 2*currentChild + 2;
    while ((!stop) && ((leftChild) <= (pos - 1)))
    {
        comp ++;
        if ((leftChild == pos - 1) || (tab[leftChild] > tab[rightChild])){
            maxChild = leftChild;
        }
        else{
            maxChild = rightChild;
        }
        if (tab[currentChild < tab[maxChild]])
        {
            tmp = tab[currentChild];
            tab[currentChild] = tab[maxChild];
            tab[maxChild] = tmp;
            permu++;
            currentChild = maxChild;
            leftChild = 2*currentChild + 1;
            rightChild = 2*currentChild + 2;
        }
        else{
            stop = true;
        }
        
    }
    
}

int tri_tas(char type){
    int tab[taille];
    if (type == 'a')
        // Création d'un tableau de valeur aléatoire
        for( int i = 0; i < taille; i++){
            tab[i] = (int)((double)rand() / ((double)RAND_MAX + 1) * ((double)1000 - (double)0)) + 0;
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
    int *permu = 0;
    int *comp = 0;
    for (int i = 1; i < (taille); i++)
    {
        insert(tab,i,permu,comp);
    }
    for (int i = 1; i < (taille); i++)
    {
        remo(tab,(taille-i),permu,comp);
    }
    affichage(tab);
    printf("Conversion: %lld, Permutation: %lld, n: %lld, n2: %lld\n",comp,permu,taille,(taille*taille));
    // affichage(tab);
}

int main(){
    srand((unsigned)time(NULL));
    printf("Nbr d'iterations \n");

    // tri avec un tableau:  a = aleatoire, c = croissant, d = decroissant
    char type = 'a';

    //https://openclassrooms.com/forum/sujet/calcul-temps-execution-84649
    int time1 = 0;
    printf("Tri par tas: \n");
    tri_tas(type);
    time1 = clock();
    printf("Temps d'execution = %d ms\n", time1);

    return 0;
}