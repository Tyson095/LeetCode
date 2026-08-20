class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1, arr2 ;
        int n = nums.size(), idx = 2 ;
        n -= 2 ;
        arr1.push_back(nums[0]) ;
        arr2.push_back(nums[1]) ;

        while(n--) {
            if(arr1.back() < arr2.back()) {
                arr2.push_back(nums[idx++]) ;
            }else {
                arr1.push_back(nums[idx++]) ;
            }
        }

        arr1.insert(arr1.end(), arr2.begin(), arr2.end()) ;

        return arr1 ;
    }
};