#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "listes.c" 

int main (void) {
        char *num;
        LinkedList *liste;
        if ((liste = (LinkedList *) malloc (sizeof (LinkedList))) == NULL)
                return -1;
        if ((num = (char *) malloc (50)) == NULL)
                return -1;
        InitRandLinkedList (liste);

        num = "2";        
        insertElemAtLinkedListStart(liste,num);
        DisplayList(liste);
        
        num = "6";
        AppendNewElemToSingleLinkedList(liste,liste->fin,num);
        DisplayList(liste);

        num = "12";
        AppendNewElemToSingleLinkedList(liste,liste->fin,num);
        DisplayList(liste);
        
        // printf("\n%c\n", GetElementAt(liste,1)->*(donnee));
        swapSingleLinkedListELements(liste, GetElementAt(liste,2), GetElementAt(liste,3));
        DisplayList(liste);


        LinkedList *liste2;
        if ((liste2 = (LinkedList *) malloc (sizeof (LinkedList))) == NULL)
                return -1;
        if ((num = (char *) malloc (50)) == NULL)
                return -1;
        InitRandLinkedList (liste2);
        LinkedList *liste3;
        if ((liste3 = (LinkedList *) malloc (sizeof (LinkedList))) == NULL)
                return -1;
        if ((num = (char *) malloc (50)) == NULL)
                return -1;
        InitRandLinkedList (liste3);
        num = "1";        
        insertElemAtLinkedListStart(liste2,num);
        num = "9";
        AppendNewElemToSingleLinkedList(liste2,liste2->fin,num);
        DisplayList(liste2);


        concatSingleLinkedLists(liste3,liste,liste2);
        DisplayList(liste3);
        return 0;
} 