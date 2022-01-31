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

// https://isen.junia.ovh/cir1/slides.html?presentation=algo/tris/tri_par_tas#11
int insert(int tab[], int pos){
    int currentNode;
    int father;
    currentNode = pos;
    father = (currentNode-1)/2;
    while ((currentNode > 0) && (tab[currentNode] > tab[father])){
        swap(tab[currentNode], tab[father]);
        currentNode = father;
        father = (currentNode -1)/2;
    }
}

int remove(int tab[], int pos){
    int currentChild, leftChild, rightChild, maxChild;
    bool stop;
    currentChild = 0;
    stop = false;
    swap (tab[0],tab[pos]);
    leftChild = 2*currentChild + 1;
    rightChild = 2*currentChild + 2;
    while ((!stop) && ((leftChild) <= (pos - 1)))
    {
        if ((leftChild = pos - 1) || (tab[leftChild] > tab[rightChild])){
            maxChild = leftChild;
        }
        else{
            maxChild = rightChild;
        }
        if (tab[currentChild < tab[maxChild]])
        {
            swap(tab[currentChild], tab[maxChild]);
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
    for (int i = 0; i < (taille - 1); i++)
    {
        insert(tab,i);
    }
    for (int i = 0; i < (taille - 1); i++)
    {
        remove(tab,(taille-1-i));
    }
}

int main(){
    srand((unsigned)time(NULL));
    printf("Nbr d'iterations \n");

    // tri avec un tableau:  a = aleatoire, c = croissant, d = decroissant
    char type = "a";


    //https://openclassrooms.com/forum/sujet/calcul-temps-execution-84649
    int time1 = 0;
    printf("Naif: \n");
    tri_tas(type);
    time1 = clock();
    printf("Temps d'execution = %d ms\n", time1);
    
    return 0;
}