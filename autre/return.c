#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

int afficher(txt){
    printf("%d\n",txt);
    return ("%d",txt);
}

int taille(int **nom){
    int i = 0;
    while (nom[i] != 0)
    {
        i++;
    }
    return i;
}

void main(){
    int nom[5] = {74, 79, 72, 78, 0};
    printf("%d", taille(nom));
    
}