#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

#define INFINITE "infinite"
#define NONE "none"
#define MAX_INT 50000

using namespace std;

inline int findLCM(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (vector<int>::size_type i = 0; i < nums.size(); i++) {
        for (int j = 0; j < i; j++) {
            int reduced = nums[i];
            if (reduced % nums[j] == 0) {
                reduced = reduced / nums[j];
            }
            nums[i] = reduced;
        }
    }
    int lcm = 1;
    for (const int prime : nums)
        lcm *= prime;
    return lcm;
}

inline bool printMultiplesInRange(int from, int to, int factor) {
    bool found = false;
    for (int num = from; num < to; num++) {
        if (num % factor == 0) {
            if (found)
                cout << ' ';
            found = true;
            cout << num;
        }
    }
    return found;
}

int main() {
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
            const bool isLessClue = firstWord[0] == 'l';
            const bool isGreaterClue = firstWord[0] == 'g';
            const bool isDivideClue = firstWord[0] == 'd';
            if (isLessClue && x < lt)
                lt = x;
            else if (isGreaterClue && x > gt)
                gt = x;
            else if (isDivideClue)
                divisors.push_back(x);
        }
        // Impossible bounds
        if (lt-1 <= gt)
            cout << NONE << endl;
        // No upper bound
        else if (lt > MAX_INT)
            cout << INFINITE << endl;
        else {
            int lcm = findLCM(divisors);
            if (!printMultiplesInRange(gt + 1, lt, lcm))
                cout << NONE;
            cout << endl;
        }
    }
    return 0;
}

