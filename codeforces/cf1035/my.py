bs = int(input())
n = int(input())
res = 0 
for v in range(1000000):
    if not v:
        a = ""
        b = 0
    else:
        a = str(v)
        b = int(a + a[::-1])
    def conv(w):
        if w > n:
            return False
        ans = []
        while w > 0:
            ans.append(w % bs)
            w //= bs
        return ans == ans[::-1]
    if conv(b):
        res += b
    if v < 100000:
        for x in range(10):
            b = int(a + str(x) + a[::-1])
            if conv(b):
                res += b
print(res)
