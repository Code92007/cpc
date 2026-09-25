n = 200000
m = 20
special = 18

print(n, m)

# 19 维空间：
# span(bit 0..15, bit 17, bit 18, bit 19)
# 前 17 轮反复枚举，之后与当前 W 合并成完整的 20 维空间。
high_parts = [
    0,
    1 << 17,
    1 << 18,
    (1 << 17) | (1 << 18),
    1 << 19,
    (1 << 17) | (1 << 19),
    (1 << 18) | (1 << 19),
    (1 << 17) | (1 << 18) | (1 << 19),
]

large_space = []
for high in high_parts:
    large_space.extend(high | x for x in range(1 << 16))

print(len(large_space), *large_space)

# 让 W 每轮只增加一个维度。
for k in range(17, 1, -1):
    low_size = 1 << (k - 2)
    high_bit = 1 << (k - 1)
    values = list(range(low_size))
    values += [high_bit | x for x in range(low_size)]
    print(len(values), *values)

# 增大每一轮扫描 n 个集合的成本。
for _ in range(n - special):
    print(1, 1)

# 第一轮最后只迫使 W 增加向量 1。
print((1 << 17) - 2, *range(2, 1 << 17))
