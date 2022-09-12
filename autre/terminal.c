#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

int main(){
    int k = 60;
    while(k >= 0){
        printf("%d\n",k);
        k-=1;
        sleep(1);
    }
}