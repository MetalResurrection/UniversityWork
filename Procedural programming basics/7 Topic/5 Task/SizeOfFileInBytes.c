#include <stdio.h>

long getFileSize(char *fileName);

int main() {

    printf("Please enter the desired file you want to see the size of:\n");
    char fileName[100];
    scanf("%99s", fileName);

    printf("The file size is %ld", getFileSize(fileName));



return 0;
}

 long getFileSize(char *fileName) {
 FILE *file = fopen(fileName, "rb");

 if (file == NULL) {
    printf("Error opening file.\n");
    return -1;
 }

 if (fseek(file, 0, SEEK_END) != 0) {
    printf("Seek failed.\n");
    fclose(file);
    return -1;
 }

 long size = ftell(file);
 fclose(file);


 return size;


 }
