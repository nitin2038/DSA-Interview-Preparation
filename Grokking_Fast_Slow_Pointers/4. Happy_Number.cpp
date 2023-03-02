/*
    TC : O(logn)
    SC : O(1)
*/

#include<bits/stdc++.h>
using namespace std;

int getSquareSum(int n) {
    int sum = 0;
    while (n > 0) {
        int rem = n % 10;
        sum += rem * rem;
        n /= 10;
    }
    return sum;
}

bool isHappyNumber(int n) {
    int slow = n;
    int fast = n;
    do {
        slow = getSquareSum(slow);
        fast = getSquareSum(getSquareSum(fast));
    } while (slow != fast);

    return slow == 1;
}

void solve() {
    if (isHappyNumber(23) == 1)
        cout << "true";
    else
        cout << "false";
}

int main() {
    solve();
}