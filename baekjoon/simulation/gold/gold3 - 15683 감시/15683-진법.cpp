#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
typedef pair<int, int> pii;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board1[10][10];
int board2[10][10];
vector<pii> cctv;
int mn = INT_MAX;
int n, m;

// dir = 방향 -> 0: 오, 1: 위, 2: 왼, 3: 아래
void navigate(int x, int y, int dir){
    dir %= 4; // dir이 4 넘을 수 있으므로 보정
    while(true){
        x += dx[dir];
        y += dy[dir];
        if(x < 0 || x >= n || y < 0 || y >= m) break;

        int nxt = board2[x][y];
        if(nxt == 6) break;
        else if(nxt == 0) board2[x][y] = -1;
        else if((nxt >= 1 && nxt <= 5) || nxt == -1) continue;
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &board1[i][j]);
            if(board1[i][j] != 0 && board1[i][j] != 6) cctv.push_back({i, j});
        }
    }

    // 가능한 조합 모두 탐색 4^cctv.size()
    // tmp라는 숫자는 모든 cctv의 방향 정보를 담고 있음
    for(int tmp=0; tmp<(1 << (2 * cctv.size())); tmp++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                board2[i][j] = board1[i][j];
            }
        }
            
        int brute = tmp;

        for(int i=0; i<cctv.size(); i++){
            int dir = brute % 4;
            brute /= 4;
            int x = cctv[i].first;
            int y = cctv[i].second;
            
            int cur = board2[x][y];
            if(cur == 1){
                navigate(x, y, dir);
            }else if(cur == 2){
                navigate(x, y, dir);
                navigate(x, y, dir+2);
            }else if(cur == 3){
                navigate(x, y, dir);
                navigate(x, y, dir+3);
            }else if(cur == 4){
                navigate(x, y, dir);
                navigate(x, y, dir+1);
                navigate(x, y, dir+3);
            }else if(cur == 5){
                navigate(x, y, dir);
                navigate(x, y, dir+1);
                navigate(x, y, dir+2);
                navigate(x, y, dir+3);
            }
        }
        int sum = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board2[i][j] == 0) sum++;
            }
        }
        mn = min(mn, sum);
    }

    printf("%d", mn);
}