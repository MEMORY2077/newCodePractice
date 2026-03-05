class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        ans = hp = 0
        for x in nums:
            if hp == 0:
                ans, hp = x, 1
            else:
                hp +=1 if ans == x else - 1
        return ans