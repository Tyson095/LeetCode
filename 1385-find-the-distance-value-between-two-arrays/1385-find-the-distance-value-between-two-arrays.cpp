class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;
        sort(arr2.begin(), arr2.end());

        for(int i : arr1) {
            int l = 0, r = arr2.size() - 1;
            bool valid = true;
            
            while(l <= r) {
                int mid = l + (r - l) / 2;

                if(abs(i - arr2[mid]) <= d) {
                    valid = false;
                    break;
                }

                if(arr2[mid] < i) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            if(valid) {
                ans++;
            }
        }

        return ans;
    }
};
