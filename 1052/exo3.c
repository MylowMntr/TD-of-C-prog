#include <stdlib.h>
#include <stdio.h>
#define TAILLEMAX 254

int compterCar(char chaine[], int tailleMax){
    int nbrmot = 0;
    for(int i=0; chaine[i]!=NULL; i++){
        if(chaine[i]==' ')
            nbrmot++;
    }
    return (nbrmot+1);
}
    
void main(){
    char chaine[TAILLEMAX];
    printf("Entrez une chaine de caractere : ");
    gets(chaine);
    printf("Il y a %d mots.",compterCar(chaine, TAILLEMAX));
}