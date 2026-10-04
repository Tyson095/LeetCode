class Solution {
public:
    bool checkValidString(string s) {
        int cmin = 0; // Minimum possible open brackets
        int cmax = 0; // Maximum possible open brackets
        
        for (char c : s) {
            if (c == '(') {
                cmin++;
                cmax++;
            } else if (c == ')') {
                cmin--;
                cmax--;
            } else if (c == '*') {
                cmin--; // If we treat '*' as ')'
                cmax++; // If we treat '*' as '('
            }
            
            if (cmax < 0) return false;
            
            if (cmin < 0) cmin = 0; // if cmin < 0 and cmax >= 0, it means if we leave * we can achive valid paranthesis
        }
        
        return cmin == 0;
    }
};
