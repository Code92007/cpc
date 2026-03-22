t = int(input())
while t>0:
    t -= 1
    a, b = map(int,input().split())
    def cal(x, y):
        ans = 0
        now = 1
        while x >= now:
            x -= now
            ans += 1
            z = x
            x = y
            y = z
            now *= 2
        return ans
    print(max(cal(a,b),cal(b,a)))