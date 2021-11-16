#include <stdlib.h>
#include <stdio.h>


// 0x20 = 32 et 0x7E = 126
// on cherche a afficher les valeurs entre ces deux la

void main(){
    int ligne = 0, colonne = 0, num, i;

    printf("    0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F");
    for (ligne = 0; ligne <= 7; ligne++)
    {   
        printf("\n%d   ",ligne);
        for (colonne = 0; colonne <= 15; colonne++)
        {
            num = ((ligne*16)+colonne);
            // printf("%d et %d ",colonne,ligne);
            if (num >= 32 && num <= 126)
            {
                printf("%c  ",num);
            }
            
        }
        
        
    }
    
}