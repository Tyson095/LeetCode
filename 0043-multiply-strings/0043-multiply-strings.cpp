class Solution {
public:
    string add(string nums1, string nums2) {
        string ans ;

        int i = nums1.size()-1, j = nums2.size()-1 ;
        int carry = 0 ;

        while(i >= 0 && j >= 0) {

            int a = nums1[i--] - '0' ;
            int b = nums2[j--] - '0' ;

            int x = (a + b + carry) % 10 ;
            carry = (a + b + carry) / 10 ;

            ans.push_back('0' + x) ;
        }

        while(i >= 0) {
            int a = nums1[i--] - '0' ;
            int x = (a + carry) % 10 ;
            carry = (a + carry) / 10 ;
            ans.push_back('0' + x) ;
        }

        while(j >= 0) {
            int a = nums2[j--] - '0' ;
            int x = (a + carry) % 10 ;
            carry = (a + carry) / 10 ;
            ans.push_back('0' + x) ;
        }
        
        if(carry != 0) {
            ans.push_back(carry + '0') ;
        }

        reverse(ans.begin(), ans.end()) ;
        return ans ;
    }


    string multiply(string nums1, string nums2) {
        if (nums1 == "0" || nums2 == "0") {
            return "0";
        }
        string ans = "0" ;

        int i = nums1.size()-1, j = nums2.size()-1 ;

        while(j >= 0) {
            string curr ;
            int carry = 0 ;

            int temp = j ;
            while(temp < nums2.size()-1) {
                curr.push_back('0') ;
                temp++ ;
            }

            temp = i ;
            while(temp >= 0) {
                int a = nums1[temp--] - '0' ;
                int b = nums2[j] - '0' ;

                int x = ((a*b) + carry) % 10 ;
                carry = ((a*b) + carry) / 10 ;

                curr.push_back('0' + x) ;
            }
            if(carry != 0) {
                curr.push_back('0' + carry) ;
            }

            reverse(curr.begin(), curr.end()) ;
            ans = add(ans, curr) ;
            j-- ;
        }

        return ans ;
    }
};