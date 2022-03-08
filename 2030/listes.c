#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "listes.h" 


void InitRandLinkedList (LinkedList * liste) {
        liste->debut = NULL;
        liste->fin = NULL;
        liste->taille = 0; 
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

/* affichage de la liste */
void DisplayList (LinkedList * liste){
        SingleLinkedListElem *courant;
        courant = liste->debut;
        while (courant != NULL){
                printf ("%p - %s", courant, courant->donnee);
                courant = courant->suivant;
        }
}