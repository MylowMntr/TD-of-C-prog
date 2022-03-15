#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "listes.h" 


void InitRandLinkedList (LinkedList * liste) {
        liste->debut = NULL;
        liste->fin = NULL;
        liste->taille = 0; 
}

/* insertion au début ET initialisation de la liste */
int insertElemAtLinkedListStart (LinkedList * liste, char *donnee){
        SingleLinkedListElem *nouveau_element;
        if ((nouveau_element = (SingleLinkedListElem *) malloc (sizeof (SingleLinkedListElem))) == NULL)
                return -1;
        if ((nouveau_element->donnee = (char *) malloc (50 * sizeof (char)))
                        == NULL)
                return -1;
        strcpy (nouveau_element->donnee, donnee);
        nouveau_element->suivant = NULL;
        liste->debut = nouveau_element;
        liste->fin = nouveau_element;
        liste->taille++;
        return 0; 
} 

/* insertion au début de la liste */
int insertElemAtLinkedListHead (LinkedList * liste, char *donnee){
        SingleLinkedListElem *nouveau_element;
        if ((nouveau_element = (SingleLinkedListElem *) malloc (sizeof (SingleLinkedListElem))) == NULL)
                return -1;
        if ((nouveau_element->donnee = (char *) malloc (50 * sizeof (char)))
                        == NULL)
                return -1;
        strcpy (nouveau_element->donnee, donnee);
        nouveau_element->suivant = liste->debut;
        liste->debut = nouveau_element;
        liste->taille++;
        return 0;
}

int insertElemAtLinkedListPos (LinkedList * liste, char *donnee, int pos){
        if (liste->taille < 2)
                return -1;
        if (pos < 1 || pos >= liste->taille)
                return -1;
        SingleLinkedListElem *courant;
        SingleLinkedListElem *nouveau_element;
        int i;
        if ((nouveau_element = (SingleLinkedListElem *) malloc (sizeof (SingleLinkedListElem))) == NULL)
                return -1;
        if ((nouveau_element->donnee = (char *) malloc (50 * sizeof (char)))
                        == NULL)
                return -1;
        courant = liste->debut;
        for (i = 1; i < pos; ++i)
                courant = courant->suivant;
        if (courant->suivant == NULL)
                return -1;
        strcpy (nouveau_element->donnee, donnee);
        nouveau_element->suivant = courant->suivant;
        courant->suivant = nouveau_element;
        liste->taille++;
        return 0;
}

/*insertion à la fin de la liste */
int AppendNewElemToSingleLinkedList (LinkedList * liste, SingleLinkedListElem * courant, char *donnee){
        SingleLinkedListElem *nouveau_element;
        if ((nouveau_element = (SingleLinkedListElem *) malloc (sizeof (SingleLinkedListElem))) == NULL)
                return -1;
        if ((nouveau_element->donnee = (char *) malloc (50 * sizeof (char)))
                        == NULL)
                return -1;
        strcpy (nouveau_element->donnee, donnee);
        courant->suivant = nouveau_element;
        nouveau_element->suivant = NULL;
        liste->fin = nouveau_element;
        liste->taille++;
        return 0;
}

/* supprimer un element après la position demandée */
int DeleteSingleLinkedListElement (LinkedList * liste, int pos){
        if (liste->taille <= 1 || pos < 1 || pos >= liste->taille)
                return -1;
        int i;
        SingleLinkedListElem *courant;
        SingleLinkedListElem *supp_element;
        courant = liste->debut;
        for (i = 1; i < pos; ++i)
                courant = courant->suivant;
        supp_element = courant->suivant;
        courant->suivant = courant->suivant->suivant;
        if(courant->suivant == NULL)
                liste->fin = courant;
        free (supp_element->donnee);
        free (supp_element);
        liste->taille--;
        return 0;
}
// recupere un maillon et le renvoi
SingleLinkedListElem *GetElementAt(LinkedList *liste, int pos){
        int i;
        SingleLinkedListElem *courant;
        courant = liste->debut;
        for (i = 1; i < pos; ++i){
                courant = courant->suivant;
        }
        return courant;
}       

// permute deux maillons appartenant a la liste
int swapSingleLinkedListELements(LinkedList* liste, SingleLinkedListElem* elementA, SingleLinkedListElem* elementB){
        if ((elementA == NULL) || (elementB == NULL)){
                return -1;
        }
        SingleLinkedListElem *tmp;
        tmp = elementA->donnee;
        elementA->donnee = elementB->donnee;
        elementB->donnee = tmp;

        return 0;
}

// concatene 2 listes (A et B) dans liste C
int concatSingleLinkedList(LinkedList* listeC, LinkedList *listeA, LinkedList *listeB){
        LinkedList *CopyListe1;
        LinkedList *CopyListe2;
        CopyListe1 = listeA;
        CopyListe2 = listeB;

        listeC->taille = listeA->taille + listeB->taille;

        listeC->debut = CopyListe1->debut;
        listeC->fin = CopyListe1->fin;

        listeC->fin->suivant = CopyListe2->debut;
        listeC->fin = CopyListe2->fin;
        return 0;
}

// concatene 2 listes (A et B) dans liste C
int concatSingleLinkedLists(LinkedList* listeC, LinkedList *listeA, LinkedList *listeB){
        SingleLinkedListElem *courant;
        courant = listeA->debut;
        insertElemAtLinkedListStart(listeC,courant->donnee);
        courant = courant->suivant;
        
        while (courant != NULL){
                AppendNewElemToSingleLinkedList(listeC,listeC->fin,courant->donnee);
                courant = courant->suivant;
        }
        courant = listeB->debut;
        while (courant != NULL){
                AppendNewElemToSingleLinkedList(listeC,listeC->fin,courant->donnee);
                courant = courant->suivant;
        }
        
        return 0;
}


/* affichage de la liste */
void DisplayList (LinkedList * liste){
        SingleLinkedListElem *courant;
        courant = liste->debut;
        printf ("%d elements:deb=%s,fin=%s\n", liste->taille,liste->debut->donnee, liste->fin->donnee);
        while (courant != NULL){
                printf ("%p - %s\n", courant, courant->donnee);
                courant = courant->suivant;
        }
}