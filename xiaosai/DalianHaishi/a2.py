from collections import deque

def simulate(n, k, spells):
    # 法术列表，1-indexed
    # spells[i] = (type, x)
    
    # 初始队列：所有非 Passive 的法术编号
    queue = deque()
    passive_ids = []
    for i in range(1, n+1):
        t, x = spells[i]
        if t == "Passive":
            passive_ids.append(i)
        else:
            queue.append(i)
    
    v = 0
    reloaded = False
    output_lines = []
    
    # 投射物列表
    projectiles = []
    
    # 模拟 k 次魔法
    for magic_time in range(k):
        released = []  # 本次魔法释放的法术编号顺序
        projectiles.clear()
        
        # 当前魔法：不断释放直到队列空或满足条件
        while True:
            if not queue:
                # 队列空，尝试重新加载
                if not reloaded:
                    # 重新加载：把非 Passive 的法术重新加入队列（原始顺序）
                    for i in range(1, n+1):
                        if spells[i][0] != "Passive":
                            queue.append(i)
                    reloaded = True
                else:
                    # 无法重新加载，本次魔法结束
                    break
            
            current_id = queue.popleft()
            released.append(current_id)
            t, x = spells[current_id]
            
            if t == "Modifier":
                v += x
                # 自动释放下一个
                continue  # 继续 while 循环，取下一个法术
            elif t == "Projectile*":
                p = v + x
                if p != 0:
                    projectiles.append((current_id, p))
                # 自动释放下一个
                continue
            elif t == "Projectile":  # 不带星号
                p = v + x
                if p != 0:
                    projectiles.append((current_id, p))
                # 不带星号，不自动释放下一个，本次魔法结束
                break
            elif t == "Multi":
                # 进行 x 次释放下一个法术
                # 这里需要小心：下一个法术可能被多次释放，但队列会变化吗？
                # 样例中没有 Multi，暂时假设不实现
                pass
            elif t == "Jump":
                if v == 0:
                    # 无动作
                    break
                else:
                    # 步骤 1: 重新加载
                    if not reloaded:
                        new_queue = deque()
                        for i in range(1, n+1):
                            if spells[i][0] != "Passive":
                                new_queue.append(i)
                        queue = new_queue
                        reloaded = True
                    # 步骤 2: 消耗 x 个法术
                    for _ in range(x):
                        if queue:
                            queue.popleft()
                        else:
                            break
                    # 步骤 3: 释放下一个法术（继续 while 循环）
                    continue
            else:
                # Passive 不应该在队列中
                break
        
        # 构建输出行
        line_parts = []
        # 被动法术编号
        for pid in passive_ids:
            line_parts.append(str(pid))
        # 释放的法术编号
        for rid in released:
            line_parts.append(str(rid))
        # 投射物
        for proj_id, param in projectiles:
            line_parts.append(f"({proj_id},{param})")
        output_lines.append(" ".join(line_parts))
    
    return output_lines

# 读取输入
def main():
    import sys
    data = sys.stdin.read().strip().splitlines()
    if not data:
        return
    n, k = map(int, data[0].split())
    spells = [None] * (n + 1)  # 1-indexed
    for i in range(1, n + 1):
        parts = data[i].split()
        t = parts[0]
        x = int(parts[1])
        spells[i] = (t, x)
    
    outputs = simulate(n, k, spells)
    for out in outputs:
        print(out)

if __name__ == "__main__":
    main()