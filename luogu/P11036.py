for _ in range(int(input())):
    a = int(input())
    c = 2 * (a & -a)
    print(1, c, a + c)