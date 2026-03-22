from math import *
k = int(input())
t = max(0,int(sqrt(k))-2)
while t*t+3*t+1<k:
    t += 1
print(["Lua","XUU","Dust"][t%3])