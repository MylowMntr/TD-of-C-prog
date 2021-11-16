#include <stdio.h>
#include <stdlib.h>

void main(){
    // a)
    float tab[100] = {0.0},val = 0;
    int nbr = 0;
    while (val >= 0.0){   
        printf("Entrez les notes : ");
        scanf("%f",&val);

        if (val >= 0.0) {
            tab[nbr] = val;
            nbr++;
        }
    }
    printf("Il y a %d valeur(s).\n",nbr);

    // b)
    // for (int k = 0; k < 100; k++)
    // {
    //     if (k % 11 == 0){
    //         printf("\n");
    //     }
    //     else{
    //         printf("%.02f\t",tab[k]);
    //     }
    // }


    // c)
    float addnbr;
    int addcase,suppnbr;
    printf("Quelle valeur voulez-vous ajouter ?\n");
    scanf("%f",&addnbr);
    printf("Ou voulez-vous ajouter votre valeur ?\n");
    scanf("%d",&addcase);
    nbr += 1;
    tab[addcase] = addnbr;
    // for (int k = 0; k < 100; k++)
    // {
    //     if (k % 11 == 0){
    //         printf("\n");
    //     }
    //     else{
    //         printf("%.02f\t",tab[k]);
    //     }
    // }

    // e)
    printf("Quelle case voulez-vous supprimer ?\n");
    scanf("%d",&suppnbr);
    nbr -= 1;
    tab[suppnbr] = 0.0;
    // for (int k = 0; k < 100; k++)
    // {
    //     if (k % 11 == 0){
    //         printf("\n");
    //     }
    //     else{
    //         printf("%.02f\t",tab[k]);
    //     }
    // }

    // g)
    float total = 0;
    for (int k = 0; k < 100; k++)
    {
        total = total + tab[k];
    }
    total = total / nbr;
    printf("%.02f",total);

}