/*
    TC : O(N)
    SC : O(1)
*/

#include<bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int>&arr) {
    int notDuplicate = 1;
    for(int i=0;i<arr.size();i++) {
        if(arr[notDuplicate - 1] != arr[i]) {
            arr[notDuplicate] = arr[i];
            notDuplicate+=1;
        }
    }

    return notDuplicate;
}

int main() {
    vector<int>arr = {2, 3, 3, 3, 6, 9, 9};
    cout<<removeDuplicates(arr);
    return 0;
}