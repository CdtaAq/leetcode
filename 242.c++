#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    vector<int> freq(string& s){
        vector<int> ans(26, 0);
        for(char c: s){
            ans[c-'a']++;
        }
        return ans;
    }
    bool isAnagram(string s, string t) {
        return freq(s)==freq(t);
    }
};
