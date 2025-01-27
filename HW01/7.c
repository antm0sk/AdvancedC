#include <stdio.h>

int main() {
    int N;
    unsigned int num, result = 0;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%u", &num);
        result ^= num;
    }

    printf("%u\n", result);

    return 0;
}
