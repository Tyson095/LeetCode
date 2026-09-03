class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> temp = strs ;
        vector<bool> used(strs.size(), false) ;
        vector<vector<string>> ans ;

        for(int i = 0 ; i < temp.size() ; i++) {
            sort(temp[i].begin(), temp[i].end()) ;
        }

        for(int i = 0 ; i < temp.size() ; i++) {
            if(used[i]) {
                continue ;
            }
            vector<string> curr ;

            for(int j = i ; j < temp.size() ; j++) {
                if(temp[i] == temp[j]) {
                    curr.push_back(strs[j]) ;
                    used[j] = true ;
                }
            }

            used[i] = true ;
            ans.push_back(curr) ;
        }

        return ans ;
    }
};