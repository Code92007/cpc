t = int(input())
a = [26]
mx = 1e18
while a[-1]<mx:
    a.append(a[-1]*26)
# print(a)
while t>0:
    t-=1
    w = int(input())
    las = 1
    for v in a:
        if w>v:
            w-=v
            las=v
        else:
            break
    las*=26
    #print(las)
    #print(w)
    w -= 1
    x = ""
    # print(w)
    # print(las)
    while las>1:
        x += chr((w%26)+ord('A'))
        w //= 26
        las//=26
        # print(x)
        
    x = x[::-1]
    print(x)