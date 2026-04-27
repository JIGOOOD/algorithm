#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

vector<string> answer;
unordered_map<string, priority_queue<string, vector<string>, greater<string>>> m;

void dfs(string cur){
    while(m.count(cur) && !m[cur].empty()){
        string nxt = m[cur].top(); m[cur].pop();
        dfs(nxt);
    }
    answer.push_back(cur);
}

vector<string> solution(vector<vector<string>> tickets) {
    for(auto ticket: tickets){
        m[ticket[0]].push(ticket[1]);
    }
    
    dfs("ICN");
    reverse(answer.begin(), answer.end());
    return answer;
}