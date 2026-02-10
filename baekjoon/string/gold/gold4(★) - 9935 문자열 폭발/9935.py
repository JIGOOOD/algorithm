a = input().strip()
boom = input().strip()
stack = []
b_len = len(boom)

for ch in a: # O(n)
    stack.append(ch)
    if len(stack) >= b_len:
        if ''.join(stack[-b_len:]) == boom: # O(b_len) = O(1)
            del stack[-b_len:] # O(b_len) = O(1)

result = ''.join(stack)
print(result if result else "FRULA")