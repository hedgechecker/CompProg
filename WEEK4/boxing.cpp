#include <bits/stdc++.h>
using namespace std;

int w, h;
vector<vector<int>> board;
int x,y;

int checkValid(tuple<int,int> t){
    int y = get<0>(t);
    int x = get<1>(t);
    if(y < 0 || y >= h || x < 0 || x>= w){
        return 0;
    }
    if(board[y][x] == -1){
        return 1;
    }else if(board[y][x] == -99){
        return -1;
    }
    return 0;
}

void getPos(tuple<int,int> t, list<tuple<int,int>> &l){
    int y = get<0>(t);
    int x = get<1>(t);
    l.push_back({y+1,x+2});
    l.push_back({y-1,x+2});
    l.push_back({y+1,x-2});
    l.push_back({y-1,x-2});
    l.push_back({y+2,x+1});
    l.push_back({y+2,x-1});
    l.push_back({y-2,x+1});
    l.push_back({y-2,x-1});
}

void printMoves(queue<tuple<int,int>> &knights, int val){
    tuple<int,int> curr;
    while(!knights.empty()){
        list<tuple<int,int>> l;
        curr = knights.front();
        knights.pop();
        
        master: getPos(curr, l);
        for(auto i: l){
            int y = get<0>(i);
            int x = get<1>(i);
            if(y < 0 || y >= h || x < 0 || x>= w){}
            else if(board[y][x] == val){
                cout << (h-1)-get<0>(curr)+1 << " " << get<1>(curr)+1  << " " << (h-1)-y+1 << " " << x+1 << endl;
                curr = {y,x};
                val--;
                if(val < 0){
                    return;
                }else{
                    goto master;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> w;
    cin >> h;
    board.assign(h,vector<int>(w));
    char c;
    queue<tuple<int,int>> que;
    queue<tuple<int,int>> knights;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> c;
            if(c == 'k'){
                y = i;
                x = j;
                board[i][j] = 0;
                que.push({i,j});
            }else if( isupper(c) != 0){
                if(c == 'N'){
                    knights.push({i,j});
                    board[i][j] = -99;
                }else{
                    board[i][j] = -9;
                }
            }else{
                board[i][j] = -1;
            }
        }
    }

    int val;
    while(!que.empty()){
        tuple t = que.front();
        val = board[get<0>(t)][get<1>(t)];
        que.pop();

        list<tuple<int,int>> l;
        getPos(t, l);
        for(auto i : l){
            int ch = checkValid(i); 
            if(ch == 1){
                board[get<0>(i)][get<1>(i)] = val +1;
                que.push(i);
            }else if(ch == -1){
                cout << "Checkmate in " << val +1 << endl;
                goto skip;
            }
        }
    }
    cout << "Resign" << endl;
    return 0;


    skip:
    printMoves(knights, val);
    return 0;
}