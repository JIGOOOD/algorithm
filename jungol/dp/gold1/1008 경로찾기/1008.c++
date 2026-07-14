#include <iostream>
#include <algorithm>
#include <deque>
#include <tuple>

using namespace std;

int dist[102][102];
int board[102][102];
int inf = 100000002;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;
    cin >> n >> t;

    int st_x, st_y;
    int en_x, en_y;

    // dist 배열 초기화
    fill(&dist[0][0], &dist[0][0] + 102 * 102, inf);

    // board 입력
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
            if(board[i][j] == -1){
                st_x = i;
                st_y = j;
                board[i][j] = 0;
            }else if(board[i][j] == -2){
                en_x = i;
                en_y = j;
                board[i][j] = 0;
            }
        }
    }

    // 최솟값 갱신
    deque<tuple<int, int, int>> dq;
    dist[st_x][st_y] = 0;
    dq.push_back({st_x, st_y, 0});

    for(int time=1; time<=t; time++){
        int len = dq.size();
        for(int i=0; i<len; i++){
            int x, y, w;
            tie(x, y, w) = dq.front(); dq.pop_front();

            for(int dir=0; dir<4; dir++){
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if(board[nx][ny] == 0 && !(nx == en_x && ny == en_y)) continue;

                if(dist[nx][ny] > dist[x][y] + board[nx][ny]){
                    dist[nx][ny] = dist[x][y] + board[nx][ny];
                    dq.push_back({nx, ny, dist[nx][ny]});
                }
            }
        }
    }

    if(dist[en_x][en_y] == inf) cout << -1;
    else cout << dist[en_x][en_y];
}