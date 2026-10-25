#include <stdio.h>


char *largestFile(int argc, char *argv[]);


int main(int argc, char *argv[])
{
    char *name = largestFile(argc, argv);

    if (name != NULL) {
        printf("Didziausias failas: %s\n", name);
    } else {
        printf("Nepavyko rasti failo.\n");
    }

    return 0;
}
char *largestFile(int argc, char *argv[]) {

if (argc <= 1) {
    return NULL;
}

char *largestName = NULL;
long largestSize = -1;

for (int i = 1; i < argc; i++) {
        FILE *file = fopen(argv[i], "rb");

        if (file == NULL) {
        continue;
}

if (fseek(file, 0, SEEK_END) != 0) {
    fclose(file);
    continue;
}

    long size = ftell(file);
    fclose(file);


if (size >= 0 && size > largestSize) {
    largestSize = size;
    largestName = argv[i];
}

}

return largestName;
}

