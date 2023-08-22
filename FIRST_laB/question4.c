#include <stdio.h>

struct pkt {
    char ch1;
    char ch2[2];
    char ch3;
};

int main() {
    struct pkt packet;
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    packet.ch1 = (char)(number >> 16); 
    packet.ch2[0] = (char)(number >> 8); 
    packet.ch2[1] = (char)number; 
    packet.ch3 = (char)(number >> 24); 
    printf("Content of each member of the structure:\n");
    printf("ch1: %c\n", packet.ch1);
    printf("ch2: %c%c\n", packet.ch2[0], packet.ch2[1]);
    printf("ch3: %c\n", packet.ch3);
    int original_number = (packet.ch3 << 24) | ((unsigned char)packet.ch1 << 16) | ((unsigned char)packet.ch2[0] << 8) | (unsigned char)packet.ch2[1];
    printf("\nOriginal number: %d\n", original_number);
    return 0;
}