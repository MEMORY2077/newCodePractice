class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        n = len(s)
        pre = cur = ans = 0
        for i in range(n):
            cur += 1
            if i == n - 1 or s[i] != s[i+1]:
                ans += min(pre,cur)
                pre = cur
                cur = 0
        return ans