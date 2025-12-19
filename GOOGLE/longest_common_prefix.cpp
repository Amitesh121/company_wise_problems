#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <numeric>
#include <algorithm>
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(),strs.end());
        string prefix;
        string first = strs[0];
        string last = strs[n-1];
        for(int i=0;i<first.size();i++){
            if(first[i]!=last[i]){
                return prefix;
            }
            prefix+=first[i];
        }
        return prefix;

    }
};