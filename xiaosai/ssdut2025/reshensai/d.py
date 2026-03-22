t = int(input())
all = ["PUSH","DUP","UNION","INTERSECT","ADD"]
while t > 0:
    t -= 1
    m = int(input())
    stk = []
    for _ in range(m):
        s = input()
        idx = all.index(s)
        if idx == 0:
            ele = set()
            stk.append(ele)
        elif idx == 1:
            w = set(stk[-1])
            stk.append(w)
        elif idx == 2:
            w = set(stk.pop())
            w2 = set(stk.pop())
            w2 |= w
            stk.append(w2)
        elif idx == 3:
            w = set(stk.pop())
            w2 = set(stk.pop())
            w2 &= w
            stk.append(w2)
        else:
            w = frozenset(stk.pop())
            w2 = set(stk.pop())
            w2.add(w)
            stk.append(w2)
        print(len(stk[-1]))