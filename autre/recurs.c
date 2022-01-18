#include <stdio.h>
#include <stdlib.h>

void recursCompteurDecrement(int compteur){
    if (compteur == 0){
        printf("%d",compteur);
        return;
    }
    else{
        printf("%d-", compteur);
        return recursCompteurDecrement(compteur -1);
    }
}

int recursStrLen(char *chaine){
    if (*chaine == '\0'){
        return 0;
    }
    return (1 + recursStrLen(++chaine));
}

int mult(int a, int b){
    if(b != 1){
        return (a + mult(a,b-1));
    }
    else {
        return a;
    }
}

int fibo(int a){
    if (a > 1){
        return (fibo(a-1)+fibo(a-2));
    }
    else{
        return a;
    }
}

void main(){
    // recursCompteurDecrement(7);
    // char *truc = "Coucou";
    //printf("%d",recursStrLen(truc));
    // printf("%d",mult(3,5));
    printf("%d",fibo(3));
}
