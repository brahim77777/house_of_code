#include <stdio.h>
#include <stdbool.h>

int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '[' && close == ']') return 1;
    if (open == '{' && close == '}') return 1;
    return 0;
}

bool isValid(const char *s) {
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }

    char stack[length];
    int top = -1;  

    for (int i = 0; i < length; i++) {
        char c = s[i];

        if (c == '(' || c == '[' || c == '{') {
            top++;
            stack[top] = c;
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (top == -1) {
                return 0;  
            }
            char openBracket = stack[top];
            top--;

            if (!isMatchingPair(openBracket, c)) {
                return 0; 
            }
        }
    }

    return (top == -1) ? 1 : 0;
}

int main(void) {
    const char *test1 = "()";
    const char *test2 = "[()]";
    const char *test3 = "{(a+b] * x}";
    const char *test4 = "[{a+b}*(x/y)]";

    printf("Test 1: %s\n", test1);
    printf("Is valid: %s\n\n", isValid(test1)?"true":"false");

    printf("Test 2: %s\n", test2);
    printf("Is valid: %s\n\n", isValid(test2)?"true":"false");

    printf("Test 3: %s\n", test3);
    printf("Is valid: %s\n\n", isValid(test3)?"true":"false");

    printf("Test 4: %s\n", test4);
    printf("Is valid: %s\n\n", isValid(test4)?"true":"false");

    return 0;
}

