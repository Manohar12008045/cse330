class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        map<int,int> mp;
        for(int i=0;i<n;i++)
            mp[nums[i]]++;
        int l=0;
        int r=(n/2);
        int gap=0;
        while(l<r)
        {
            int dif=nums[r]-nums[l];
            if(dif%2!=0)
            {
                r--;
                continue;
            }
            map<int,int> temp=mp;
            for(auto it=temp.begin();it!=temp.end();it++)
            {
                if(temp[it->first]==0)
                    continue;
                int ele1=it->first;
                int ele2=it->first+dif;
                if(temp.find(ele2)==temp.end())
                    break;
                if(temp[ele1]>temp[ele2])
                    break;
                else
                {
                    temp[ele2]-=temp[ele1];
                    temp[ele1]=0;
                }
                
            }
            bool is=true;
            for(auto it=temp.begin();it!=temp.end();it++)
            {
                if(temp[it->first]>0)
                {
                    is=false;
                    break;
                }
                    
            }
            if(is && dif%2==0)
            {
                gap=dif;
                break;
            }
            r--;
        }
        
        vector<int> ans;
        for(auto it= mp.begin();it!=mp.end();it++)
        {
           if(mp[it->first]==0)
               continue;
            int sz=mp[it->first];
            int ele2=it->first+gap;
            for(int i=0;i<sz;i++)
                ans.push_back((it->first+ele2)/2);
            mp[ele2]-=mp[it->first];
                
        }
    
        return ans;
        
        
    }
};
