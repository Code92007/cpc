from collections import Counter
n = int(input())
a = list(map(int,input().split()))
b = Counter(a)
w = b.most_common(1)[0]
# print(w[1])
# print(w)
print("Yes" if w[1]==1 else "No")