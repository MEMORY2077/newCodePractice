from typing import List
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        c=1
        for now in range(len(digits)-1,-1,-1):
            if c == 0: return digits
            digits[now] += c
            c = 0
            if digits[now] == 10:
                digits[now] = 0
                c = 1
        if c == 1:
            digits.insert(0,1)
        return digits