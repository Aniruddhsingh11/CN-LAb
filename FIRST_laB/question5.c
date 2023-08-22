#include <stdio.h>
int isLittleEndian() {
    int num = 1;
    return (*(char*)&num == 1);
}

void printBytes(int number) {
    unsigned char *ptr = (unsigned char *)&number;
    printf("Bytes at each location:\n");
    for (int i = 0; i < sizeof(int); i++) {
        printf("Byte %d: %02X\n", i + 1, ptr[i]);
    }
}

int convertEndianness(int number) {
    unsigned char *ptr_src = (unsigned char *)&number;
    int converted = 0;
    unsigned char *ptr_dest = (unsigned char *)&converted;
    int num_bytes = sizeof(int);
    for (int i = 0; i < num_bytes; i++) {
        ptr_dest[num_bytes - 1 - i] = ptr_src[i];
    }
    return converted;
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    if (isLittleEndian()) {
        printf("Host machine is in Little Endian.\n");
    } else {
        printf("Host machine is in Big Endian.\n");
    }
    printBytes(number);
    int convertedNumber = convertEndianness(number);
    printf("\nConverted number: %d\n", convertedNumber);
    return 0;
}