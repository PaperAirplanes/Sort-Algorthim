#include<iostream>
#include<vector>
using namespace std;
// reference Jack Cui 2018-4-25
int MaxBit(vector<int> &lis){
    int max_data = lis[0];
    for (int i = 1; i < lis.size(); i++){
        if(lis[i] > max_data){
            max_data = lis[i];
        }
    }
    int bits_max = 0;
    while(max_data){
        bits_max++;
        max_data /= 10;
    }
    return bits_max;             //返回最大值的最大位数
}

int digit(int num, int d){
    int pos = 1;
    while(--d > 0){
        pos *= 10;
    }
    return (num / pos) % 10;     // 返回数值num的第d位上的数值
}

vector<int> RadixSort(vector<int> &lis){
    int n = lis.size();
    vector<int> temp(n);
    vector<int> number(10);
    for (int k = 1; k <= MaxBit(lis); k++){
        for (int i = 0; i < 10; i++){
            number[i] = 0;
        }
        for (int i = 0; i < n; i++){
            number[digit(lis[i], k)]++;
        }
        for (int i = 1; i < 10; i++){
            number[i] += number[i - 1];
        }
        for (int i = n - 1; i >= 0; i--){  //从后往前进行遍历
            int m = digit(lis[i], k);      //判断当前位数的值
            temp[number[m] - 1] = lis[i];  //在当前位数值的容器末尾添加
            number[m]--;                   //在每个小容器内都是逐渐向前填满
        }
        for (int i = 0; i < n; i++) {
            lis[i] = temp[i];
        }
        cout <<"第"<< k <<"趟排序：";
        for(int i = 0; i < lis.size(); i++){
            cout << lis[i] <<" ";
        }
        cout <<endl;
    }
    return lis;
}
int main(){
    int ted;
    vector<int> lis;
    while(cin >> ted) {
        lis.push_back(ted);
    }
    cout << "排序前" <<endl;
    for (int i = 0; i < lis.size(); i++){
        cout << lis[i] << " ";
    }
    cout << endl;
    vector<int> result = RadixSort(lis);
    cout << "排序后" << endl;
    for (int i = 0; i < result.size(); i++){
        cout << result[i] <<" ";
    }
    cout << endl;
    return 0;
}
