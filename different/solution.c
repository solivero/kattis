#include <stdio.h>
#include <stdlib.h>

int main() {
    long long first, sec;
    while (scanf("%lli%lli", &first, &sec) != EOF) {
        printf("%lli\n", llabs(first-sec));
    }
}


