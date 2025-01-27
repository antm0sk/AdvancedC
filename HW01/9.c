#include <stdint.h>
#include <stdio.h>

struct pack_array {
    uint32_t array;    // поле для хранения упакованного массива из 0 и 1
    uint32_t count0 : 8; // счётчик нулей в array
    uint32_t count1 : 8; // счётчик единиц в array
};

void array2struct(int input[], struct pack_array *result) {
    result->array = 0;
    result->count0 = 0;
    result->count1 = 0;

    for (int i = 0; i < 32; i++) {
        if (input[i] == 1) {
            result->array |= (1U << (31 - i));
            result->count1++;
        } else {
            result->count0++;
        }
    }
}

int main() {
    int input[32];
    struct pack_array result;

    for (int i = 0; i < 32; i++) {
        if (scanf("%d", &input[i]) != 1) {
            printf("Error: Invalid input.\n");
            return 1;
        }
    }

    array2struct(input, &result);

    printf("%u %u %u\n", result.array, result.count0, result.count1);

    return 0;
}
