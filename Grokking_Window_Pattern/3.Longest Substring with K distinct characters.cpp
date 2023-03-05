/*
    TC : O(N)
    SC : O(K+1)
*/

#include<bits/stdc++.h>
using namespace std;

class LongestSubstringKDistinct
{
public:
    static int findLength(const string &str, int k)
    {
        int windowStart = 0, maxLen = 0;
        unordered_map<char, int>mpp;
        for(int windowEnd=0; windowEnd<str.size(); windowEnd++) {
            mpp[str[windowEnd]]+=1;
            while(mpp.size()>k) {
                    mpp[str[windowStart]]-=1;
                    if(mpp[str[windowStart]] == 0) {
                        mpp.erase(str[windowStart]);
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
    cout << "Length of the longest substring: "
        << LongestSubstringKDistinct::findLength("araaci", 2) << endl;
    cout << "Length of the longest substring: "
        << LongestSubstringKDistinct::findLength("araaci", 1) << endl;
    cout << "Length of the longest substring: "
        << LongestSubstringKDistinct::findLength("cbbebi", 3) << endl;
}
