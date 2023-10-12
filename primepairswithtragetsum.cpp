class Solution {
    private:
            void findSubSet( vector<vector<int>>&ans, vector<int>&nums, int n){
        int i=0,j=nums.size()-1;
        while(i<=j){
            if(nums[i]+nums[j]==n){
                ans.push_back({nums[i],nums[j]});
                i++;
                j--;
            }
            else if(nums[i]+nums[j]<n)
            i++;
            else
            j--;
        }
    }
    
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>>ans;
        vector<int>v;
        vector<int>store;
               vector<bool>prime(n+1,true);
            prime[0]=prime[1]=false;
        
             for(int i=2;i<n;i++){
             if(prime[i])
             v.push_back(i);
             for(int j=2*i;j<n;j+=i)   
             prime[j]=false;
             }
                
        // sort(v.begin(),v.end());
       findSubSet(ans,v, n);
        return ans;
        
    }
};
