#include "pile.h"
#include <stdbool.h>
#include <string.h>
#define STACKOVERFLOW -1

// création d'une pile 
// stack : nom de la pile
// initialStackSize: taille de la pile en nombre de valeurs empilables
void NewStack(Stack**stack, int initialStackSize) {
    // allocation de la structure pile
    *stack= (Stack*) malloc(sizeof(Stack));
    if(*stack!= NULL) {
        // allocation du tableau de données
        (*stack)->tab = (int*)malloc(sizeof(int)*initialStackSize);
        if(((*stack)->tab) != NULL) {
            // initialisation des paramètres de la pile
            (*stack)->stackMaxSize = initialStackSize;(*stack)->stackNbElemts = 0;
        }
        else{
            // la pile n'a pas pu être créée, stack vaut NULLfree
            (*stack);*stack= NULL;
        }
    }
}

// teste si la piles est pleine
bool isStackFull(Stack* stack) {
    return((stack->stackNbElemts >= stack->stackMaxSize));
}

// teste si la pile est vide
bool isStackEmpty(Stack*stack) {
    return(stack->stackNbElemts == 0);
}

// pousse une valeur sur la pile
int push(Stack*stack, char value) {
    if(!isStackFull(stack)) {
        stack->tab[stack->stackNbElemts] = value;
        stack->stackNbElemts++;
        return(0);
    }
    else{
        return(STACKOVERFLOW);
    }
}

// récupère la valeur au sommet de la pile
int pull(Stack*stack, char *value) {
    if(!isStackEmpty(stack)) {
        stack->tab[stack->stackNbElemts -1] = 0;
        stack->stackNbElemts--;
        return(EXIT_SUCCESS);
    }
    return(EXIT_FAILURE);
}

int peek(Stack*stack, char *value) {
    if(!isStackEmpty(stack)) {
        value = stack->tab[stack->stackNbElemts-1];
        return(value);
    }
    return(EXIT_FAILURE);
}


// PARTIE 2: Palindrome
bool isPalindrome(char *word){
    Stack *Pile;
    NewStack(&Pile,20);
    int size = strlen(word);
    for (int i = 0; i < size; i++)
    {
        // printf("%c", &word[i]);
        push(Pile, word[i]);
    }
    if(isStackEmpty(Pile)){
        printf("Erreur dans l'ajout du mot a la pile.\n");
        return -1;
    }

    char *truc;
    char lettre;
    for (int i = 0; i < (size/2); i++)
    {
        lettre = peek(Pile,truc);
        // printf("--%c   --%c\n", lettre, Pile->tab[i]);
        if(lettre != Pile->tab[i]){
            printf("Ce n'est pas un palindrome.");
            return -1;
        }
        pull(Pile, truc);
    }
    printf("C'est un palindrome.");
    return 0;   

}

void main(){
    char *mot = "radar";
    isPalindrome(mot);
}