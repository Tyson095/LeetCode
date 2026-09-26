class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        long long sum1 = 0, sum2 = 0;

        for(int i : source) {
            sum1 += i;
        }
        for(int i : target) {
            sum2 += i;
        }

        return sum1 == sum2;
    }
};