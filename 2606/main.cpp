#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

bool pc_virus[100];
bool visit[100];

int pc_map[100][100];

int n_pc = 0;
int n_pair = 0;

void search_virus(int start_pc){
  queue<int> q;
  q.push(start_pc);

  visit[start_pc] = true;

  // 
  while(!q.empty()){
    int pc_a = q.front();
    q.pop();
    // cout << "Pop "<< pc_a << " PC " << endl;

    // a와 연결된 pc를 큐에 넣는다.
    for(int i=0; i<n_pc; i++){
      if(pc_map[pc_a][i] > 0){
        int pc_b = i;
      
        // 방문 안한것만 큐에넣는다.
        if(!visit[pc_b]){
          // cout << "Push " << pc_b << " PC" << endl;
          q.push(pc_b);
          visit[pc_b] = true;
          pc_virus[pc_b] = true;
          // cout << "Virus detect " << pc_b << endl;
        }
      }
    }
  }

}
int main(){
  
  fill(pc_virus, pc_virus+100, false);
  fill(visit, visit+100, false);
  for(int i=0; i<100; i++){
    memset(pc_map[i], 0, sizeof(int)*100);
  }

  cin >> n_pc;
  cin >> n_pair;

  for(int i=0; i<n_pair; i++){
    int pc1 = 0;
    int pc2 = 0;
    cin >> pc1 >> pc2;

    pc1 -= 1;
    pc2 -= 1;

    // 양방향 연결
    pc_map[pc1][pc2] = 1;
    pc_map[pc2][pc1] = 1;
  }

  // cout << "result " << endl;
  // for(int i=0; i<n_pc; i++){
  //   for(int j=0; j<n_pc; j++){
  //     cout << pc_map[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  search_virus(0);
  
  int virus_cnt = 0;
  // cout << endl << "result " << endl;
  for(int i=1; i< n_pc; i++){
    // cout << pc_virus[i] << " ";
    if(pc_virus[i]){
      virus_cnt++;
    }
  }


  // cout << endl;
  cout <<virus_cnt;
}

// bfs
