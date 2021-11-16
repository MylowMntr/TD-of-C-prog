#include <stdio.h>
#include <stdlib.h>

void swap(int *A, int*B){
    int temp = A;
    A = B;
    B = temp;
    
    printf("\nX = %d > Y = %d", A, B);
}
void ordonne(int *A, int*B){
    if (B > A){
        swap(A,B);
    }
    else{
        printf("\nX = %d > Y = %d", A, B);}
}

void main(){
    int x, y;
    printf("Valeur de X : ");
    scanf("%d", &x);
    printf("Valeur de Y : ");
    scanf("%d", &y);
    if ((x > 0) && (y > 0)){
        ordonne(x,y);
    }
    if ((x == NULL) || (y == NULL)){
        printf("-1");
    }
}
