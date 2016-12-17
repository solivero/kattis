// Read clues 
// GT: set if less than prev
// LT: set if greater than prev
// DB: add to list
// If LT-1 <= GT output none
// If DB not empty
// Sort DB
// For element, check divisble with all previous, changing current element to answer if divisible.
// From GT+1 to LT (excl), output num if divisible by DB product
//
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    const int MAX_INT = 50000;
    int n = 0;
    while (scanf("%d\n", &n)) {
        if (n == 0)
            return 0;
        int gt = 0;
        int lt = MAX_INT + 1;
        vector<int> divisors;
        char firstWord[10];
        char secondWord[10];
        int x;
        for (int i = 0; i < n; i++) {
            scanf("%s %s %d\n", firstWord, secondWord, &x);
            //cout << firstWord << " " << x << endl;
            if (firstWord[0] == 'l' && x < lt)
                lt = x;
            else if (firstWord[0] == 'g' && x > gt)
                gt = x;
            else if (firstWord[0] == 'd')
                divisors.push_back(x);
        }
        // Impossible bounds
        if (lt-1 <= gt)
            cout << "none" << endl;
        // No upper bound
        else if (lt > MAX_INT)
            cout << "infinite" << endl;
        else {
            sort(divisors.begin(), divisors.end());
            for (vector<int>::size_type i = 0; i < divisors.size(); i++) {
                for (int j = 0; j < i; j++) {
                    int reduced = divisors[i];
                    if (divisors[i] % divisors[j] == 0) {
                        reduced = divisors[i] / divisors[j];
                    }
                    divisors[i] = reduced;
                }
            }
            int product = 1;
            for (const auto prime : divisors)
                product *= prime;
            bool found = false;
            for (int i = gt+1; i < lt; i++) {
                if (i % product == 0) {
                    if (found)
                        cout << ' ';
                    found = true;
                    cout << i;
                }
            }
            if (!found)
                cout << "none";
            cout << endl;
        }
    }
    return 0;
}

