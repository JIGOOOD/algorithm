#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef pair<int, int> pii;

vector<pii> cosmos[102];
vector<string> cmp;

int main(){
    int n, m, s, cnt = 0;
    scanf("%d %d", &m, &n);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &s);
            cosmos[i].push_back({s, j});
        }
        sort(cosmos[i].begin(), cosmos[i].end());

        string str= "";
        str += to_string(cosmos[i][0].second);
        for(int j=0; j<n-1; j++){
            if(cosmos[i][j].first == cosmos[i][j+1].first){
                cosmos[i][j+1].second = cosmos[i][j].second;
            }
            str += to_string(cosmos[i][j+1].second);
        }
        cmp.push_back(str);
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            if(i>=j) continue;
            if(cmp[i] == cmp[j]) cnt++;
        }
    }
    printf("%d", cnt);
}