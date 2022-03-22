#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "bila.h" 


DoubleLinkedList*newDoubleLinkedList(){
    DoubleLinkedList *list;
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}
DoubleLinkedListElem*NewDoubleLinkedListItem(int value){
    DoubleLinkedList *list;
    DoubleLinkedListElem *start;
    start->data = value;
    start->previous = NULL;
    
    list->size = 1;
    list->head = start;
    list->tail = start;
    return list;
}
/* affichage de la liste */
void DisplayDoubleList (DoubleLinkedList * liste){
        DoubleLinkedListElem *courant;
        courant = liste->head;
        printf ("%d elements:deb=%s,tail=%s\n", liste->size,liste->head->data, liste->tail->data);
        while (courant != NULL){
                printf ("%p - %s\n", courant, courant->data);
                courant = courant->next;
        }
}
/* affichage de la liste */
void RevDisplayDoubleList (DoubleLinkedList * liste){
        DoubleLinkedListElem *courant;
        courant = liste->tail;
        printf ("%d elements:deb=%s,tail=%s\n", liste->size,liste->tail->data, liste->head->data);
        while (courant != NULL){
                printf ("%p - %s\n", courant, courant->data);
                courant = courant->previous;
        }
}
int insertItemAtDoubleLinkedListTail(DoubleLinkedList*list, DoubleLinkedListElem*newItem){
    list->tail->next = newItem;
    return 0; 
}
int insertItemAtDoubleLinkedListHead(DoubleLinkedList*list, DoubleLinkedListElem*newItem){
    list->head->previous = newItem;
    list->head = newItem;
}




int getDoubleLinkedListSize(DoubleLinkedList*list){
    return list->size;
}
/*insertion à la tail de la liste */
int AppendNewElemToSingleLinkedList (DoubleLinkedList * liste, DoubleLinkedListElem * courant, char *data){
        DoubleLinkedListElem *nouveau_element;
        if ((nouveau_element = (DoubleLinkedListElem *) malloc (sizeof (DoubleLinkedListElem))) == NULL)
                return -1;
        if ((nouveau_element->data = (char *) malloc (50 * sizeof (char)))
                        == NULL)
                return -1;
        strcpy (nouveau_element->data, data);
        courant->next = nouveau_element;
        nouveau_element->next = NULL;
        liste->tail = nouveau_element;
        liste->size++;
        return 0;
}

/* supprimer un element après la position demandée */
int DeleteSingleLinkedListElement (DoubleLinkedList * liste, int pos){
        if (liste->size <= 1 || pos < 1 || pos >= liste->size)
                return -1;
        int i;
        DoubleLinkedListElem *courant;
        DoubleLinkedListElem *supp_element;
        courant = liste->head;
        for (i = 1; i < pos; ++i)
                courant = courant->next;
        supp_element = courant->next;
        courant->next = courant->next->next;
        if(courant->next == NULL)
                liste->tail = courant;
        free (supp_element->data);
        free (supp_element);
        liste->size--;
        return 0;
}
// recupere un maillon et le renvoi
DoubleLinkedListElem *GetElementAt(DoubleLinkedList *liste, int pos){
        int i;
        DoubleLinkedListElem *courant;
        courant = liste->head;
        for (i = 1; i < pos; ++i){
                courant = courant->next;
        }
        return courant;
}       

// permute deux maillons appartenant a la liste
int swapSingleLinkedListELements(DoubleLinkedList* liste, DoubleLinkedListElem* elementA, DoubleLinkedListElem* elementB){
        if ((elementA == NULL) || (elementB == NULL)){
                return -1;
        }
        DoubleLinkedListElem *tmp;
        tmp = elementA->data;
        elementA->data = elementB->data;
        elementB->data = tmp;

        return 0;
}

// concatene 2 listes (A et B) dans liste C
int concatSingleLinkedList(DoubleLinkedList* listeC, DoubleLinkedList *listeA, DoubleLinkedList *listeB){
        DoubleLinkedList *CopyListe1;
        DoubleLinkedList *CopyListe2;
        CopyListe1 = listeA;
        CopyListe2 = listeB;

        listeC->size = listeA->size + listeB->size;

        listeC->head = CopyListe1->head;
        listeC->tail = CopyListe1->tail;

        listeC->tail->next = CopyListe2->head;
        listeC->tail = CopyListe2->tail;
        return 0;
}

// concatene 2 listes (A et B) dans liste C
int concatSingleLinkedLists(DoubleLinkedList* listeC, DoubleLinkedList *listeA, DoubleLinkedList *listeB){
        DoubleLinkedListElem *courant;
        courant = listeA->head;
        insertElemAtLinkedListStart(listeC,courant->data);
        courant = courant->next;
        
        while (courant != NULL){
                AppendNewElemToSingleLinkedList(listeC,listeC->tail,courant->data);
                courant = courant->next;
        }
        courant = listeB->head;
        while (courant != NULL){
                AppendNewElemToSingleLinkedList(listeC,listeC->tail,courant->data);
                courant = courant->next;
        }
        
        return 0;
}
