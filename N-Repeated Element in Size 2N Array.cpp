class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mid=nums.size()/2;
        int x=0;
        if(nums[mid]==nums[mid-1] || nums[mid]==nums[mid+1])
        x=nums[mid];
        if(nums[mid-1]==nums[mid-2])
        x=nums[mid-1];
        return x;
    }
};

