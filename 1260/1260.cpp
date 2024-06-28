//
// Created by minkyung on 24. 6. 24.
//
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;

vector<int> vec[1002];
vector<int> result_bfs;
vector<int> result_dfs;
bool visit[1002];

void bfs(int temp) {
  queue<int> q;
  q.push(temp);
  visit[temp] = true;

  while(!q.empty()) {
    int x = q.front();
    q.pop();
    result_bfs.push_back(x);

    // 정점 x 에 연결된 정점들 탐색
    for(int i=0; i<vec[x].size(); i++) {
      if(!visit[vec[x][i]]) {
        q.push(vec[x][i]);
        visit[vec[x][i]] = true;
      }
    }
  }

}

void dfs(int x) {
  visit[x] = true;
  result_dfs.push_back(x); // 탐색한 노드 저장

  for(int i=0; i<vec[x].size(); i++) {
    if(!visit[vec[x][i]]) {
      dfs(vec[x][i]);
    }
  }
}

int main()
{
  int n; // 정점의 개수
  int m; // 간선의 개수
  int v; // 탐색 시작 정점 번호

  cin >> n >> m >> v;

  //cout << n << " " << m << " " << v << endl;

  // 간선이 연결하는 두 정점의 번호 입력받기
  for(int i=0; i<m; i++) {
    int n1, n2;
    cin >> n1 >> n2;

    vec[n1].push_back(n2);
    vec[n2].push_back(n1);
  }

  for(int i=0; i<1002; i++) {
    sort(vec[i].begin(), vec[i].end()); // 낮은 숫자의 정점부터 탐색
  }

  bfs(v);
  memset(visit, false, sizeof(visit));
  dfs(v);

  for(int i=0; i<result_dfs.size(); i++) {
    cout << result_dfs[i] << " ";
  }
  cout << endl;

  for(int i=0; i< result_bfs.size(); i++) {
    cout << result_bfs[i] << " ";
  }
  cout << endl;

  return 0;

}