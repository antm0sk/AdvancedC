#include <stdio.h>
#include <stdint.h>

int extractExp(float f) {
    uint32_t bits = *(uint32_t*)&f;
    return (bits >> 23) & 0xFF;
}

int main() {
    float input;
    scanf("%f", &input);
    printf("%d\n", extractExp(input));
    return 0;
}
