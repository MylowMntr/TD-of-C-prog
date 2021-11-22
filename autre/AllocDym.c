#include <stdlib.h>
#include <stdio.h>

typedef struct heure{
    int heure; 
    int minute;
    } Heure;

void incrementMinute(Heure*now) {
    now->heure= (now->minute + 1) / 60 + now->heure;
    now->minute = (now->minute + 1) % 60;
    }


char* cloneStr(char* source) {
    char* tmp = (char*)malloc(strlen(source) + 1);
    // tmp mémorise la position du début de la chaine clonée
    char* dest = tmp;
    if (dest != NULL) {    
        while (*source != '\0') {
            *(dest++) = *(source++); // on fait avancer dest et source jusqu'à la fin de chaine
        }
        *dest = '\0'; // remise en place du fin de chaine
    }    
    dest = tmp;        // replace dest en début de mot ou renvoie NULL si malloc a échoué
    return dest;
}


Heure* cloneLog(Heure* source, int nbLog) {
    Heure* tmp = (Heure*)malloc(nbLog + 1);
    // tmp mémorise la position du début de la chaine clonée
    Heure* dest = tmp;
    for (int i = 0; i < nbLog; i++)
    {
        dest[i].heure = source[i].heure;
        dest[i].minute = source[i].minute;
    }
    
    dest = tmp;        // replace dest en début de mot ou renvoie NULL si malloc a échoué
    return dest;
}

void afficheLog( Heure*Log, int nbLog){
    for (int i = 0; i < nbLog; i++)
    {
        printf("%d:%d\n", Log[i].heure, Log[i].minute);
    }
}

Heure* clonelog(Heure* Log, int nbLog){
    Heure * new = (Heure*)calloc(nbLog,sizeof(Heure));
    if (new != NULL){
        for (int i = 0; i < nbLog; i++)
        {
            new[i] = Log[i];
        }
        return new;
    }
}


void main(){
    // int list [6] = {'g', 'r', 'o', 'o', 't', '\0'};
    // printf("%d\n",list);
    // printf("%d\n",cloneStr(list));
    // printf("\n");

    Heure tab[20] = {{0,59},{1,0},{3,30}};
    int nbLog = 3;

    afficheLog(tab,nbLog);
    // printf("%d\n", &tab);
    // printf("%d\n", cloneLog(&tab,nbLog));
    // printf("%d", clonelog(&tab,nbLog));
    printf("\n");
    afficheLog(cloneLog(&tab,nbLog),nbLog);
    printf("\n");
    afficheLog(clonelog(&tab,nbLog),nbLog);
    printf("\n");
    // incrementMinute(tab+i);
    
    for (int i = 0; i < nbLog; i++)
    {
        incrementMinute(tab+i);
    }
    afficheLog(tab,nbLog);
}