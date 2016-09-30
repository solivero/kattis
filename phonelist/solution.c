#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 10

struct node {
    bool end;
    struct node *children[SIZE];
};

void print_node(struct node *the_node) {
    printf("End %d\n", the_node->end);
    for (int ix = 0; ix < SIZE; ix++) {
        if (the_node->children[ix] == NULL)
            printf("NULL ");
        else
            printf("%d ", ix);
    }
    printf("\n");
}


bool insert_word (struct node *root, char *word) {
    struct node *current_node = root;
    int len = strlen(word);
    int c = 0;
    struct node *next_ptr;
    // Go through word char by char
    for (int i = 0; i < len; i++) {
        // Convert ascii digit to int, or -1 for end/error
        c = word[i] - '0';
        next_ptr = current_node->children[c];
        // Allocate and init new node if not exists
        if (next_ptr == NULL) {
            next_ptr = malloc(sizeof(struct node));
            next_ptr->end = false;
            for (int j = 0; j < SIZE; j++) {
                next_ptr->children[j] = NULL;
            }
            current_node->children[c] = next_ptr;
        } else {
            if (next_ptr->end)
                return false;
            else if (i + 1 == len) {
                return false;
            }
        }
        current_node = next_ptr;
    }
    next_ptr->end = true;
    return true;
}

bool is_consistent() {
    bool consistent = true;
    struct node root = {.end = false, .children = {NULL}}; 
    long n_numbers = 0;
    scanf("%ld", &n_numbers);
    for (long j = 0; j < n_numbers; j++) {
        char number[SIZE+1];
        scanf("%s", number);
        if (consistent && !insert_word(&root, number))
            consistent = false;
    }
    return consistent;
}

int main() {
    int n_cases = 0;
    scanf("%d", &n_cases);
    for (int i = 0; i < n_cases; i++) {
        if (is_consistent())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

