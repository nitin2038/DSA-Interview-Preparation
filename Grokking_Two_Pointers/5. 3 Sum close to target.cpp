/*
    TC : O(N^2)  // two for loops
    SC : O(N)   //for res arr
*/

#include <bits/stdc++.h>
using namespace std;

int searchTriplet(vector<int>&arr, int target) {
    sort(arr.begin(), arr.end());
    int closestSum = INT_MAX;

    for (int i = 0; i < arr.size() - 2; i++) {
        int left = i + 1, right = arr.size() - 1;
        while (left < right) {
            int sum = arr[i] + arr[left] + arr[right];

            //2nd if condn for saving the closest difference
            if (abs(target - sum) < abs(target - closestSum) || (abs(target - sum) == abs(target - closestSum) && (target - sum) > (target - closestSum))) {
                closestSum = sum;
            }

            if (sum > target)
                right--;
            else
                left++;
        }
    }

    return closestSum;
}

void solve()
{
    vector<int>arr{0, 0, 1, 1, 2, 6};
    int target = 5;
    cout << searchTriplet(arr, target) << " : ClosestSum value" << endl;
}

int main() {
    solve();
    return 0;
}
