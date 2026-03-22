n,m=map(int,input().split())
used = [False]*(m+1)
for i in range(n):
    l = int(input())
    a = list(map(int,input().split()))
    ans = 0
    for v in a:
        if not used[v]:
            ans = v
            used[v] = True
            break
    print(ans)