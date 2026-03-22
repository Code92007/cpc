def cal(x):
    return ["Passive","Modifier","Projectile*","Projectile","Multi","Jump"].index(x)
n, k, a, p, q = map(int, input().split()), [None] * (n + 1), [], []
for i in range(1, n + 1):
    parts = input().split()
    t, x = cal(parts[0]), int(parts[1])
    if t == 0:
        p.append(i)
    else:
        q.append(i)
    a[i] = (t, x)
pos, v, m, pr, reloaded = 0, 0, len(q),  [], False
for _ in range(k):
    if reloaded:
        reloaded = False
        pos = 0
    if pos >= m:
        reloaded = True
        pos = 0
    cnt, now, pr = 1, [], []
    while cnt > 0:
        if pos >= m:
            if reloaded:
                break
            reloaded = True
            pos = 0
            continue
        cur = q[pos]
        pos += 1
        cnt -= 1
        now.append(cur)
        t, x = a[cur]  
        if t == 1:
            v += x
        elif t in (2,3):
            pr.append((cur, v + x))
        elif t == 4:
            cnt += x
        else:
            if v:
                if not reloaded:
                    reloaded = True
                    pos = 0
                pos += x
                cnt += 1
        if t in (1,2):
            cnt += 1
    res = [str(pid) for pid in p] + [str(rid) for rid in now] + [f"({pid},{p})" for pid, p in pr] 
    print(" ".join(res))

