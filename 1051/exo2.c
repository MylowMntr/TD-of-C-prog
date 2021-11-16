#include <stdio.h>
#include <stdlib.h>

void main(){
    int tab[10][11] = {0};
    // printf("%d",tab[4][3]);
    //  rand() % 20 + 1

    for (int k = 0; k < 10; k++)
        for (int p = 0; p < 11; p++)
        {
            if (p % 11 == 0){
                printf("\n");
            }
            else{
                tab[k][p] = (rand() % 20 + 1);
                printf("%d\t",tab[k][p]);
            }
        }
    printf("\n");
    int tabS[10][10];
    for (int k = 0; k < 10; k++)
        for (int p = 0; p < 10; p++)
        {
            if (p % 11 == 0){
                printf("\n");
            }
            else{
                tabS[k][p] = tab[p][k];
                printf("%d\t",tabS[k][p]);
            }
        }   
}
