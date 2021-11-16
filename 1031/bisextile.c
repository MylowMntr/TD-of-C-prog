#include <stdlib.h>
#include <stdio.h>
void main(){    int annee;    printf("Quelle annee?\n");    scanf("%d",&annee);    if ((annee%4 == 0) && !(annee%100 == 0)){        printf("Bissextile");    }    else if ((annee%4 == 0) && (annee%100 == 0) && (annee%400 == 0)){                    printf("Bissextile");    }    else{        printf("Pas bissextile");    }}