#include <stdlib.h>
#include <stdio.h>

void main(){
    int total =0, num, nbr=0;
    float flo;

    while (num != -1)
    {
        printf("Valeur entiere :\n");
        scanf("%d",&num);
        total = total + num;
        nbr++;
    }
    flo =(total/nbr);
    printf("Il y a %d valeurs avec pour moyenne %.02f.",nbr,flo);
}