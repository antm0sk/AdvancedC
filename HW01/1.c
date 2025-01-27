#include <stdio.h>

int main() {
    int shift;
    scanf("%d ", &shift);

    char c;
    while ((c = getchar()) != '.') {
        if (c >= 'a' && c <= 'z') {
            putchar('a' + (c - 'a' + shift) % 26);
        } else if (c >= 'A' && c <= 'Z') {
            putchar('A' + (c - 'A' + shift) % 26);
        } else {
            putchar(c);
        }
    }
    putchar('.');
    return 0;
}
