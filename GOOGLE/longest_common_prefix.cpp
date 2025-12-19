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

// This sorting is a common step in algorithms designed to find the longest common prefix among strings in a list. By sorting, the strings with the greatest differences are placed at the beginning and the end of the array; the longest common prefix of all strings must be a prefix of both the first and the last string in the sorted list. 