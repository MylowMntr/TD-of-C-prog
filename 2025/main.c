#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "pile.c"


//https://openclassrooms.com/fr/courses/19980-apprenez-a-programmer-en-c/16993-securisez-la-saisie-de-texte


int main(){
    Stack *Pile;
    NewStack(&Pile,20);
    char var;               // variable temporaire a metre dans nombre
    char nombre[20];        // tableau de char
    int i = 0;              // parcours de char nombre
    bool esp = false;       // test de l'espace pour debug remplacer en condition d'arret
    printf("Entrer une expression postfixee (finir par 'c'): ");
    while(esp == false){

        var = (char)_getch();
        printf("%c", var);
        if (var == 'c'){
            esp = true;
            printf("\n");
        }
        if (var == '+' || var == '-' || var == '*' || var == '/' ){
            push(Pile,var);
        }
        if (var == ' '){
            var = atoi(nombre);
            push(Pile, var);
            nombre[0] = '\0';
            i=0;
        }
        else{
            nombre[i] = var;
            i++;
        }
    }
    printf("%d  %d  %c  %d  %c\n", Pile->tab[0], Pile->tab[1], Pile->tab[2], Pile->tab[3], Pile->tab[4]);
    char *value;
    pull(Pile,&value);
    printf("\n%c\n", value);

        printf("%d  %d  %c  %d  %c\n", Pile->tab[0], Pile->tab[1], Pile->tab[2], Pile->tab[3], Pile->tab[4]);

        if (Pile->tab[i] == '+' || Pile->tab[i] == '-' || Pile->tab[i] =='*' || Pile->tab[i] == '/' ){            
            switch (Pile->tab[i]){
            case '+':
                Pile->tab[i-2] = (Pile->tab[i-2]) + (Pile->tab[i-1]);
                printf("%d",Pile->tab[i-2]);
                break;
            case '-':
                Pile->tab[i-2] = (Pile->tab[i-2]) - (Pile->tab[i-1]);
                printf("%d",Pile->tab[i-2]);
                break;
            case '*':
                Pile->tab[i-2] = (Pile->tab[i-2]) * (Pile->tab[i-1]);
                printf("%d",Pile->tab[i-2]);
                break;
            case '/':
                Pile->tab[i-2] = (Pile->tab[i-2]) / (Pile->tab[i-1]);
                printf("%d",Pile->tab[i-2]);
                break;
            default:
                break;
            }
        
    }
    return 0;
}