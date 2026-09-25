#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 0;

void dfs(int cnt, int sum, int n, vector<int>& numbers, int& target){
    if(cnt == n){
        if(sum == target) answer++;
        return;
    }
    
    // 해당 요소 값이 +인 경우와 -인 경우를 모두 탐색, 이때는 for문을 돌지 않고 그 횟수만큼 재귀함수를 호출
    dfs(cnt+1, sum+numbers[cnt], n, numbers, target);
    dfs(cnt+1, sum-numbers[cnt], n, numbers, target);

}

int solution(vector<int> numbers, int target) {
    dfs(0, 0, numbers.size(), numbers, target);
    return answer;
}