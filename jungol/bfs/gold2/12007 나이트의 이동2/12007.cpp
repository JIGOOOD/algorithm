#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int main(){
    int n, m, x, y, k;
    cin >> n >> m >> x >> y >> k;

    vector<vector<int>> board(4*k + 1, vector<int>(4*k + 1)); // 0 도달 불가, 1 도달 가능

    deque<pair<int, int>> q;
    q.push_back({x-1, y-1});

    long long res = (long long)n * m;
    int offset = 2*k;

    for(int t=1; t<=k; t++){
        int l = q.size();
        while(l--){
            auto [a, b] = q.front(); q.pop_front();

            for(int i=0; i<8; i++){
                int nx = a + dx[i];
                int ny = b + dy[i];

                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(board[nx-(x-1)+offset][ny-(y-1)+offset]) continue;
                board[nx-(x-1)+offset][ny-(y-1)+offset] = 1;
                if(t % 2 == k % 2) res -= 1;
                q.push_back({nx, ny});
            }
        }
    }

    cout << res;
}