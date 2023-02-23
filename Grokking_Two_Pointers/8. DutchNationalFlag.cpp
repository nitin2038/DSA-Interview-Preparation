/*
    TC : O(N)
    SC : O(1)
*/
#include <bits/stdc++.h>
using namespace std;

void print(vector<int>&arr) {
    for (auto i : arr) {
        cout << i << " ";
    }
    cout << endl;
}


void dutchNational(vector<int>&arr) {
    int lo = 0, mid = 0, hi = arr.size() - 1;
    while (mid <= hi) {
        switch (arr[mid]) {
        case 0 : swap(arr[lo++], arr[mid++]);
            break;
        case 1: mid++;
            break;
        case 2: swap(arr[mid], arr[hi--]);
            break;
        }
    }

    print(arr);

}

void solve()
{
    vector<int>arr{1, 0, 2, 1, 0};
    dutchNational(arr);
}

int main() {
    solve();
    return 0;
}

