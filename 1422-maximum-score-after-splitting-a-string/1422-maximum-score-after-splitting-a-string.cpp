class Solution {
public:
    int maxScore(string s) {
        int st , mid , end , count;
        st = mid = count = 0 ;
        end = s.length()-1;

        while(mid < end){
            int left = 0 , right = 0 ;
            for(int i = st ; i <= mid ; i++){             // left subset
                if(s[i] == '0') left++;
            }
            for(int i = mid + 1 ; i <= end ; i++){        // right subset
                if(s[i] == '1') right++;
            }
            mid++;
            count = max(count , right+left);

        }
    return count ;}
};