#include <stdlib.h>
#include <stdio.h>

void main(){
    int AB,BC,CA;
    printf("Valeur de AB : ");
    scanf("%d",AB);
    printf("Valeur de BC : ");
    scanf("%d",BC);
    printf("Valeur de CA : ");
    scanf("%d",CA);

    if ((AB <= BC + CA) && (BC <= AB + CA) && (CA <= AB + CA))
        printf("C'est un triangle");
    else
        printf("Pas un triangle");
}