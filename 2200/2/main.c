#include <stdio.h>
#include <stdlib.h>

typedef struct adresse{
    int adrID; 
    // Identifiant unique d'une adresse (ex noordre de création)
    char adr1[50];
    char adr2[50];
    char CP[10]; 
    // code postal
    int codePays; 
    // choisir un code pays ex France= 33
} ADRESSE;

int main(void) {
    const char* filename = "addresse.bin";
    FILE* output_file = fopen(filename, "wb");
    if (!output_file) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    ADRESSE adresse1 = {1,"Rue du Oui","Maison Oui","12345",33};
    ADRESSE adresse2 = {2,"Rue du Non","Maison Non","54321",01};
    ADRESSE adresse3 = {3,"Rue du Ah","Maison Ah","98765",44};
    ADRESSE adresse4 = {4,"Rue du Bh","Maison Bh","56789",02};
    fwrite(&adresse1, sizeof(adresse1), 1, output_file);
    fwrite(&adresse2, sizeof(adresse2), 1, output_file);
    fwrite(&adresse3, sizeof(adresse3), 1, output_file);
    fwrite(&adresse4, sizeof(adresse4), 1, output_file);

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