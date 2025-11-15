#include <bits/stdc++.h>
using namespace std;
#define B(y, x) board[(y) * w + (x)]

const int dy[8] = {1,-1,1,-1,2,2,-2,-2};
const int dx[8] = {2,2,-2,-2,1,-1,1,-1};
vector<int> board;
int w,h;
struct P{int y, x;};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> w;
    cin >> h;
    board.assign(w*h,0);

    P start;
    vector<P> knights;
    char c;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> c;
            if(c == 'k'){
                start = {i,j};
                B(i,j) = 0;
            }else if(c == 'N'){
                knights.push_back({i,j});
                B(i,j) = -99; // Knight
            }else if( isupper(c)){
                B(i,j) = -9; // own piece
            }else{
                B(i,j) = -1; // empty
            }
        }
    }

    vector<P> q;
    q.reserve(h*w);
    q.push_back(start);
    int head = 0;

    int finalDist = -1;
    P solution{-1,-1};

    while(head < (int)q.size()){
        auto [y, x] = q[head++];
        int d = B(y,x);

        for(int i = 0; i < 8; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= h || nx < 0 || nx >= w)
                continue;
            int &cell = B(ny, nx);
            if (cell == -1) {
                cell = d + 1;
                q.push_back({ny, nx});
            } else if (cell == -99) {
                // found target knight
                finalDist = d + 1;
                solution = {ny, nx};
                cell = finalDist;
                cout << "Checkmate in " << finalDist << "\n";
                goto skip;
            }
        }
    }
    cout << "Resign" << "\n";
    return 0;

    skip:
    int need = finalDist;
    for (auto kpos : knights) {
        int ky = kpos.y;
        int kx = kpos.x;

        if (B(ky,kx) != need) continue;

        // follow path backwards
        int curY = ky, curX = kx;
        int want = need - 1;

        while (want >= 0) {
            bool moved = false;

            for (int m = 0; m < 8; m++) {
                int py = curY + dy[m];
                int px = curX + dx[m];

                if (py < 0 || py >= h || px < 0 || px >= w) continue;

                if (B(py,px) == want) {
                    // print move in required coordinate system
                    cout << (h - curY)     << " " << (curX + 1) <<
                            " " << (h - py) << " " << (px + 1) << "\n";

                    curY = py;
                    curX = px;
                    want--;
                    moved = true;
                    break;
                }
            }

            if (!moved) break; // safety; shouldn't occur
        }
    }

    return 0;
}