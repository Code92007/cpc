s = input()
v = int(s[2:6])
w = int(s[6:])
print("YES" if s[0]=='2' and s[1]=='2' and 1909<=v and v<=2025 and w>0 else "NO")