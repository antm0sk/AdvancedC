#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPR 100005
#define STACK_SIZE 10000

int main(void) {
    char expr[MAX_EXPR];
    if (!fgets(expr, sizeof(expr), stdin))
        return 0;
    
    // Удаляем символ перевода строки, если он есть
    size_t len = strlen(expr);
    if (len > 0 && expr[len - 1] == '\n')
        expr[len - 1] = '\0';
    
    int stack[STACK_SIZE];
    int top = -1;
    
    // Разбиваем строку на токены по пробелу
    char *token = strtok(expr, " ");
    while (token != NULL) {
        int tlen = strlen(token);
        // Если последний символ токена – точка, удаляем её
        if (tlen > 0 && token[tlen - 1] == '.') {
            token[tlen - 1] = '\0';
            // Если после удаления точка токен оказался пустым – завершаем разбор
            if (strlen(token) == 0)
                break;
        }
        
        // Если токен начинается с цифры, то это число
        if (isdigit(token[0])) {
            int num = atoi(token);
            stack[++top] = num;
        } else {
            // Иначе токен – оператор. Извлекаем два верхних числа.
            int b = stack[top--];
            int a = stack[top--];
            int res = 0;
            switch (token[0]) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '/': res = a / b; break;
                case '*': 
                case '×': res = a * b; break;
                default: break;
            }
            stack[++top] = res;
        }
        token = strtok(NULL, " ");
    }
    if (top >= 0)
        printf("%d", stack[top]);
    return 0;
}
