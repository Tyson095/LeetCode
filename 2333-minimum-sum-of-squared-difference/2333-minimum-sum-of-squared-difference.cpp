class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2, ans = 0,  sum = 0;
        int n = nums1.size();

        int maxDiff = 0;
        vector<int> diff(n);

        for(int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxDiff = max(maxDiff, diff[i]);
            sum += diff[i];
        }

        if(sum <= k) {
            return 0;
        }

        vector<long long> freq(maxDiff+1, 0);

        for(int i : diff) {
            freq[i]++;
        }

        for(int i =  maxDiff; i > 0 && k > 0; i--) {
            if(freq[i] == 0) {
                continue;
            }
            if(k >= freq[i]) {
                k -= freq[i];
                freq[i-1] += freq[i];
                freq[i] = 0;
            }else {
                freq[i-1] += k;
                freq[i] -= k;
                k = 0;
            }
        }

        for(int i = 0; i <= maxDiff; i++) {
            ans += freq[i] * i * i;
        }

        return ans;
    }
};