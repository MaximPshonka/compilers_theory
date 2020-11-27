#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

#define TSTATE 4
#define TCHARTYPE 5
#define SYM_AMOUNT 22


bool isLetterOrDigit(char c, char* arr) {
    for (int i = 0; i < SYM_AMOUNT; i++) {
        if (c == *(arr + i))
            return true;
    }
    return false;
}

//c - текущий s - следующий

int ResultPriority(char c, char s, char* arr) {
    if ((c == '0') && (s == 'x')) {
        return 1;
    }
    else
        if (c == 'x') {
            return 2;
        }
        else
            if (c == '$') {
                return 3;
            }
            else
                if (isLetterOrDigit(c, arr)) {
                    return 4;
                }
                else {
                    return 0;
                }
}

int main() {
    char letterOrDigit[SYM_AMOUNT] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'a', 'b', 'c', 'd', 'e', 'f' };

    int IsFinalStates[TSTATE] = { 0, 0, 0, 1 };
    int TransitionsArray[TSTATE][TCHARTYPE] = {
            {0, 0 ,0, 0, 0},
            {0, 2, 0, 3, 0},
            {0, 0, 3, 0, 0},
            {0, 0, 0, 0, 3}
    };
    char str[16] = { 0 };
    gets(str);

    printf("vvedite stroky\n");
    gets(str);
    int state = 1;
    int a = 0;
    for (int i = 0; i < strlen(str) - 1; i++)
    {
        a = ResultPriority(str[i], str[i + 1], letterOrDigit);
        state = TransitionsArray[state][a];
    }
    if (IsFinalStates[state] == 0) {
        printf("not right string\n");
    }
    else
        printf("right string\n");


    return 0;
}
