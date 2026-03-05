#1:存到新数组里
#2:三次反转(此代码) 
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        def reverse(i:int ,j:int)->None:
            while i<j:
                temp=nums[i]
                nums[i]=nums[j]
                nums[j]=temp
                i+=1
                j-=1
        n=len(nums)
        k%=n
        reverse(0,n-1)
        reverse(0,k-1)
        reverse(k,n-1)    
        