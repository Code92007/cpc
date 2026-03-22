def inv(a, p):
    return pow(a, p - 2, p)
def C(n, k, p):
    if k > n:
        return 0
    num = 1
    deno = 1
    for i in range(min(k, n - k)):
        num = (num * (n - i)) % p
        deno = (deno * (i + 1)) % p
    return (num * inv(deno, p)) % p
def F(n,p):
    if n == 0 or n == 1:
        return 1
    f = 1
    for i in range(2, n + 1):
        f = f*i%p
    return f
t = int(input())
while t>0:
    t -= 1
    n = int(input())
    a = list(map(int,input().split()))
    b = a[1:]
    mod = 998244353
    ans = sum(a)
    low = ans//n
    if ans%n==0:
        if max(b)>low:
            print(0)
        else:
            print(F(n,mod))
    else:
        high = low+1
        cnt2 = ans%n
        cnt1 = n-cnt2 #low有cnt1个，high有cnt2个
        if max(b)>high:
            print(0)
        elif b.count(high)>cnt2:
            print(0)
        else:
            cnt3 = b.count(high)
            print(C(n-cnt3,cnt2-cnt3,mod)*F(cnt2,mod)%mod*F(cnt1,mod)%mod)
'''
2 1 1可行
2 2 2可行
2 1 0不可行
给一个序列 将a0分配出去
使得a1-an是非严格单调递减的
并且要么所有数都相同，要么前面一半数和后面一半数只能差1，问方案数
首先sum是固定的，所以最后分配的方式一定是固定的
'''