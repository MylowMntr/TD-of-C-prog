#include <stdlib.h>
#include <stdio.h>

void main(){    
    int annee;    
    for (annee = 3000; annee >= 2000; annee--)
    {      
        if ((annee%4 == 0) && !(annee%100 == 0)){        
            printf("%d\n",annee);    }    
        else if ((annee%4 == 0) && (annee%100 == 0) && (annee%400 == 0)){                    
            printf("%d\n",annee);    }    
    }
}