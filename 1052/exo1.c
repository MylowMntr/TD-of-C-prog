#include <stdlib.h>
#include <stdio.h>

int somme(int n){
    return((n*(n+1))/2);
}

void main(){
    int nbr;
    printf("Quel n ?\n");
    scanf("%d",&nbr);
    if (nbr > 0){
        int x = somme(nbr);
        printf("Somme des %d premiers entiers : %d",nbr,x);
    }
    else{
        printf("-1");
    }
}