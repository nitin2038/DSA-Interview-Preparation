
/*
    TC : O(N^2)  // two for loops
    SC : O(N)   //for res arr
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>threeSum(vector<int>&arr) {
    vector<vector<int>>res;
    sort(arr.begin(), arr.end()); //O(nlogn)


    //O(N)*O(N) => O(N^2)
    for (int i = 0; i < arr.size() - 2; i++) {
        //to avoid duplicates
        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        int targetSum = 0 - arr[i];
        int left = i + 1, right = arr.size() - 1;
        while (left < right) {
            int currSum = arr[left] + arr[right];
            if (currSum == targetSum) {
                res.push_back({arr[i], arr[left], arr[right]});
                left += 1;
                right -= 1;

                while (left < right && arr[left] == arr[left - 1])
                    left++;

                while (left < right && arr[right] == arr[right + 1])
                    right--;
            }
            else if (currSum < targetSum)
                left += 1;
            else
                right -= 1;
        }
    }

    return res;
}

void solve()
{
    vector<int>arr{ -3, 0, 1, 2, -1, 1, -2};
    vector<vector<int>>resArr = threeSum(arr);
    cout << resArr.size() << " :: resultant Arr size" << endl;
    for (auto currArr : resArr) {
        cout << "[";
        for (auto i : currArr) {
            cout << i << " ";
        }
        cout << "]";
        cout << endl;
    }
    cout << endl;
}

int main() {
    solve();
    return 0;
}