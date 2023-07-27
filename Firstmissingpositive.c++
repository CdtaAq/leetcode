class Solution {
public:
    int firstMissingPositive(vector<int>& v) {
        sort(v.begin(),v.end());

        // Remove duplicate values from vector
        v.erase(unique(v.begin(), v.end()), v.end());
        int n = v.size();
        int k = 1;
        for(int i = 0;i < n;){
            if(v[i] <= 0) {
                i++;
            }
            else { 
                if(v[i] != k){
                    return k;
                }
                else {
                    i++;
                    k++;
                }
            }
        }

        return k ;
    }
};
