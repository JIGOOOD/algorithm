/*
1. 광물을 5개씩 쪼개고, 광물 개수를 기록
2. 다이아, 철, 돌이 많은 순으로 정렬
3. 그리고 다이아, 철, 돌 곡괭이 순으로 정렬한 광물 깨기 (다이아가 많을 수록 다이아 곡괭이로 깨야 함)
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

unordered_map<string, int> m = {{"diamond", 0}, {"iron", 1}, {"stone", 2}};
int cost[3][3] = {
    {1, 1, 1}, // 0: 다이아 곡괭이
    {5, 1, 1}, // 1: 철 곡괭이
    {25, 5, 1} // 2: 돌 곡괭이
};

int solution(vector<int> picks, vector<string> minerals) {
    // 광물 5개씩 나누고, 다이아, 철, 돌 많은 순으로 정렬
    int limit = picks[0] + picks[1] + picks[2];
    priority_queue<vector<int>> pq;
    
    int l = min((int)minerals.size(), limit * 5);
    for(int i=0; i<l; i+=5){
        vector<int> v = {0, 0, 0}; // 다이아, 철, 돌
        for(int j=0; j<5; j++){
            if(i+j >= l) break;
            string tar = minerals[i+j];
            v[m[tar]]++;
        }
        pq.push(v);
    }
    
    // 피로도 계산
    int answer = 0;
    int idx = 0;
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        int sum = 0;
        
        while(idx < 3){
            if(picks[idx] == 0){
                idx++;
            }else{
                picks[idx]--;
                for(int i=0; i<3; i++){
                    sum += (cost[idx][i] * cur[i]);
                }
                answer += sum;
                break;
            }
        }
    }
    return answer;
}