n,q=map(int,input().split())
a = list(map(int,input().split())
b = [0]*n
for i in range(n):
    if i==0:
        b[i]=a[i]
    else:
        b[i]=b[i-1]+a[i]
while q>0:
    q-=1
    l,r =map(int,input().split()) 
    l-=1
    r-=1
    if l==0:
        print(b[r])
    else:
        print(b[r]-b[l-1])