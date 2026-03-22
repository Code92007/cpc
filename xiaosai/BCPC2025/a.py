from datetime import datetime
n = int(input())
dt = "%Y-%m-%d"
a,b = input().split()
c = datetime.strptime(a,dt)
d = datetime.strptime(b,dt)
ans = 0
for _ in range(n):
    e,f = input().split()
    e = e[:-1]
    g = datetime.strptime(e,dt)
    f = int(f)
    if c<=g and g<=d:
        ans+=f
print(ans)