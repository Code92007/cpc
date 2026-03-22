def cal(t, w): # 数值t在w轮的位置
    if w<2*t:
        return t
    pos = t
    cur = t
    t = 2*t-1
    inf = 1e18
    # cnt = 0 
    while t<=inf:
        # print(f"t:{t} w:{w} t+cur:{t+cur} pos:{pos}")
        if t<=w and w<=t+cur:
            return pos-(w-t)
        t += cur + 1
        pos = t // 2
        cur = pos
        # cnt += 1
    return -1
# cnt2 = 0
def cal2(x, t):
    # print(f"x:{x} t:{t}")
    # global cnt2
    # cnt2 += 1
    if t <= 1:
        return x
    if x > t // 2:
        return x
    elif x == t // 2:
        return cal2(0, t-1)
    nx, nt = x, t 
    w = (nt-1-2*nx)//3
    nt -= w
    nx += w
    if nx != nt // 2:
        nx += 1
        nt -= 1
    # print(f"nx:{nx} nt:{nt}")
    return cal2(nx, nt)
# for i in range(0,10):
#     for j in range(i,10):
#         print(f"i:{i} j:{j} cal:{cal(i,j)}")
#    满足x+w=(t-w-1)//2 2*x+2*w=t-w或2*x+2*w=t-w-1 w=t-2*x或3w=t-1-2x 3*w=t-2*x
# 
# for i in range(0,15):
#     print(cal2(i,14))
# print(cnt2)
q = int(input())
while q>0:
    q -= 1
    op, x, y = map(int,input().split())
    if op == 1:
        print(cal(x,y))
    else:
        print(cal2(x,y))