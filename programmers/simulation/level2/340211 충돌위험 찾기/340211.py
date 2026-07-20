from collections import defaultdict

def solution(points, routes):
    cnt =  defaultdict(int)
    
    for route in routes:
        x, y = points[route[0]-1]
        t = 0
        cnt[(t, x, y)] += 1
    
        for tar in route[1:]:
            tx, ty = points[tar-1]
            while tx != x or ty != y:
                t += 1
                if tx != x: x += 1 if tx > x else -1
                elif ty != y: y += 1 if ty > y else -1
                cnt[(t, x, y)] += 1
            
    return sum(1 for v in cnt.values() if v >= 2)