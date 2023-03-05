/*
    TC : O(N)
    SC : O(1)
    //similiar to Longest Substring with same letter after replacement
*/

using namespace std;

#include <iostream>
#include <vector>

class ReplacingOnes
{
public:
    static int findLength(const vector<int> &arr, int k)
    {
      int maxLength = 0, windowStart = 0 , maxCount1= 0;
      for(int windowEnd=0;windowEnd<arr.size();windowEnd++) {
          if(arr[windowEnd]==1)
            maxCount1+=1;
        
        //if window has 0's more than k, then shrink window
        if((windowEnd-windowStart+1)-maxCount1 > k) {
            windowStart+=1;
            if(arr[windowStart]==1) {
                maxCount1-=1;
            } 
        }
        
        maxLength = max(maxLength, windowEnd-windowStart+1);            
      }
      return maxLength;
    }
};

int main(int argc, char *argv[])
{
    cout << ReplacingOnes::findLength(vector<int>{0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1}, 2)
        << endl;
    cout << ReplacingOnes::findLength(vector<int>{0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1}, 3)
        << endl;
}
