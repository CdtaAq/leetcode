class Solution {
public:
  
    int help(vector<int> &nums, int target,vector<int>& dp){
        int n=nums.size();
		// Base case: If target is zero, we find the combination
        if(target==0) return 1; 
        int ans=0; 
		
        if(dp[target]!=-1) return dp[target];   // To avoid redundant calculations.
		
        for(int i=0; i<n; i++){
            if(nums[i]<=target){ // Check if the current element can contribute to the target sum.
                ans+=help(nums, target-nums[i],dp); // Recursively explore subproblem with reduced target.
            }
        }
        dp[target]= ans; // Store the result in dp.
        return dp[target]; // Return the total no of valid combination.
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1); //create Dp

        return help(nums, target,dp);
    }
};
