t=int(input())
while t>0:
    t-=1
    n,d=map(int,input().split())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    now = []
    idx = 0
    for i in range(n):
        now.append([a[i],i])
        while idx<len(now):
            v = min(b[i],now[idx][0])
            b[i] -= v
            now[idx][0] -= v
            if not now[idx][0]:
                idx += 1
            if not b[i]:
                break
        while idx<len(now) and now[idx][1]<=i-d:
            idx += 1
    print(sum(v[0] for v in now[idx:]))