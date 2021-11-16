#include <stdlib.h>
#include <stdio.h>
#define TABSIZE 100

int remplirTab(float tab[], int tabSize, int nbVal, float min, float max){
    if ((min >= max) || (nbVal == 0)){
        return -1;
    }
    for (int i = 0; i < nbVal; i++)
    {
        tab[i] = min + (float)rand()/((float)RAND_MAX/(max - min)); 
        // printf("%.02f\n",tab[i]);
        
    }
    return nbVal;
}

int afficherTab(float tab[], int tabSize, int nbVal){
    for (int i = 0; i < nbVal; i++)
    {
        printf("%.02f ;",tab[i]);
    }
    printf("\n");
    return nbVal;
}

int maxTab(float tab[], int tabSize, int nbVal){
    int maxi;
    for (int i = 0; i < nbVal; i++)
    {
        if (tab[i] > maxi){
            maxi = i;
        }
    }
    return maxi;
}

void main(){
    float mini,maxi;
    int nbrval;
    float tab[TABSIZE] = {0.0};
    printf("Valeur minimum :\n");
    scanf("%f", &mini);
    printf("Valeur maximum :\n");
    scanf("%f", &maxi);
    printf("Nombre de valeur :\n");
    scanf("%d", &nbrval);

    printf("%d\n",remplirTab(tab,TABSIZE,nbrval,mini,maxi));
    printf("%d\n",afficherTab(tab,TABSIZE,nbrval));
    printf("%d\n",maxTab(tab,TABSIZE,nbrval));
}