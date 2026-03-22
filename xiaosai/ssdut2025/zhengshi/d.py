x = int(input())
def dfs(x):
    # print(x)
    if x == 1:
        return 0
    if x%2==1:
        return dfs(3*x+1)+1
    else:
        return dfs(x//2)+1
print(dfs(x))