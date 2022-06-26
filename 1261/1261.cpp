#include <iostream>
#include <queue>
#include <inttypes.h>

using namespace std;

int map[100][100];
int dist[100][100];
int dir_y[4] = {1, -1, 0, 0};
int dir_x[4] = {0, 0, 1, -1};

queue<pair<int,int>> moveq;

int main(){
    int n=0, m=0, x=0;
    cin >> m >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &map[i][j]);
        }
    }

    // dist는 최대 값으로 초기화
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            dist[i][j] = (n*m);
        }
    }
    
    moveq.push({0, 0});
    dist[0][0] = 0;

    while(!moveq.empty()){

        int cur_x = moveq.front().first;
        int cur_y = moveq.front().second;

        moveq.pop();

        // 상하좌우 이동
        for(int i=0; i<4; i++){
            int nt_x = cur_x + dir_x[i];
            int nt_y = cur_y + dir_y[i];
        
            if( nt_x < 0 || nt_y < 0 || nt_x >= m || nt_y >= n){
                continue;
            }

            // 거리 가중치 업데이트
            int cur_dist = 0;
            if(map[nt_y][nt_x] == 1){
                cur_dist = dist[cur_y][cur_x]+1;
            }
            else if(map[nt_y][nt_x] == 0){
                cur_dist = dist[cur_y][cur_x];
            }

            if(dist[nt_y][nt_x] > cur_dist){
                dist[nt_y][nt_x] = cur_dist;
                moveq.push({nt_x, nt_y});
            }
        }
        
    }
    

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dist[n-1][m-1];

}

