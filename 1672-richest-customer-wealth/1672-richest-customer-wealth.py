class Solution(object):
    def maximumWealth(self, accounts):
	maxWealth = 0
	for i in range(len(accounts)):
		totalWealth = sum(accounts[i])
		maxWealth = max(maxWealth, totalWealth)
	return maxWealth