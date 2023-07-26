class Solution {
public:
    int trap(vector<int>& height) {
        //Forward and reverse iteration method
        int n = height.size();
        int left_max=height[0],right_max=height[n-1],temp=0,ans=0,final_index=0;
        for(int i=1;i<n;i++){
            if(height[i]>=left_max){
                ans+=temp;
                left_max=height[i];
                temp=0;
                final_index=i;
            }
            temp+=left_max-height[i];
        }
        if(final_index==n-1) return ans;
        //Dealing with extra case like 4 5 7 2 5(here water in 7 2 5 is missing above)
        temp=0;
        //Mistake: Till final index only
        for(int i=n-1;i>=final_index;i--){
            if(height[i]>=right_max){
                ans+=temp;
                right_max=height[i];
                temp=0;
            }
            temp+=right_max-height[i];
        }
        return ans;
    }
};
