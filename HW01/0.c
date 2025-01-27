#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);  // Считываем количество чисел

    int max_value = -2147483648; // Инициализируем максимум минимальным значением int
    int max_count = 0;          // Счетчик максимального числа

    for (int i = 0; i < n; i++) {
        int current;
        scanf("%d", &current);  // Считываем текущее число

        if (current > max_value) {
            max_value = current; // Обновляем максимум
            max_count = 1;       // Сбрасываем счетчик
        } else if (current == max_value) {
            max_count++;         // Увеличиваем счетчик
        }
    }

    printf("%d\n", max_count);  // Выводим количество максимумов
    return 0;
}