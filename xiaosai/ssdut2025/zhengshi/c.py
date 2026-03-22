eps = 1e-14
def cal(c):
    no = 1.0
    e = 0.0
    k = 0
    if abs(c-1.0)<eps:
        return 1.0
    while k<100000:
        prob = min(1.0,c*(k+1))
        prob2 = no*prob
        e += (k+1)*prob2
        no *= 1.0-prob
        k += 1
        if no<eps:
            break
    if e<eps:
        return 0.0
    # print(f"c:{c} e:{1.0/e}")
    return 1.0/e

t = int(input())
while t>0:
    t-=1
    p = float(input())
    if abs(p-1.0)<eps:
        print("1.000000000000000")
        continue
    l,r=1e-6,1
    for _ in range(100):
        m=(l+r)/2
        if cal(m)>p:
            r=m
        else:
            l=m
    print(f"{r:.15f}")
    # print(ans/cnt)
# print(0.01+0.99*0.02+0.99*0.98*0.03)