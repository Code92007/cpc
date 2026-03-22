from collections import defaultdict
op = input()
s = list(input().split(" "))
if op == "sheify":
    if "she" in s:
        print(" ".join(s))
    else:
        a = defaultdict(int)
        for v in s:
            a[v] += 1
        ch = ""
        cnt = 10000000
        for v in s:
            if a[v]<cnt:
                ch = v
                cnt = a[v]
            elif a[v]==cnt and v<ch:
                ch = v
        for (i,v) in enumerate(s):
            if v == ch:
                s[i] = "she"
                break
        print(" ".join(s))
elif op == "desheify":
    if s.count("she") >= 2:
        print(" ".join(s))
    else:
        a = defaultdict(int)
        for v in s:
            a[v] += 1
        ch = ""
        cnt = 10000000
        for v in s:
            if v == "she":
                continue
            if a[v]<cnt:
                ch = v
                cnt = a[v]
        for (i,v) in enumerate(s):
            if v == "she":
                s[i] = ch
                break
        print(" ".join(s))