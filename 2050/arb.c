#include "arb.h"
#include <stdio.h>
#include <stdlib.h>

Cursor getCursorOnRoot(BinaryTree tree){
    Cursor curs;
    curs.pointeur = tree.anchor;
    curs.side = Left;
    return curs;
}

BinaryTreeElement * getCurs(Cursor curs){
    return curs.pointeur;
}

int newBinaryTreeElement(BinaryTreeElement **node) {
    *node = (BinaryTreeElement *)malloc(sizeof(BinaryTreeElement));

    if (node != NULL) {
        (*node)->data = 0;
        (*node)->nodeID = 0;
        (*node)->leftChild = NULL;
        (*node)->rightChild = NULL;
        return EXIT_SUCCESS;
    }
    else { return EXIT_FAILURE; }
}

int newTree(BinaryTree ** tree){
    *tree = (BinaryTree *)malloc(sizeof(BinaryTree));

    if (tree != NULL){
        (*tree)->anchor = NULL;
        (*tree)->nodeCount = 0;
        return EXIT_SUCCESS;
    }
    else { return EXIT_FAILURE; }
    
}

void goDown(Cursor * curs, Direction dir){
    if (dir == Left){
        curs->pointeur = curs->pointeur->leftChild;
    }
    if (dir == Right){
        curs->pointeur = curs->pointeur->rightChild;
    }
}

bool isAtTheEnd(Cursor curs){
    Direction dir = curs.side;
    if(dir = Left){
        if (curs.pointeur->leftChild == NULL){
            return true;
        }
    }
    if(dir = Left){
        if (curs.pointeur->rightChild == NULL){
            return true;
        }
    }
    return false;
}

bool isALeaf(Cursor curs){
    if ((curs.pointeur->leftChild == NULL) || (curs.pointeur->rightChild == NULL)){
        return true;
    }
    return false;
}

bool hasAChild(Cursor curs, Direction D){
    if (curs.side = D){
        return true;
    }
    return false;
}

int getValue(Cursor curs){
    return curs.pointeur->data;
}

void modifyValue(Cursor curs, int x){
    curs.pointeur->data = x;
}

void insertValueInAbrAt(Cursor curs, int x){
    BinaryTreeElement *new;
    new->data = x;
    curs.pointeur = new;
}

void addValueToABR(BinaryTree tree, int x){
    tree.anchor->data = x;
}

void affichage(BinaryTreeElement *courant, int current_level, int max_level)
{
  int i;
  if (courant) {
    affichage(courant->rightChild, current_level + 1, max_level);
    for (i = 0; i < current_level; i++) {
      printf("    ");
    }
    printf("%d\n", courant->data);
    affichage(courant->leftChild, current_level + 1, max_level);
  } else {
    if (current_level < max_level) {
      affichage(NULL, current_level + 1, max_level);
      for (i = 0; i < current_level; i++) {
        printf("    ");
      }
      printf("..\n");
      affichage(NULL, current_level + 1, max_level);
    }
  }
}

void aff(BinaryTreeElement *courant){
    if (courant != NULL){
        aff(courant->leftChild);
        printf("%d", courant->data);
        aff(courant->rightChild);
    }
}