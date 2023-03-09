/* TC : O(N+M)
   SC : O(M)
   Similar to Permutation in a string
*/


using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class StringAnagrams
{
public:
    static vector<int> findStringAnagrams(const string &str, const string &pattern)
    {
      vector<int> resultIndices;
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
            
            //Code logic changed here for string anagram 
            //rest all same as permutation in strings
            if(match == mpp.size()) {
                resultIndices.push_back(windowStart);
            }
            
            if(windowEnd >= pattern.size()-1) {
                char leftChar = str[windowStart++];
                //if found in hashMap and outside the window then
                if(mpp.find(leftChar)!=mpp.end()) {
                    if(mpp[leftChar]==0) {
                        match--;
                    }
                    mpp[leftChar]+=1 ;
                }
            }
        }
      return resultIndices;
    }
};

int main(int argc, char *argv[])
{
    auto result = StringAnagrams::findStringAnagrams("ppqp", "pq");
   // cout<<"e";
    for (auto num : result)
    {
        cout << num << " ";
    }
    cout <<endl;

    result = StringAnagrams::findStringAnagrams("abbcabc", "abc");
    for (auto num : result)
    {
        cout << num << " ";
    }
    cout << endl;
}
