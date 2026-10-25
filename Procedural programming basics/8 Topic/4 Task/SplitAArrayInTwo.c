#include <stdio.h>
#include <stdlib.h>

int splitData(const int *data, int size, int firstSize, int **firstArray, int **secondArray);

int main() {


    int data[] = {3, 5, 2, 3, 8, 7, 9, 11, 8, 1};
    int *firstArray = NULL;
    int *secondArray = NULL;

    int result = splitData(data, 10, 5, &firstArray, &secondArray);

 if (result == 0)
    {
        printf("First array: ");
        for (int i = 0; i < 5; i++)
            printf("%d ", firstArray[i]);

        printf("\nSecond array: ");
        for (int i = 0; i < 5; i++)
            printf("%d ", secondArray[i]);

        printf("\n");
    }

    else
    {
        printf("Error splitting array.\n");
    }

    free(firstArray);
    free(secondArray);

    return 0;
}

int splitData(const int *data, int size, int firstSize, int **firstArray, int **secondArray) {

if (data == NULL || size <= 0 || firstSize < 0 || firstSize > size || firstArray == NULL || secondArray == NULL || *firstArray != NULL || *secondArray != NULL)
{
    return -1;
}

int secondSize = size - firstSize;

int *first = NULL;
int *second = NULL;

if (firstSize > 0) {
    first = malloc(firstSize * sizeof(int));
    if (first == NULL) {
        return -1;
    }
}

if (secondSize > 0) {
    second = malloc(secondSize * sizeof(int));
    if (second == NULL) {
            free(first);
        return -1;
    }
}

for (int i= 0; i < firstSize; i++) {
    first[i] = data[i];
}

for (int i = 0; i < secondSize; i++)
{
    second[i] = data[firstSize + i];
}

*firstArray = first;
*secondArray = second;

return 0;
}
