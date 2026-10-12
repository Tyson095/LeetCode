class Solution {
public:
    int strStr(string hay, string ndl) {
        if(ndl.size() > hay.size()) {
            return -1;
        }

        for(int i = 0; i < hay.size(); i++) {
            if(hay[i] == ndl[0]) {
                for(int j = 0, i2 = i; j < ndl.size() && i2 < hay.size(); j++, i2++) {
                if(hay[i2] != ndl[j]) {
                    break;
                }

                if(hay[i2] == ndl[j] && j == ndl.size()-1) {
                    return i;
                    }
                }
            }
        }

        return -1;
    }
};