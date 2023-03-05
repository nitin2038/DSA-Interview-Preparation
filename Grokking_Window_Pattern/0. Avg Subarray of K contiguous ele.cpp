/*

    TC : O(N)
    SC : O(1)
*/

#include<bits/stdc++.h>
using namespace std;

vector<double>avgSubarrayEle(vector<int>arr, int k) {
    vector<double>res(arr.size()-k+1);
    int windowStart = 0;
    double windowSum = 0;
    for(int windowEnd = 0; windowEnd<arr.size(); windowEnd++) {
        windowSum+=arr[windowEnd];
        if(windowEnd >=k-1) {
            res[windowStart] = windowSum/k;
            windowSum-=arr[windowStart];
            windowStart+=1;
        }
    }
    return res;
}

int main () {
    vector<double>res = avgSubarrayEle(vector<int>{1, 3, 2, 6, -1, 4, 1, 8, 2}, 5);
    for(double d: res) {
        cout<<d << " ";
        
    }
    cout<<endl;
}
