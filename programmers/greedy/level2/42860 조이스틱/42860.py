def solution(name):
    answer = 0
    l = len(name)
    
    # 상하로 전체 알파벳 결정
    for i in range(l):
        tar = ord(name[i])
        answer += min(tar - ord('A'), ord('Z') - tar + 1)
    
    mn = l-1
    # 좌우로 꺾는 지점 최솟값 결정
    for i in range(l): # i가 꺾는 지점
        nxt = i+1
        while nxt < l and name[nxt] == 'A': nxt += 1 # i뒤에 처음으로 나오는 'A'가 아닌 값
        mn = min([mn, i*2 + (l-nxt), i + 2*(l-nxt)])
    
    answer += mn
    return answer