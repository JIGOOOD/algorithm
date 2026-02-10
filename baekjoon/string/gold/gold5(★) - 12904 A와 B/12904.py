import sys
input = sys.stdin.readline

s = input().strip()
t = input().strip()

while True:
    if t[-1] == 'A':
        t = t[:-1]
    else:
        t = ''.join(reversed(t[:-1]))
    
    if len(t) == len(s):
        if t == s: print(1)
        else: print(0)
        break
    