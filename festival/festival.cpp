#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n_test_case = 0;
  cin >> n_test_case;

  vector<double> answer_vec;

  for (int i = 0; i < n_test_case; i++)
  {
    // 공연장 대여 가능한 일수 , 이미 섭외한 공연팀의 수 입력.
    int n_day = 0, n_team = 0;
    cin >> n_day >> n_team;

    vector<int> cost_vec;
    // 공연장 대여비용이 대여가능일수만큼 입력됨.
    for (int j = 0; j < n_day; j++)
    {
      int cost;
      cin >> cost;
      cost_vec.push_back(cost);
    }

    // cout << endl << endl;
    // 가능한 대여일 범위 구하기
    double min_avg__ = 100;
    for (int j = n_team; j <= n_day; j++)
    {
      // 대여 시작일 지정
      for (int begin=0; begin<n_day; begin++)
      {
        int begin_day_index = begin;
        int end_day_index = begin_day_index + j - 1;

        if (end_day_index < n_day)
        {
          // 평균 구하기
          double sum = 0.f;
          for (int n = begin_day_index; n <= end_day_index; n++)
          {
            sum += cost_vec[n];
          }

          sum = sum / j;
          // cout << i<<" Update: " << "n_day=" << j << "[" << begin_day_index << " " << end_day_index << "]"<< endl;
          if (min_avg__ > sum)
          {
            min_avg__ = sum;

          }
        }
      }
    }

    answer_vec.push_back(min_avg__);
  }

  cout << fixed;
  cout.precision(8);
  for (auto &&val : answer_vec)
  {
    cout << val << endl;
  }
}