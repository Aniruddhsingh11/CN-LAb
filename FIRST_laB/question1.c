#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <number1> <number2>\n", argv[0]);
        return 1;
    }
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);
    printf("Before swapping:\n");
    printf("Number 1: %d\n", num1);
    printf("Number 2: %d\n", num2);
    swap(&num1, &num2);
    printf("\nAfter swapping:\n");
    printf("Number 1: %d\n", num1);
    printf("Number 2: %d\n", num2);
    return 0;
}