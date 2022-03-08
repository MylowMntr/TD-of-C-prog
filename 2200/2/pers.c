#include <stdio.h>
#include <stdlib.h>

typedef struct pers{
    int adrID; 
    // Identifiant unique d'une adresse (ex noordre de création)
    char nom[50];
    char prenom[50];
} PERSONNE;

int main(void) {
    const char* filename = "personnes.bin";
    FILE* output_file = fopen(filename, "wb");
    if (!output_file) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    PERSONNE pers1 = {1,"OUI","Stiti"};
    PERSONNE pers2 = {2,"NON","Bril"};
    PERSONNE pers3 = {3,"Ah","Bon"};
    PERSONNE pers4 = {4,"Bah","Bar"};
    fwrite(&pers1, sizeof(pers1), 1, output_file);
    fwrite(&pers2, sizeof(pers2), 1, output_file);
    fwrite(&pers3, sizeof(pers3), 1, output_file);
    fwrite(&pers4, sizeof(pers4), 1, output_file);

    fclose(output_file);   



    output_file = fopen(filename, "r");
    if (output_file == NULL)
    {
        printf("Error");
        return -1;
    }
    // read one character at a time and
    // display it to the output
    char ch;
    while ((ch = fgetc(output_file)) != EOF)
        putchar(ch);

    // close the file
    fclose(output_file);
    exit(EXIT_SUCCESS);
}