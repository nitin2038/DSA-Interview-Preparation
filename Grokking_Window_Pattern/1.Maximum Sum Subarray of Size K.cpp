/*
    TC : O(N)
    SC : O(1)
*/
using namespace std;

#include <iostream>
#include <vector>

class Solution {
  public:
    static int findMaxSumSubArray(int k, const vector<int>& arr) {
      int maxSum = 0;
      int currSum = 0;
      int windowStart = 0;
      for(int windowEnd = 0; windowEnd<arr.size(); windowEnd++) {
          currSum+=arr[windowEnd];
          if(windowEnd>=k-1) {
              maxSum = max(maxSum, currSum);
              currSum-=arr[windowStart];
              windowStart+=1;
          }
      }
      
      return maxSum;
    }
  };
  
  int main(int argc, char *argv[])
  {
      cout << "Maximum sum of a subarray of size K: "
          << Solution::findMaxSumSubArray(3, vector<int>{2, 1, 5, 1, 3, 2})
          << endl;
      cout << "Maximum sum of a subarray of size K: "
          << Solution::findMaxSumSubArray(2, vector<int>{2, 3, 4, 1, 5})
          << endl;
  }