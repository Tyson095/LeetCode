class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        int i = arr1.size() - 1;
        int j = arr2.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry != 0) {
            int sum = carry;
            if (i >= 0) sum += arr1[i--];
            if (j >= 0) sum += arr2[j--];

            int rem = sum % -2;
            carry = sum / -2;

            if (rem < 0) {
                rem += 2;
                carry += 1; 
            }

            ans.push_back(rem);
        }

        while (ans.size() > 1 && ans.back() == 0) {
            ans.pop_back();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
