/*
    TC : O(N)
    SC : O(1)
    Other Approach : Using hashmap : TC : O(N) , SC : O(N)
*/
#include<bits/stdc++.h>
using namespace std;

pair<int, int> pairWithTargetSum(vector<int>&arr, int target) {
    int left = 0, right = arr.size()-1;
    while(left < right) {
        int curr_sum = arr[left]+arr[right];
        if(curr_sum == target) {
            return make_pair(arr[left], arr[right]);
        }
        else if(curr_sum > target) {
            right--;
        }
        else {
            left++;
        }
    }
    return make_pair(-1, -1);
}

int main() {
    vector<int>arr{1, 2, 3, 4, 6};
    int target = 6;
    auto result = pairWithTargetSum(arr, target);
    cout<<result.first<<" "<<result.second<<endl;
}