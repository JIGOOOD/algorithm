from collections import deque

s = input()

a = deque()
c = deque()
vis = [0] * 300002

n = len(s)

for i in range(n):
    if s[i] == 'A': a.append(i)
    elif s[i] == 'C': c.append(i)

res = 0
for i in range(n):
    if s[i] == 'B':
        while a and vis[a[0]]: a.popleft()
        while c and (c[0] < i or vis[c[0]]): c.popleft()

        if not a and not c: break # 뒤에도 어차피 없을테니
        elif a and not c:
            if a[0] > i: continue
            vis[a[0]] = 1
            a.popleft()
            vis[i] = 1
            res += 1
        else:
            vis[c[0]] = 1
            c.popleft()
            vis[i] = 1
            res += 1

print(res)