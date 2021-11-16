#include <stdlib.h>
#include <stdio.h>

//il faut utiliser 2.5 et non 2,5 pour le taux

void main(){
    int capital,annee = 0;
    float somme,taux;

    printf("Montant de la somme :\n");
    scanf("%d",&capital);
    printf("Taux d'interet :\n");
    scanf("%f",&taux);
    printf("Capital : %d  Taux : %.02f\n",capital,taux);
    
    somme = capital;
    while (somme < (capital*2))
    {
        somme = somme + (somme*taux / 100);
        annee++;
        printf("an %d : %.02f euros\n",annee,somme);
    }
    printf("Votre capital aura double apres %d ans",annee);
    
}