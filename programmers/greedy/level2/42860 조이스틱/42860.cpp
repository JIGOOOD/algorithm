#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string name) {
    int len = name.size();
    int answer = 0;

    for(int i=0; i<len; i++){
        char tar = name[i];
        answer += min(tar-'A', 'Z'-tar+1);
    }

    int mn = len - 1;

    for(int i=0; i<len; i++){
        if(name[i] == 'A') continue;

        int next = i+1;
        while(next < len && name[next] == 'A'){
            next++;
        }

        int cost = i*2 + (len - next);
        if(cost < mn){
            mn = cost;
        }
    }

    answer += mn;
    return answer;
}