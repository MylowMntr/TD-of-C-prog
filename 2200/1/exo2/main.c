#include <stdio.h>
#include <stdlib.h>

int main(void) {
    const char* filename = "data1.bin";

    FILE* output_file = fopen(filename, "wb");
    if (!output_file) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    for(int i = 1; i < 1000; i++)
    {
        fwrite(&i, sizeof(int), 1, output_file); 
    }
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