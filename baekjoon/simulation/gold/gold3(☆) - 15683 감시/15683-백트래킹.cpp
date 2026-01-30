#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
typedef pair<int, int> pii;

vector<pii> cctv1 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
vector<vector<pii>> cctv2 = {{{1, 0}, {-1, 0}}, {{0, 1}, {0, -1}}};
vector<vector<pii>> cctv3 = {{{1, 0}, {0, 1}}, {{-1, 0}, {0, 1}}, {{-1, 0}, {0, -1}}, {{1, 0}, {0, -1}}};
vector<vector<pii>> cctv4 = {{{0, 1}, {1, 0}, {-1, 0}}, {{-1, 0}, {0, 1}, {0, -1}}, {{0, -1}, {1, 0}, {-1, 0}}, {{1, 0}, {0, 1}, {0, -1}}};
vector<vector<pii>> cctv5 = {{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}};

vector<vector<int>> board(10, vector<int>(10));
vector<pii> cctv;
int mn = INT_MAX;
int n, m;

// 바꿔야 함 보드 이건 참조로 해야 함
// point(현재 cctv) 돌려서 감시
void navigate(int x, int y, vector<vector<int>> &b, pii point){
    if(x == 1 && y == 0){ // 우
        while(true){
            point.second++;
            if(point.second >= m) break;

            int nxt = b[point.first][point.second];
            if(nxt == 6) break;
            else if(nxt == 0) b[point.first][point.second] = -1;
            else if((nxt >= 1 && nxt <= 5) || nxt == -1) continue;
        }
    }else if(x == 0 && y == 1){ // 상
        while(true){
            point.first--;
            if(point.first < 0) break;

            int nxt = b[point.first][point.second];
            if(nxt == 6) break;
            else if(nxt == 0) b[point.first][point.second] = -1;
            else if((nxt >= 1 && nxt <= 5) || nxt == -1) continue;
        }
    }else if(x == -1 && y == 0){ // 좌
        while(true){
            point.second--;
            if(point.second < 0) break;

            int nxt = b[point.first][point.second];
            if(nxt == 6) break;
            else if(nxt == 0) b[point.first][point.second] = -1;
            else if((nxt >= 1 && nxt <= 5) || nxt == -1) continue;
        }
    }else if(x == 0 && y == -1){ // 하
        while(true){
            point.first++;
            if(point.first >= n) break;

            int nxt = b[point.first][point.second];
            if(nxt == 6) break;
            else if(nxt == 0) b[point.first][point.second] = -1;
            else if((nxt >= 1 && nxt <= 5) || nxt == -1) continue;
        }
    }
}

// b는 재귀를 위해 원본 유지 (모든 조합 탐색)
void dfs(vector<vector<int>> b, int cnt){
    if(cnt == cctv.size()){
        int sum = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(b[i][j] == 0) sum++;
            }
        }
        mn = min(mn, sum);
        return;
    }

    // 배열 복사 (cctv로 감시할 영역 바꿀 것)
    vector<vector<int>> newb(10, vector<int>(10));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            newb[i][j] = b[i][j];
        }
    }

    auto target = cctv[cnt]; // 얘 돌려서 감시 구간 구하기
    int num = board[target.first][target.second]; //cctv 번호
    if(num == 1){
        for(auto v: cctv1){
            navigate(v.first, v.second, newb, target); // newb 변형 완료
            dfs(newb, cnt+1);
            newb = b;
        }
    }else if(num == 2){
        for(auto ct: cctv2){
            for(auto v: ct){ // 한 세트에 대한 변형 완료
                navigate(v.first, v.second, newb, target); // newb 변형 완료
            }
            dfs(newb, cnt+1);
            newb = b;
        }
    }else if(num == 3){
        for(auto ct: cctv3){
            for(auto v: ct){ // 한 세트에 대한 변형 완료
                navigate(v.first, v.second, newb, target); // newb 변형 완료
            }
            dfs(newb, cnt+1);
            newb = b;
        }
    }else if(num == 4){
        for(auto ct: cctv4){
            for(auto v: ct){ // 한 세트에 대한 변형 완료
                navigate(v.first, v.second, newb, target); // newb 변형 완료
            }
            dfs(newb, cnt+1);
            newb = b;
        }
    }else if(num == 5){
        for(auto ct: cctv5){
            for(auto v: ct){ // 한 세트에 대한 변형 완료
                navigate(v.first, v.second, newb, target); // newb 변형 완료
            }
            dfs(newb, cnt+1);
            newb = b;
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &board[i][j]);
            if(board[i][j] != 0 && board[i][j] != 6) cctv.push_back({i, j});
        }
    }
    dfs(board, 0);
    printf("%d", mn);
}