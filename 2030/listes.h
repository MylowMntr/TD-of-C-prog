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
