#include <stdio.h>
#include <string.h>

int contains(char *str, char c) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == c) {
            return 1;
        }
    }
    return 0;
}

void add(char *str, char sym) {
    int len = strlen(str);
    str[len] = sym;
    str[len + 1] = '\0';
}

void uni(char *str, char *set) {
    for (int i = 0; i < strlen(set); i++) {
        if (!contains(str, set[i])) {
            add(str, set[i]);
        }
    }
}

int ns, nt;
char res[100] = "";

typedef struct {
    int from;
    char symbol;
    int to;
} Transition;

Transition transition[100];
char symbols[100] = "";

void eclosure(int state, char *result) {
    if (!contains(result, state + '0')) {
        add(result, state + '0');
    }

    for (int i = 0; i < nt; i++) {
        if (transition[i].from == state && transition[i].symbol == 'e' &&
            !contains(result, transition[i].to + '0')) {
            eclosure(transition[i].to, result);
        }
    }
}

int main() {
    printf("Enter the number of states: ");
    scanf("%d", &ns);
    printf("Enter the number of transitions: ");
    scanf("%d", &nt);

    printf("Enter the transition table (from symbol to):\n");
    for (int i = 0; i < nt; i++) {
        scanf("%d %c %d", &transition[i].from, &transition[i].symbol, &transition[i].to);
    }

    for (int i = 0; i < nt; i++) {
        if (!contains(symbols, transition[i].symbol) && transition[i].symbol != 'e') {
            add(symbols, transition[i].symbol);
        }
    }

    printf("Transition Table:\n");
    for (int i = 0; i < strlen(symbols); i++) {
        printf("Symbol: %c\n", symbols[i]);
        for (int j = 0; j < ns; j++) {
            char closure[100] = "";
            eclosure(j, closure);

            char temp[100] = "";
            for (int k = 0; k < strlen(closure); k++) {
                int state = closure[k] - '0';
                for (int l = 0; l < nt; l++) {
                    if (transition[l].from == state && transition[l].symbol == symbols[i]) {
                        if (!contains(temp, transition[l].to + '0')) {
                            add(temp, transition[l].to + '0');
                        }
                    }
                }
            }

            char result[100] = "";
            for (int k = 0; k < strlen(temp); k++) {
                eclosure(temp[k] - '0', result);
            }

            for (int k = 0; k < strlen(result); k++) {
                printf("%d %c %d\n", j, symbols[i], result[k] - '0');
            }
        }
    }

    return 0;
}
