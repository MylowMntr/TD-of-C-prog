typedef struct SingleLinkedListElem
{
    char *donnee;
    struct SingleLinkedListElem *suivant;
} SingleLinkedListElem;

typedef struct LinkedList
{
    SingleLinkedListElem *debut;
    SingleLinkedListElem *fin;
    int taille;
} LinkedList;


typedef struct SLLStack{
    LinkedList *list;
    int stackMaxSize;  // doit-on garder cette propriété ?
    int stackNbElemts; // nb elements actuellement stockés
} SLLStack;