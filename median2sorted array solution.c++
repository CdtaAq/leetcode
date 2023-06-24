// Optimized Approach: Using gap method:
    // Time Complexity: O((log base 2 power N)*(N))
   //  Space Complexity: O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        // Do some pre-calculation : O(N)
        int n1=nums1.size();
        int n2=nums2.size();
        int n=n1+n2;
        
        // Now Create Two Pointer
        int gap=ceil((n1+n2)/2.0);
        int i=0;
        int j=gap;
        
        // Edge Cases
        if(n1==0)
            return n2%2?nums2[n2/2]:(nums2[n2/2]+nums2[n2/2-1])/2.0;
        
        if(n2==0)
            return n1%2?nums1[n1/2]:(nums1[n1/2]+nums1[n1/2-1])/2.0;
        
        // Apply gap method: O((log base 2 power N)*N)
        
       while(gap)
       {   i=0;
           j=gap;
       // Move both pointer until they reach at last 
        while(j<n)
        {
            // If 'i' in 'nums1' and 'j' is also in 'nums1'
            if(i<n1&&j<n1&&nums1[i]>nums1[j])
            swap(nums1[i],nums1[j]);
        else
            // if 'i' in 'nums1' and 'j' is in 'nums2'
            if(i<n1&&j>=n1&&nums1[i]>nums2[j-n1])
                swap(nums1[i],nums2[j-n1]);
        else 
            // if 'i' in 'nums2' and 'j' is also in 'nums2'
            if(i>=n1&&j>=n1&&nums2[i-n1]>nums2[j-n1])
                 swap(nums2[i-n1],nums2[j-n1]);
            
        // Move both pointer ahead by only one step
        i++;
        j++;
        }
        
        // Edge Case, because of 'ceil()' gap never becomes zero
        if(gap==1)
            gap=0;
         
         gap=ceil(gap/2.0);
       }   
        
    //Return Result
      if(n%2)
          return n/2<n1?nums1[n/2]:nums2[n/2-n1];
     else
         if(n/2<n1)
             return (nums1[n/2]+nums1[n/2-1])/2.0;
        else
            if((n/2-1)<n1)
               return (nums1[n/2-1]+nums2[n/2-n1])/2.0;
       else 
           return (nums2[n/2-n1]+nums2[n/2-1-n1])/2.0;
       
    }
};

** Accepted **
