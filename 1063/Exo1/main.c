#include <stdlib.h>
#include <stdio.h>


int recursCompteurDecrement(int compteur) {
    int a = 0;
    if (compteur > 0){
        return (a + recursCompteurDecrement(-1));
    }
    return a;
}

void main(){
    printf("%d",recursCompteurDecrement(3));
}