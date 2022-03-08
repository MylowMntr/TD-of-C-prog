#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "listes.c" 

int main (void) {
        char choix;
        char *num;
        LinkedList *liste;
        SingleLinkedListElem *courant;
        if ((liste = (LinkedList *) malloc (sizeof (LinkedList))) == NULL)
                return -1;
        if ((num = (char *) malloc (50)) == NULL)
                return -1;
        courant = NULL;
        choix = 'o';
        InitRandLinkedList (liste);
        int pos, k;
        DisplayList(liste);
        *num = 2;
        printf ("%d elements:deb=%s,fin=%s", liste->taille,liste->debut->donnee, liste->fin->donnee);
        
        AppendNewElemToSingleLinkedList(liste,liste->fin,num);
        *num = 6;
        printf ("%d elements:deb=%s,fin=%s", liste->taille,liste->debut->donnee, liste->fin->donnee);
        AppendNewElemToSingleLinkedList(liste,liste->fin,num);

        *num = 12;
        printf ("%d elements:deb=%s,fin=%s", liste->taille,liste->debut->donnee, liste->fin->donnee);
        AppendNewElemToSingleLinkedList(liste,liste->fin,num);

        DisplayList(liste);

        return 0;
} 