#include<stdio.h>

struct {
    unsigned int a: 1;
    unsigned char b: 7;
} bit;

int main() {
    bit.a = 1;
    bit.b = 'A';
    printf("%u %c", bit.a, bit.b);
    return 0;
}
