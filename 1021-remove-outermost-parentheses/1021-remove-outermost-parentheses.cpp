class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int count = 0;
        deque<int> dq;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                count++;
                dq.push_back(s[i]);
            }else {
                count--;
                if(count == 0) {
                    dq.pop_front();
                    string temp(dq.begin(), dq.end());
                    ans += temp;
                    dq.clear();
                }else {
                    dq.push_back(s[i]);
                }
            }
        }

        return ans;
    }
};