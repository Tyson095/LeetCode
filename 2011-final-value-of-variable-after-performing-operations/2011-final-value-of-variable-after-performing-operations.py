class Solution:
    def finalValueAfterOperations(self, operations) :
        ans = 0
        for op in operations:
            if op[1] == '+':
                ans += 1
            else:
                ans -= 1
        return ans