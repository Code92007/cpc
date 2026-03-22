a,b,c = map(int,input().split())
print('1' if any(x+y+z==180 for x in [a,360-a] for y in [b,360-b] for z in [c,360-c]) else '0')