#include <stdio.h>

int main() {
    unsigned int N;
    int K;

    scanf("%u %d", &N, &K);

    unsigned int mask = (1U << K) - 1;

    unsigned int max_value = 0;

    for (int i = 0; i <= 32 - K; i++) {
        unsigned int current = (N >> i) & mask;
        if (current > max_value) {
            max_value = current;
        }
    }

    // Выводим результат
    printf("%u\n", max_value);

    return 0;
}