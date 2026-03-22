from datetime import date
t=int(input())
while t>0:
    t-=1
    a,b,c,d,e,f=map(int,input().split())
    st=date(a,b,c)
    ed=date(d,e,f)
    dt=ed-st
    ans=max(0,dt.days+1)
    print(ans)