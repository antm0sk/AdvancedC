#include <stdio.h>

int main() {
    unsigned int N;
    int count = 0;

    scanf("%u", &N);

    while (N > 0) {
        count += N & 1;
        N >>= 1;
    }

    printf("%d\n", count);

    return 0;
}