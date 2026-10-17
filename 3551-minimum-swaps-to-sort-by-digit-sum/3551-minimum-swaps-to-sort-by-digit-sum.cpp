class Solution {
public:
    int digitSum(int x) {
        int sum = 0;

        while(x) {
            sum += x % 10;
            x /= 10;
        }

        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> equ; // {sum(x), x} 

        for(int x : nums) {
            equ.push_back({digitSum(x), x});
        }
        sort(equ.begin(), equ.end());
        unordered_map<int, int> m;  // {x, new idx}

        for(int i = 0; i < n; i++) {
            m[equ[i].second] = i;
        }
        vector<int> temp;

        for(int x : nums) {
            temp.push_back(m[x]);
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {
            while(temp[i] != i) {
                int j = temp[i];
                swap(temp[i], temp[j]);
                ans++;
            }
        }

        return ans;
    }
};