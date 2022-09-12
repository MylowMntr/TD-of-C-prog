#include <stdio.h>
#include <stdlib.h>
#include "arb.c"

int main(){
    BinaryTree *tree;
    newTree(&tree);

    BinaryTreeElement * racine;
    newBinaryTreeElement(&racine);
    BinaryTreeElement * oui;
    newBinaryTreeElement(&oui);
    BinaryTreeElement * non;    
    newBinaryTreeElement(&non);
    BinaryTreeElement * stiti;
    newBinaryTreeElement(&stiti);
    BinaryTreeElement * bril;    
    newBinaryTreeElement(&bril);
    BinaryTreeElement * fi;
    newBinaryTreeElement(&fi);
    BinaryTreeElement * menclature;    
    newBinaryTreeElement(&menclature);


    tree->anchor = racine;
    Cursor curs;
    curs = getCursorOnRoot(*tree);

    racine->rightChild = oui;
    racine->leftChild = non;
    oui->leftChild = stiti;
    oui->rightChild = fi;
    non->leftChild = bril;
    non->rightChild = menclature;
    racine->data = 5;
    oui->data = 2;
    non->data = 4;
    fi->data = 6;
    stiti->data = 8;
    bril->data = 1;
    menclature->data = 3;

    affichage(racine,0,3);

}