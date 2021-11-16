#include <stdio.h>
#include <stdlib.h>
     
int occur(char mot[], int tailleMax,  char car){
    int nbr = 0;
    for(int i=0;i<sizeof (mot) ;i++) { 
        if (mot[i] == car) {
            nbr++ ;
        }
    }
    return nbr;
}

void main(){
    printf("%d", occur("toto", 5, 'o'));
}