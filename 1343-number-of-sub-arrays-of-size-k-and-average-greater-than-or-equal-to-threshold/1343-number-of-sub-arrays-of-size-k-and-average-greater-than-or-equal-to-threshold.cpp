class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int ans = 0;
        int sum = 0;

        for(int i = 0; i < k; i++) {
            sum += arr[i];
        }

        if(sum/k >= threshold) {
            ans++;
        }

        for(int i = 1; i <= arr.size()-k; i++) {
            int l = arr[i-1];
            int r = arr[i+k-1];

            sum -= l;
            sum += r;

            if(sum/k >= threshold) {
                ans++;
            }
        }

        return ans;
    }
};