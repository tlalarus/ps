#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> tokenize(string& src, const char delimiter=' '){
    vector<string> result;
    string token;
    stringstream ss(src);
    
    while(getline(ss, token, delimiter)){
        result.push_back(token);
    }
    return result;
}

int main()
{
    int n=0;
    cin >> n;
    
    // 배열 크기 받아서 할당하기
    int** arr = new int*[n];
    int** integral = new int*[n];
    for(int i=0; i<n; i++){
        arr[i] = new int[n];
        integral[i] = new int[n];
        for(int j=0; j<n; j++){
            arr[i][j] = 0;
            integral[i][j] = 0;
        }
    }
    
    // int cnt = 0;
    // int rows = 0;
    // int cols = 0;
    // while(cnt < (n*n)){
    //     string input_str;
    //     getline(cin, input_str);
    //     vector<string> elements = tokenize(input_str);
    //     for(auto&& ele : elements){
    //         int intval = atoi(ele.c_str());
    //         if(intval < -127 || intval > 127){
    //             continue;
    //         }
    //         arr[rows][cols] = intval;
    //         cols++;
    //         if(cols == n){
    //             rows++;
    //         }
    //         cnt++;
    //     }
    // }
    
    int arr1[4][4] = {{0, -2, -7, 0 }, {9, 2, -6, 2}, {-4, 1, -4, 1}, {-1, 8, 0, -2}};

    cout << "Print array" << endl;
    // print arr
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;


    int x2=0, y2=0;
    int max = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i>0 && j>0){
                integral[i][j] = integral[i][j-1] + integral[i-1][j] + arr[i][j] - integral[i-1][j-1];
            } else if(i>0){
                integral[i][j] = integral[i-1][j] + arr1[i][j];
            } else if(j>0){
                integral[i][j] = integral[i][j-1] + arr1[i][j];
            } else if(i==0 && j==0){
                integral[i][j] = arr1[i][j];
            }
            if(integral[i][j] > max){
                max = integral[i][j];
                x2 = j;
                y2 = i;
            }
        }
    }
    
    cout << "Print integral" << endl;
    // print arr
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << integral[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    max = 0;
    for(int y=0; y<y2; y++){
        for(int x=0; x<x2; x++){
            int sum = integral[y2][x2] - integral[y][x2] - integral[y2][x] + integral[y][x];
            if(max < sum){
                max = sum;
            }
        }
    }

    int max_sum = 0;
    for(int y1=0; y1<n-1; y1++){
        for(int x1=0; x1<n-1; x1++){
            for(int y2=y1+1; y2<n; y2++){
                for(int x2=x2+1; x2<n; x2++){
                    int sum = integral[y2][x2] - integral[y1][x2] - integral[y2][x1] + integral[y1][x1];
                                    
                    if(max_sum < sum){
                        max_sum = sum;
                    }
                }
            }
        }
    }
    
    cout << max_sum << endl;
    
}