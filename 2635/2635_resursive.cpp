#include <iostream>
#include <vector>
using namespace std;

int generate(short n1, short n2, vector<unsigned short>& result)
{
    short res = n1 - n2;
    if(res > 0){

        result.push_back(res);
        return generate(n2, res, result);
    }
}

int main()
{
    short begin = 0;
    cin >> begin;

    int length_max = 0;
    vector<unsigned short> result_max;
    
    for(short second=1; second<begin; second++){
        vector<unsigned short> result;
        result.push_back(begin);
        result.push_back(second);

        generate(begin, second, result);

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