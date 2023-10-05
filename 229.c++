class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       vector<int> result;
        if (nums.empty()) {
            return result;
        }
        
        int p1 = 0, p2 = 0;
        int count1 = 0, count2 = 0;
        
        for (int num : nums) {
            if (num == p1) {
                count1++;
            } else if (num == p2) {
                count2++;
            } else if (count1 == 0) {
                p1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                p2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        
        count1 = 0;
        count2 = 0;
        for (int num : nums) {
            if (num == p1) {
                count1++;
            } else if (num == p2) {
                count2++;
            }
        }
        
        int n = nums.size();
        if (count1 * 3 > n) {
            result.push_back(p1);
        }
        if (count2 * 3 > n) {
            result.push_back(p2);
        }
        
        return result;
    }
};
