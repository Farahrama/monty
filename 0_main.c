#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

int main(int argc, char *argv[])
{
    char *filename;
    FILE *file;

    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    filename = argv[1];
    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        return EXIT_FAILURE;
    }

    execute_monty(file);
    fclose(file);
    return 0;
}

