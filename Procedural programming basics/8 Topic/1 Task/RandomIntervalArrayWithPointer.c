#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *createArrayFunction(int arraySize, int lowPointOfGeneration, int highPointOfGeneration);


int main() {
    srand((unsigned int)time(NULL));


    //The configurable parts of the code !!!
    int arraySize = 5;
    int lowPointOfGeneration = 5;
    int highPointOfGeneration = 10;
    /////////////////////////////////////////


    int *array = createArrayFunction(arraySize, lowPointOfGeneration, highPointOfGeneration);

    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

     for (int i = 0; i < arraySize; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");


    free(array);

    return 0;

}



int *createArrayFunction(int arraySize, int lowPointOfGeneration, int highPointOfGeneration) {

    int *desiredArray = malloc(arraySize * sizeof(int));

    if(desiredArray == NULL) {
        return NULL;
    }


    for (int i = 0; i < arraySize; i++) {
            *(desiredArray + i) = rand() % (highPointOfGeneration - lowPointOfGeneration + 1) + lowPointOfGeneration;
    }

    return desiredArray;
}
