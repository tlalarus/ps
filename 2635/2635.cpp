#include <iostream>
#include <vector>
using namespace std;

int main()
{
    short begin = 0;
    cin >> begin;

    vector<unsigned short> result_max;
    int length_max = 0;
    
    for(short second=1; second<=begin; second++){

        vector<unsigned short> result;
        result.push_back(begin);
        result.push_back(second);

        while(true){
            int n = result.size();
            short next = result[n-2] - result[n-1];
            if(next < 0){
                break;
            }
            result.push_back(next);
        }

        if(length_max < result.size()){
            length_max = result.size();
            result_max = result;
        }
    }    

    cout << length_max << endl;
    for(auto&& ele : result_max){
        cout << ele << " ";
    }
    
}