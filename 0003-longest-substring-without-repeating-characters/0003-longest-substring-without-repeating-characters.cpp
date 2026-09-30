class Solution {
public:
    int lengthOfLongestSubstring(string s){
        int left = 0;
        int maxLength = 0;
        unordered_map<char, int> charMap;

        for(int right = 0; right < s.length(); right++){
            
            if (charMap.find(s[right]) != charMap.end() && charMap[s[right]] >= left) {
                left = charMap[s[right]] + 1;
            }

            charMap[s[right]] = right;
 
            maxLength = max(maxLength, right - left + 1);
        }

    return maxLength;
    }
};   