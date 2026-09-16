#include <iostream>
#include <deque>
#include <string>

using namespace std;

bool vis[300002];

int main(){
    string s;
    cin >> s;

    int res = 0;
    deque<int> a;
    deque<int> c;

    int n = s.size();
    for(int i=0; i<n; i++){
        if(s[i] == 'A') a.push_back(i);
        else if(s[i] == 'C') c.push_back(i);
    }

    for(int i=0; i<n; i++){
        if(s[i] == 'B'){
            if(!a.empty() && vis[a.front()]) a.pop_front();
            if(!c.empty() && (c.front() < i || vis[c.front()])) c.pop_front();

            if(a.empty() && c.empty()) break;
            else if(!a.empty() && c.empty()){
                if(a.front() > i) continue;
                vis[a.front()] = true;
                a.pop_front();
                vis[i] = true;
                res++;
            }else{
                vis[c.front()] = true;
                c.pop_front();
                vis[i] = true;
                res++;
            }
        }
    }

    cout << res;
}