#include <stdio.h>
#include <string.h>

int main() {

    char *canDo = NULL;
    char *shouldDo = NULL;
    size_t bytes = 0;

    getline(&canDo, &bytes, stdin);
    getline(&shouldDo, &bytes, stdin);

    if (strlen(canDo) >= strlen(shouldDo)) {
        printf("go\n");
    } else {
        printf("no\n");
    }
    return 0;

}


