#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "file.h"

void NewQueue(Queue **queue, int initialQueueSize) {
    *queue= (Queue*)malloc(sizeof(Queue));
    if(*queue!= NULL) {
        (*queue)->tab = (int*)malloc(sizeof(int)*initialQueueSize);
        if(((*queue)->tab) != NULL) {
            for(int i = 0; i < initialQueueSize; i++)
                (*queue)->tab[i] = 0;
                (*queue)->first = -1;
                (*queue)->last = -1;
                (*queue)->queueNbElemt = 0;
                (*queue)->queueMaxSize = initialQueueSize;
        }
        else{
            free(*queue);
            *queue= NULL;
        }
    }
}

bool isQueueEmpty(Queue*queue) {
    return(queue->queueNbElemt == 0);
}

bool isQueueFull(Queue*queue) {
    return(queue->queueNbElemt == queue->queueMaxSize);
}

// Ajout d'un élément dans la file
int add(Queue*queue, int value) {
    // gestion de la file en tableau circulaire
    // si la file est pleine, on ne fait rien
    if(isQueueFull(queue)) 
        return(EXIT_FAILURE);
    // si la file est vide
    // écriture du premier élément dans la file
    if(isQueueEmpty(queue)) {
        queue->first = 0;
        queue->last = 0;
        queue->queueNbElemt = 1;
        queue->tab[queue->last] = value;
    } 
    else{
        // écriture d'unélément dans la file        
        queue->last ++;
        queue->tab[queue->last % queue->queueMaxSize] = value;
        queue->queueNbElemt +=1;
        // calculer la position du prochain élément et le stocker
    }
    return(EXIT_SUCCESS);
}

// Sortie d'un élément de la file
int deQueue(Queue*queue, int*value) {        
    // gestion de la file en tableau circulaire
    // si la file est vide
    // on ne fait rien car pas d'element: ERREUR
    if(isQueueEmpty(queue)) {
        return(EXIT_FAILURE);
    }
    else{
        // écriture dans value de l'element sortant
        value = queue->tab[queue->first % queue->queueNbElemt];
        queue->tab[queue->first % queue->queueNbElemt] = 0;
        queue->queueNbElemt --;
        queue->first ++;
    }
    return(EXIT_SUCCESS);
}

int display(Queue *queue){
    if(isQueueEmpty(queue)) {
        return(EXIT_FAILURE);
    }
    else{
        printf("\nOrdre du tableau:\n");
        for (int i = 0; i < queue->queueNbElemt; i++)
        {
            printf(" %d |", queue->tab[queue->first + i]);
        }
        printf("\nOrdre dans la file:\n");
        for (int i = 0; i < queue->queueMaxSize; i++)
        {
            printf(" %d |", queue->tab[i]);
        }
    }
    printf("\n");
}

void remplir(Queue *queue, int nbr){
    for (int i = 0; i < nbr; i++)
    {
        add(queue,i);
    }
}

void main(){
    Queue *File;
    NewQueue(&File,20);
    int* value;

    remplir(File, 15);
    display(File);

    add(File,12);
    display(File);

    deQueue(File,value);
    display(File);
}