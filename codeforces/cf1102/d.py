MOD = 10**9 + 7
t = int(input())
results = []

def dfs(l, r, left, right, n):
    if l + 1 == r:
        sum_x = 0
        sum_x2 = 0
        for i in range(n):
            x1 = left[i]
            x2 = right[i]
            sum_x += x1 + x2
            sum_x2 += x1 * x1 + x2 * x2
        return sum_x % MOD, sum_x2 % MOD
    
    mid = (l + r) // 2
    mid_vec = [left[i] ^ right[i] for i in range(n)]
    
    left_sum_x, left_sum_x2 = dfs(l, mid, left, mid_vec, n)
    right_sum_x, right_sum_x2 = dfs(mid, r, mid_vec, right, n)
    
    return (left_sum_x + right_sum_x) % MOD, (left_sum_x2 + right_sum_x2) % MOD

for _ in range(t):
    n, k = map(int, input().split())
    s = input().strip()
    z = input().strip()
    
    s_vec = [int(ch) for ch in s]
    z_vec = [int(ch) for ch in z]
    
    L = 1 << (k + 1)
    total_sum_x, total_sum_x2 = dfs(1, L, s_vec, z_vec, n)
    
    ans = (n * total_sum_x - total_sum_x2) % MOD
    results.append(str(ans))

print("\n".join(results))