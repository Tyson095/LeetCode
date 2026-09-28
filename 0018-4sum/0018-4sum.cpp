class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4)return{};
        long long int sum;
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i = 0 ; i < nums.size()-3 ; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1 ; j < nums.size()-2 ;){
                int st = j+1 , end = nums.size()-1;
                while(st < end){
                    sum = (long long)nums[i] + nums[j] + nums[st] + nums[end];
                    if(sum == target){
                        ans.push_back({nums[i] , nums[j] , nums[st] , nums[end]});
                        st++;end--;
                        while(st < end && nums[st] == nums[st-1]) st++;
                    }
                    else if(sum < target){
                        st++;
                    }
                    else end--;
                }
                j++;
            while(j > i && j< nums.size() && nums[j] == nums[j-1]) j++;
            }
        }
    return ans;}
};