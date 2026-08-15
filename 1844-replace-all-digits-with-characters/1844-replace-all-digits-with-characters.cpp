class Solution {
public:
    string replaceDigits(string s) {
        for(int i = 0 ; i < s.size() ; i++) {
            if(i >0 && s[i] >= '0' && s[i] <= '9') {
                int shift = s[i] - '0' ;

                s[i] = (char)(s[i-1] + shift) ;
            }
        }

        return s ;
    }
};