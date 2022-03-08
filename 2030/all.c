#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "listes.h" 


void InitRandLinkedList (LinkedList * liste) {
        liste->debut = NULL;
        liste->fin = NULL;
        liste->taille = 0; 
}

/* insertion dans une liste vide */
int ins_dans_liste_vide (LinkedList * liste, char *donnee){
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

/* insertion à la position demandée */
int ins_liste (LinkedList * liste, char *donnee, int pos){
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

/* suppression au début de la liste */
int supp_debut (LinkedList * liste){
        if (liste->taille == 0)
                return -1;
        SingleLinkedListElem *supp_element;
        supp_element = liste->debut;
        liste->debut = liste->debut->suivant;
        if (liste->taille == 1)
                liste->fin = NULL;
        free (supp_element->donnee);
        free (supp_element);
        liste->taille--;
        return 0;
}
/* supprimer un element après la position demandée */
int supp_dans_liste (LinkedList * liste, int pos){
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

/* detruire la liste */
void detruire (LinkedList * liste){
        while (liste->taille > 0)
                supp_debut (liste);
}

int menu (LinkedList *liste,int *k){
        int choix;
        printf("********** MENU **********");
        if (liste->taille == 0){
                printf ("1. Ajout du 1er element");
                printf ("2. Quitter");
        } else if(liste->taille == 1 || *k == 1){
                printf ("1. Ajout au debut de la liste");
                printf ("2. Ajout a la fin de la liste");
                printf ("4. Suppression au debut de la liste");
                printf ("6. Detruire la liste");
                printf ("7. Quitter");
        }else {
                printf ("1. Ajout au debut de la liste");
                printf ("2. Ajout a la fin de la liste");
                printf ("3. Ajout apres la position specifie");
                printf ("4. Suppression au debut de la liste");
                printf ("5. Suppression apres la position specifie");
                printf ("6. Detruire la liste");
                printf ("7. Quitter");
        }
        printf ("Faites votre choix : ");
        scanf ("%d", &choix);
        getchar();
        if (liste->taille == 0 && choix == 2)
                choix = 7;
        return choix;
}