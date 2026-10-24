class Solution {
public:
    int toDay(string& date) {
        int prefix[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
        int month = (date[0]-'0') * 10 + (date[1]-'0');
        int day = (date[3]-'0') * 10 + (date[4]-'0');

        return prefix[month - 1] + day;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        
        int start = max(toDay(arriveAlice), toDay(arriveBob));
        int end = min(toDay(leaveAlice), toDay(leaveBob));
        
        return max(0, end - start + 1);
    }
};