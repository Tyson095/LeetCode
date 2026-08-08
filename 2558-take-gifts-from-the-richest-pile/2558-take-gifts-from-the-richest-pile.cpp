class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans = 0 ;
        priority_queue<int> pq ;
        
        for(int i : gifts) {
            pq.push(i) ;
        }

        while(k > 0) {
            int gift = pq.top() ;
            pq.pop() ;
            int i = 0 ;
            for(i = 0 ; i*i <= gift ; ) {
                i++ ;
            }

            pq.push(--i) ;
            k-- ;
        }

        while(pq.size() > 0) {
            int gift = pq.top() ;
            pq.pop() ;

            ans += (long long)gift ;
        }

        return ans ;
    }
};