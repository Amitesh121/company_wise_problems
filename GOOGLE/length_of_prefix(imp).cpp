#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    
    int findPrefixLength(int a, int b) {
        string s1 = to_string(a);
        string s2 = to_string(b);
        int len = 0;
        
        for (int i = 0; i < min(s1.size(), s2.size()); i++) {
            if (s1[i] == s2[i]) {
                len++;
            } else {
                break;
            }
        }
        return len;
    }

public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int maxLen = 0;
        
        for (int i = 0; i < arr1.size(); i++) {
            for (int j = 0; j < arr2.size(); j++) {
                
                maxLen = max(maxLen, findPrefixLength(arr1[i], arr2[j]));
            }
        }
        
        return maxLen;
    }
};
