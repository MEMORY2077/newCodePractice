class Solution:
    def bestClosingTime(self, customers: str) -> int:
        n=len(customers)
        pre=[0]*(n+1)
        for i in range(1,n+1):
            pre[i]=pre[i-1]+(customers[i-1]=='Y')
        p=0x3f3f3f3f
        ans=0
        for i in range(0,n+1):
            now=i-pre[i]
            now+=(pre[n]-pre[i])
            if now < p:
                p = now
                ans = i
        return ans