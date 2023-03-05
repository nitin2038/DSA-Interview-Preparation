/*
    TC : O(N)
    SC : O(26) ==> O(1) (for hashmap to store 26 chars)
*/


using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class CharacterReplacement
{
public:
    static int findLength(const string &str, int k)
    {
      int maxLength = 0, windowStart=0, maxRepeatingChar = 0;
      unordered_map<char, int>mpp;
      
      for(int windowEnd=0; windowEnd<str.size();windowEnd++) {
          mpp[str[windowEnd]]++;
          maxRepeatingChar = max(maxRepeatingChar, mpp[str[windowEnd]]);
          
          //shrink window if remaining char > k
          if((windowEnd-windowStart+1) - maxRepeatingChar > k) {
              mpp[str[windowStart]]-=1;
              windowStart+=1;
          }
          
          //len of the max substring after k relplacements
          maxLength = max(maxLength, windowEnd-windowStart+1);
      }
      return maxLength;
    }
};

int main(int argc, char *argv[])
{
    cout << CharacterReplacement::findLength("aabccbb", 2) << endl;
    cout << CharacterReplacement::findLength("abbcb", 1) << endl;
    cout << CharacterReplacement::findLength("abccde", 1) << endl;
}
