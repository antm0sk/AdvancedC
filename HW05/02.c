#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10005   // максимум для каждой строки

// Функция вычисления префикс-функции для строки s.
// Результат записывается в массив pi, который должен быть длины strlen(s).
void compute_prefix_function(const char *s, int *pi) {
    int n = strlen(s);
    pi[0] = 0;
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
}

int main(void) {
    char s1[MAX_SIZE], s2[MAX_SIZE];

    // Считывание двух строк (если не удалось – считаем строку пустой)
    if (fgets(s1, sizeof(s1), stdin) == NULL)
        s1[0] = '\0';
    if (fgets(s2, sizeof(s2), stdin) == NULL)
        s2[0] = '\0';

    // Удаляем символ перевода строки, если он присутствует
    size_t len1 = strlen(s1);
    if (len1 > 0 && s1[len1 - 1] == '\n') {
        s1[len1 - 1] = '\0';
        len1--;
    }
    size_t len2 = strlen(s2);
    if (len2 > 0 && s2[len2 - 1] == '\n') {
        s2[len2 - 1] = '\0';
        len2--;
    }

    int ans1 = 0, ans2 = 0;

    // 1. Наибольший префикс s1, являющийся суффиксом s2.
    // Строим строку X = s1 + '#' + s2.
    int X_len = len1 + 1 + len2;
    char *X = (char *)malloc((X_len + 1) * sizeof(char));
    if (!X) return 1;
    strcpy(X, s1);
    X[len1] = '#';
    strcpy(X + len1 + 1, s2);

    int *pi = (int *)malloc(X_len * sizeof(int));
    if (!pi) { free(X); return 1; }
    compute_prefix_function(X, pi);
    ans1 = pi[X_len - 1];

    free(X);
    free(pi);

    // 2. Наибольший суффикс s1, являющийся префиксом s2.
    // Строим строку Y = s2 + '#' + s1.
    int Y_len = len2 + 1 + len1;
    char *Y = (char *)malloc((Y_len + 1) * sizeof(char));
    if (!Y) return 1;
    strcpy(Y, s2);
    Y[len2] = '#';
    strcpy(Y + len2 + 1, s1);

    int *pi2 = (int *)malloc(Y_len * sizeof(int));
    if (!pi2) { free(Y); return 1; }
    compute_prefix_function(Y, pi2);
    ans2 = pi2[Y_len - 1];

    free(Y);
    free(pi2);

    printf("%d %d", ans1, ans2);
    return 0;
}
