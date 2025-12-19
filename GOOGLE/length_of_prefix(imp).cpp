#include <vector>
#include <string>
#include <algorithm>

using namespace std;
//naive approach TC: O(N*M)
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
//OPTIMISED APPROACH
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;

        for (int val : arr1) {
            while (val > 0) {
                prefixes.insert(val);
                val /= 10;
            }
        }

        int maxLen = 0;

        for (int val : arr2) {
            while (val > 0) {
                if (prefixes.count(val)) {

                    int currentLen = (int)log10(val) + 1;
                    maxLen = max(maxLen, currentLen);

                    break;
                }
                val /= 10;
            }
        }

        return maxLen;
    }
};

