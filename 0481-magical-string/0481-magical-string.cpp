class Solution {
public:
    int magicalString(int n) {
        if (n <= 0) return 0;
        if (n <= 3) return 1;

        string s = "122";        
        int i = 2; 

        while (s.length() < n) {
            
            char nextChar = (s.back() == '1') ? '2' : '1';
            int count = s[i] - '0'; 
            
            s.append(count, nextChar);
            i++;
        }

        int ans = 0;
        for (int j = 0; j < n; j++) {
            if (s[j] == '1') ans++;
        }

        return ans;
    }
};
