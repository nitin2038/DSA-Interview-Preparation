/*
    TC : O(N^2)  // two for loops
    SC : O(N)   //for res arr
*/
#include <bits/stdc++.h>
using namespace std;

int tripletWithSmallerSum(vector<int>&arr, int target) {
    sort(arr.begin(), arr.end());
    int countOfTriplets = 0;
    for (int i = 0; i < arr.size() - 2; i++) {
        int left = i + 1, right = arr.size() - 1;
        target -= arr[i];
        while (left < right) {
            int currSum = arr[left] + arr[right];
            if (currSum < target) {
                countOfTriplets += right - left;
                for (int j = right; j > left; j--) {
                    cout << "[" << arr[j] << " " << arr[left] << " " << arr[i] << "]" << endl;
                }
                left++;
            }
            else
                right--;
        }
    }

    return countOfTriplets;
}

void solve()
{
    vector<int>arr{ -1, 4, 2, 1, 3};
    int target = 5;
    cout << tripletWithSmallerSum(arr, target) << " : tripletWithSmallerSum value" << endl;
}

int main() {
    solve();
    return 0;
}