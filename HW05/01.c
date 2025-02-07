#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int main() {
    char N[MAX_LEN + 1];
    scanf("%s", N);
    
    int len = strlen(N);
    int unique[1000] = {0};  // массив для хранения уникальных чисел (0-999)

    // Обрабатываем случай, когда число меньше 3 цифр
    if (len < 3) {
        printf("0\n");
        return 0;
    }

    for (int i = 0; i < len - 2; i++) {
        for (int j = i + 1; j < len - 1; j++) {
            for (int k = j + 1; k < len; k++) {
                // Исключаем числа вида "007", "045", "000" и т.п.
                if (N[i] == '0') continue;  

                int num = (N[i] - '0') * 100 + (N[j] - '0') * 10 + (N[k] - '0');
                unique[num] = 1;  // помечаем число как встреченное
            }
        }
    }

    int count = 0;
    for (int i = 0; i < 1000; i++) {
        if (unique[i]) count++;
    }

    printf("%d\n", count);
    return 0;
}
