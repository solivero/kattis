#include <stdio.h>

int main() {
    long char_type[4] = {0};
    long total = 0;

    char c;

    while ((c = getchar()) >= 33 && c <= 126) {
        //putchar(c);
        if (c == 95) {
            // whitespace
            char_type[0] += 1;
        } else if (c <= 122 && c >= 97) {
            // lowercase
            char_type[1] += 1;
        } else if (c <= 90 && c >= 65) {
            // uppercase
            char_type[2] += 1;
        } else {
            // symbol
            char_type[3] += 1;
        }

        total++;
    }

    for (int i = 0; i < 4; i++) {
        printf("%1.10f\n", (double)char_type[i]/total);
    }

    return 0;
}
