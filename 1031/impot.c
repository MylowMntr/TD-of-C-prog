#include <stdlib.h>
#include <stdio.h>

//marche pas vraiment, il faudrait faire des soustractions par opération effectué

long a(rev){
    // printf("%ld\n",rev);
    return 0;
}

long b(rev){
    rev = rev - 10065;
    rev = ( rev * 11 ) / 100;
    // printf("%ld\n",rev);
    if (rev <= 0)
        return 0;
    else
        return rev;
}

long c(rev){
    rev = rev - 25660;
    rev = ( rev * 30 ) / 100;
    // printf("%ld\n",rev);
    if (rev <= 0)
        return 0;
    else
        return rev;
}

long d(rev){
    rev = rev - 73370;
    rev = ( rev * 41 ) / 100;
    // printf("%ld\n",rev);
    if (rev <= 0)
        return 0;
    else
        return rev;
}

long e(rev){
    rev = rev - 157807;
    rev = ( rev * 45 ) / 100;
    // printf("%ld\n",rev);
    if (rev <= 0)
        return 0;
    else
        return rev;
}

void main(){
    long rev;

    printf("Revenu net global : ");
    scanf("%ld",&rev);
    
    printf("%ld + %ld + %ld + %ld + %ld",e(rev) , d(rev) , c(rev) , b(rev) , a(rev));
    rev = e(rev) + d(rev) + c(rev) + b(rev) + a(rev);
    printf("\nValeur des impots : %ld euro(s)", rev);

}