class Solution {
public:
   void helper(std::vector<int>& nums, int l, int h) {
        while (l < h) {
            std::swap(nums[l], nums[h]);
            l++;
            h--;
        }
    }

    int minimumRightShifts(std::vector<int>& nums) {
        int ind = -1;
        std::vector<int> temp = nums;
        std::sort(temp.begin(), temp.end()); 
        helper(nums, 0, nums.size() - 1);    
       
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                ind = i - 1;
                break;
            }
        }

        // 
        helper(nums, 0, ind);             
        helper(nums, ind + 1, nums.size() - 1); 
        if (temp != nums) {
            return -1; 
        }
        return ind + 1; 
    }
};
