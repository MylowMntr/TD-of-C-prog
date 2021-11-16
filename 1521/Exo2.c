#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdbool.h>
#define NbChiffresMax 1000

int Facto(int **tab, int Nombre){
    int i=1;
    int fact=1;

    while(i<Nombre+1)
    {
        fact*=i;
        tab[i] = fact;
        i++;
    }
    //   printf("%d! = %d",Nombre,fact);
    return fact;
}

void main() {
    int nbr = 0;
    int nb = 0;
    int tab[NbChiffresMax] = {1};
    bool fin = false;
    int rep;
    
    // printf("%d  %d  %d\n", tab[0], tab[1], tab[2]);

    do{    
        printf("Nombre ?\n");
        scanf("%d",&nbr);
        nb = Facto(tab, nbr);
        printf("%d! = %d",nbr, nb);
        printf("\n");
    }
    while (fin != true);
    
}
