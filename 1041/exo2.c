#include <stdlib.h>
#include <stdio.h>

void main(){
    int valeur,n;
    int total = 0;

    printf("Entrez la valeur de n pour laquelle vous voulez calculer la somme des n premiers entiers non nuls :\n");
    scanf("%d",&n);

    for (valeur = 0; valeur <= n; valeur++)
    {
        total = total + valeur;
    }
    printf("\nLa somme des %d premiers entiers positifs est egale a %d",n,total);
}