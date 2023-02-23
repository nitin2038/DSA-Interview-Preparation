/*
    TC : O(M+N)
    SC : O(1)
*/
#include <bits/stdc++.h>
using namespace std;

int getValidCharIdx(string s, int idx) {
    int backspaceCount = 0;
    while(idx>=0) {
        if(s[idx]=='#')
            backspaceCount+=1;
        else if(backspaceCount > 0)
            backspaceCount-=1;
        else
            break;
            
        idx--;
    }
    
    return idx;
}

bool compareStrings(string s1, string s2) {
    int idx1 = s1.size()-1;
    int idx2 = s2.size()-1;
   
   while(idx1>=0 || idx2>=0) { 
            int i1 = getValidCharIdx(s1, idx1);
            int i2 = getValidCharIdx(s2, idx2);
            
            if(i1 < 0 && i2 < 0)
                return true;
                
            if(i1 < 0 || i2< 0)
                return false;
            
            if(s1[i1]!=s2[i2])
                return false;
            
            idx1 = i1-1;
            idx2 = i2-1;
    }
    
    return true;
}

void solve()
{   
    string s1 = "xy#z";
    string s2 = "xzz#";
    cout<<compareStrings(s1, s2);
}

int main() {
    solve();
    return 0;
}

