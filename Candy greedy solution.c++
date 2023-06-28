class Solution {
public:
    int candy(vector<int>& ratings) 
    {
        int n=ratings.size();
        if(ratings.size()==1)
        {
            return 1;
        }
        vector<int> temp(ratings.size(),1);
        int ans=0;
        if(ratings[0]>ratings[1])
        {
            temp[0]=max(temp[0]+1,temp[1]+1);
        }
        for(int i=1;i<ratings.size()-1;i++)
        {
            if(ratings[i]>ratings[i+1]||ratings[i]>ratings[i-1])
            {
                if(ratings[i]>ratings[i+1]&&ratings[i]>ratings[i-1])
                {
                    temp[i]=max(temp[i]+1,max(temp[i+1]+1,temp[i-1]+1));
                }
                else if(ratings[i]>ratings[i-1])
                {
                    temp[i]=max(temp[i]+1,temp[i-1]+1);
                }
                else if(ratings[i]>ratings[i+1])
                {
                     temp[i]=max(temp[i]+1,temp[i+1]+1);
                }
            }
        }
        if(n>=2) 
        {
            if(ratings[n-1]>ratings[n-2])
            {
                temp[n-1]=max(temp[n-1]+1,temp[n-2]+1);
            }
        }
        for(int i=ratings.size()-1;i>=1;i--)
        {
            if(ratings[i]<ratings[i-1])
            {
                if(temp[i]>=temp[i-1])
                {
                    temp[i-1]=temp[i]+1;
                }
            }
        }
        for(int i=0;i<temp.size();i++)
        {
            ans+=temp[i];
        }
        return ans;
    }
};
