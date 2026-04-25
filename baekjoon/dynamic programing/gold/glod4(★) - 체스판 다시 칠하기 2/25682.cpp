#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> board;
int start_b[2002][2002];
int start_w[2002][2002];
int dp_b[2002][2002];
int dp_w[2002][2002];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    string str;
    for(int i=0; i<n; i++){
        cin >> str;
        board.push_back(str);
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if((i+j)%2 == 0){ // 시작이랑 같음
                if(board[i-1][j-1] != 'B') start_b[i][j] = 1; // b로 시작
                if(board[i-1][j-1] != 'W') start_w[i][j] = 1; // w로 시작
            }else{ // 시작이랑 다름
                if(board[i-1][j-1] != 'W') start_b[i][j] = 1;
                if(board[i-1][j-1] != 'B') start_w[i][j] = 1;
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            dp_b[i][j] = start_b[i][j] + dp_b[i][j-1] + dp_b[i-1][j] -dp_b[i-1][j-1];
            dp_w[i][j] = start_w[i][j] + dp_w[i][j-1] + dp_w[i-1][j] -dp_w[i-1][j-1];
        }
    }

    int mn = 4000002;
    for(int i=1; i<=n; i++){
        if(i+k-1 > n) break;
        for(int j=1; j<=m; j++){
            if(j+k-1 > m) break;
            int b = dp_b[i+k-1][j+k-1] - dp_b[i+k-1][j-1] - dp_b[i-1][j+k-1] + dp_b[i-1][j-1];
            int w = dp_w[i+k-1][j+k-1] - dp_w[i+k-1][j-1] - dp_w[i-1][j+k-1] + dp_w[i-1][j-1];
            mn = min(mn, min(b, w));
        }
    }
    cout << mn;
}