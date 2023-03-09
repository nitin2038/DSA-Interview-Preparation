/* TC : O(N+M)
   SC : O(M)
   where, M, N are size of pattern and str
Approach : 1) all char in pattern to be in str,
           2) windowSize to be same as pattern size 
*/


using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class StringPermutation
{
public:
    static bool findPermutation(const string &str, const string &pattern)
    {
        //hashMap to store count of freq of pattern
        unordered_map<char, int>mpp;
        int windowStart = 0, match = 0;
        for(auto ch : pattern) {
            mpp[ch]++;
        }
        
        for(int windowEnd = 0; windowEnd<str.size(); windowEnd++) {
            char currChar = str[windowEnd];
            if(mpp.find(currChar)!=mpp.end()) {
                mpp[currChar]-=1;
                if(mpp[currChar]==0)
                    match+=1;
            }
            
            if(match == mpp.size()) {
                return true;
            }
            
            if(windowEnd >= pattern.size()-1) {
                char leftChar = str[windowStart++];
                //if found in hashMap and outside the window then
                if(mpp.find(leftChar)!=mpp.end()) {
                    if(mpp[leftChar]==0) {
                        match--;
                    }
                    mpp[leftChar]+=1;
                }
            }
        }
        
        return false;
    }
};

int main(int argc, char *argv[])
{
    cout << "Permutation exist: " << StringPermutation::findPermutation("oidbcaf", "abc")
        << endl;
    cout << "Permutation exist: " << StringPermutation::findPermutation("odicf", "dc")
        << endl;
    cout << "Permutation exist: "
        << StringPermutation::findPermutation("bcdxabcdy", "bcdyabcdx") << endl;
    cout << "Permutation exist: "
        << StringPermutation::findPermutation("aaacb", "abc") << endl;
}
