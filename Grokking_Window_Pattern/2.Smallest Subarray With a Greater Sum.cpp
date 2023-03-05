/*
    TC : O(N +N)
    SC : O(1)
*/
using namespace std;

#include<bits/stdc++.h>

class Solution {
  public:
    static int findMinSubArray(int S, const vector<int>& arr) {
      int minLenSubArray = INT_MAX, windowStart= 0, currSum = 0;
      for(int windowEnd =0; windowEnd<arr.size(); windowEnd++) {
          currSum+=arr[windowEnd];
          while(currSum >=S) {
              minLenSubArray = min(minLenSubArray, (windowEnd-windowStart+1));
              currSum-=arr[windowStart];
              windowStart+=1;
          }
      }
      return minLenSubArray == INT_MAX ? -1 : minLenSubArray;
    }
  };

int main(int argc, char *argv[])
{
    int result = Solution::findMinSubArray(7, vector<int>{2, 1, 5, 2, 3, 2});
    cout << "Smallest subarray length: " << result << endl;
    result = Solution::findMinSubArray(7, vector<int>{2, 1, 5, 2, 8});
    cout << "Smallest subarray length: " << result << endl;
    result = Solution::findMinSubArray(8, vector<int>{3, 4, 1, 1, 6});
    cout << "Smallest subarray length: " << result << endl;
}
