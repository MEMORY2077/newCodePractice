class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        p = 0
        q = 1
        n = c = len(nums)
        cc = 1
        while q != n:
            if nums[p] == nums[q] and cc != 2:
                p += 1
                nums[p] = nums[q]
                cc += 1
                q += 1
            elif nums[p] == nums[q]:
                q+=1
                c-=1
            elif nums[p] != nums[q]:
                cc = 1
                p+=1
                nums[p]=nums[q]
                q+=1
        return c