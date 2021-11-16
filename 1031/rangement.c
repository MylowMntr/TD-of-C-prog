#include <stdlib.h>
#include <stdio.h>
void main(){  int a,b,c;  printf("Valeur de A :\n");  scanf("%d", &a);    printf("Valeur de B :\n");  scanf("%d", &b);    printf("Valeur de C :\n");  scanf("%d", &c);    if (a > b){a += b;  b = a-b;    a = a-b;}if (b > c){b += c;    c = b-c;    b = b-c; }if (a > b){a += b; b = a-b;    a = a-b;    }printf("\n%d<=%d<=%d",a,b,c);}
