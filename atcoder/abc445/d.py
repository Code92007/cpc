from collections import defaultdict
n = int(input())
a=list(map(int,input().split()))
dp=defaultdict(int)
ans=0
for v in a:
    dp[v]=max(dp[v],dp[v-1]+1)
    ans=max(ans,dp[v])
print(ans)