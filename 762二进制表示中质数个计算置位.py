class Solution:
    def countPrimeSetBits(self, left: int, right: int) -> int:
        def isPrime(num:int) ->bool:
            if num == 1 or num == 0:
                return False
            if num == 2:
                return True
            c = int(num ** 0.5)
            for i in range(2,c+1):
                if num % i == 0:
                    return False
            return True
        def myCount(num:int):
            c = 0
            while num!=0:
                if num&1 != 0:
                    c += 1
                num >>= 1
            return c
        ans = 0
        for i in range(left,right+1):
            c = myCount(i)
            print(f"{i}:{c}")
            if isPrime(c):
                ans+=1
        return ans
            