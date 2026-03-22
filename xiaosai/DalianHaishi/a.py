n,k=map(int,input().split())
v = 0
t = [""]*(n+1)
w = 0*(n+1)
que = []
l = []
passive = []
cnt = 0
for i in range(1,n+1):
    t[i],x=input().split()
    w[i]=int(x)
    que.append(i)
que = que[::-1]
 

