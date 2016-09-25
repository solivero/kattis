#include <stdbool.h>
#include <stdio.h>
#include <math.h>

#define CATALOG_SIZE 1000000
int catalog[CATALOG_SIZE];
int entries_count = 0;

bool exists_in_catalog(int target) {
    int left = 0;
    int right = entries_count - 1;
    while (left <= right) { 
        int middle = floor((left + right) / 2);
        int element = catalog[middle];
        if(element < target)
            left = middle + 1;
        else if(element > target)
            right = middle - 1;
        else
            return true;
    }
    return false;
}

int main() {
    int n, m; 
    while (scanf("%d %d", &n, &m)) {
        if (!n && !m)
            break;
        int sellable = 0;
        entries_count = n;
        for (int i = 0; i < n; i++)
            scanf("%d", &catalog[i]);
        for (int i = 0; i < m; i++) {
            int catalog_num;
            scanf("%d", &catalog_num);
            if (catalog_num <= catalog[entries_count-1] && exists_in_catalog(catalog_num))
                sellable++;
        }
        printf("%d\n", sellable);
    }
    return 0;
}


    
