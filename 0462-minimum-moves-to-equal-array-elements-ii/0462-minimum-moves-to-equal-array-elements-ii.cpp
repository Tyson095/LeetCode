                     //     method 2 quickselect
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        auto target = nums.begin() + nums.size()/2;
        nth_element(nums.begin(), target, nums.end());
        int sum = 0;

        for(int i : nums) {
            sum += abs(i-*target);
        }

        return sum;
    }
};