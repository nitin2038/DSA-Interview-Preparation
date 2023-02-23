/*
    TC : O(N)
    SC :O(1)
*/

#include<bits/stdc++.h>
using namespace std;

int minWindowSort(vector<int>&arr) {
    int leftIdx = -1, rightIdx = -1;
    int maxSoFar = INT_MIN, minSoFar = INT_MAX;

    for (int i = 0; i < arr.size(); i++) {
        if (maxSoFar < arr[i])
            maxSoFar = arr[i];

        //find idx of element smaller than maxSoFar
        if (arr[i] < maxSoFar)
            rightIdx = i;
    }

    for (int i = arr.size(); i >= 0; i--) {
        if (minSoFar > arr[i])
            minSoFar = arr[i];

        //findIdx of element greater than minSoFar
        if (arr[i] > minSoFar)
            leftIdx = i;
    }

    if (leftIdx == -1) return -1;
    return rightIdx - leftIdx + 1;
}

void solve() {
    vector<int>arr = {1, 3, 2, 0, -1, 7, 10};
    int cntOfSubarray = minWindowSort(arr);
    cout << cntOfSubarray << " :Cnt";
}

int main() {
    solve();
    return 0;
}