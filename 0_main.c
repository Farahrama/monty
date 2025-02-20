#include "monty.h"
int main(int argc, char *argv[]) {
FILE *file;
if (argc != 2) {
fprintf(stderr, "USAGE: %s file\n", argv[0]);
exit(EXIT_FAILURE);
}
file = fopen(argv[1], "r");
if (!file) {
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}
execute_monty(file);
fclose(file);
return 0;
}

