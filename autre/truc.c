#include <stdio.h>
#include <stdlib.h>


int mot(char oui[], int i){
    if (oui[i] == '\0') {
        printf("%d", i);
        return(-1);
    }
    else {
        mot(oui, i + 1);
    }
}

int main() {
    char oui[] = {'o','u','i','\0'} ;
    mot(oui, 0);
}