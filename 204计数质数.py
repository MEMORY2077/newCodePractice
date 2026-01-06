class Solution:
    def countPrimes(self, n: int) -> int:
        primes = [True] * (n + 1)
        primes[0]=False
        primes[1]=True
        for i in range(2, n//2+1):
            if primes[i]:
                for j in range(2, i):
                    now = j * i
                    if now > n:
                        break
                    primes[now]=False
        ans = 0
        for isprime in primes:
            if isprime:
                ans += 1
        return ans
