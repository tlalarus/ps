#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    int nroom = 0;
    int nwork = 0;
    int nstone = 0;

    cin >> nroom >> nwork >> nstone;

    vector<int> nstone_req;

    for(int i=0; i<nroom; i++){
        int k = 0;
        cin >> k;
        nstone_req.push_back(k);
    }

    vector<pair<int,int>> working;
    for(int i=0; i<nwork; i++){
        int start, end;
        cin >> start >> end;
        // {start, end}
        working.push_back(pair<int,int>(start, end));
    }
    
    int sum = 0;
    for(auto&& ele : working){

        // 돌을 놓는다.

        // 필요한 돌 개수 합을 구한다.
        sum += nstone_req[ele.first];
    }

    if(sum > nstone)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;


    // 공사하는 개수가 0일경우
    // n개와 m개에 따라서 노드를 그려줌.

    // 최초생성: n개의 노드 생성
    // 마주보고 있는 

}