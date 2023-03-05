/*
    TC : O(N)
    SC : O(K+1)
*/
using namespace std;

#include <iostream>
#include <unordered_map>
#include <vector>

class MaxFruitCountOf2Types
{
public:
    static int findLength(const vector<char> &arr)
    {
        int windowStart = 0, maxLen = 0;
        int k = 2; //for 2 baskets

        unordered_map<char, int>mpp;
        for(int windowEnd=0; windowEnd<arr.size(); windowEnd++) {
            mpp[arr[windowEnd]]+=1;
            while(mpp.size()>k) {
                    mpp[arr[windowStart]]-=1;
                    if(mpp[arr[windowStart]] == 0) {
                        mpp.erase(arr[windowStart]);
                    }
                    windowStart+=1;
            }
            maxLen = max(maxLen, windowEnd-windowStart+1);
        }
        return maxLen;
    }
};

int main(int argc, char *argv[])
{
    cout << "Maximum number of fruits: "
        << MaxFruitCountOf2Types::findLength(vector<char>{'A', 'B', 'C', 'A', 'C'})
        << endl;
    cout << "Maximum number of fruits: "
        << MaxFruitCountOf2Types::findLength(vector<char>{'A', 'B', 'C', 'B', 'B', 'C'})
        << endl;
}
