#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char str[1001];
    int freq[10] = {0};

    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) {
            freq[str[i] - '0']++;
        }
    }

    for (int i = 0; i < 10; i++) {
        printf("%d ", freq[i]);
    }

    return 0;
}
