#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Fonction len, pour retourner la longueur d'une chaine de caractère
int len(char a[50]){
    int len = 0;
    while (a[len] != '\0'){
            len++;   
    }
    return len;
    // int len = strlen(a);
    // return len;
}

// Fonction copy, pour copier une string dans une autre (return la string "dupliquer")
int copy(char *str1[50], char *str2[50]) {
    char *copy[50];
    *copy = str1;
    str2 = *copy;
    return str2;
}

// Fonction cat, pour concatener 2 strings entre-elles, et la return
int cat(char str1[50], char str2[50]) {
    
    // strcat(str1, str2);
    return (str1);
}

// Fonction ncat, pour concatener 2 strings entre-elles, avec les n premiers caractères de la 2eme listes, et la return
int ncat(char str1[50], char str2[50], int n) {
    strncat(str1[50], str2[50], n);
    return (str1);
}

// Fonction cmp, pour comparer 2 strings entre-elles, return 1 si different, 0 si pareil
int cmp(char str1[50], char str2[50]) {
    int result;
    result = strcmp(str1, str2);
    return (result);
}

// Fonction FAtoi, pour transformer une string en int et inversement, return int si string et inversement.
int FAtoi(char str[50]) {
    int valeur;
    valeur = atoi(str);
   return (valeur);
}

void main(){
    printf("%d\n",len("Coucou"));
    printf("%s\n",copy("Coucou","avions"));
    // printf("%d\n",cat("Coucou"," toi"));
    // printf("%d\n",ncat("Coucou"," toi",2));
    // printf("%d / ",cmp("Coucou","Coucou"));printf("%d\n",cmp("Coucou"," toi"));
    // printf("%d / ",FAtoi("Coucou"));printf("%d",FAtoi("1234"));
}