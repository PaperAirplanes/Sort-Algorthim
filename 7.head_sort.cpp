#include<iostream>
#include<vector>
using namespace std;
// reference Jack Cui 2018-4-25
void HeadAdjust(vector<int> &lis, int parent, int length){
    int temp = lis[parent];
    int child = 2 * parent + 1;     // 获得左孩子
    while(child < length){
        if(child + 1 < length && lis[child] < lis[child + 1]) {
            child++;
        }
        if(temp >= lis[child]){
            break;
        }
        lis[parent] = lis[child];
        parent = child;    // 向下继续筛选比较
        child =  2 * parent + 1;
    }
    lis[parent] = temp;
}

vector<int> HeadSort0(vector<int> &lis){
    int len = lis.size();
    for(int i = len/2; i >= 0; i--){
        HeadAdjust(lis, i, len);
    }
    for(int i = len - 1; i > 0; i--){
        int temp = lis[i];
        lis[i] = lis[0];
        lis[0] = temp;
        HeadAdjust(lis, 0, i);
        cout <<"第"<< len - i <<"趟排序：";
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
    vector<int> result = HeadSort0(lis);
    cout << "排序后" << endl;
    for (int i = 0; i < result.size(); i++){
        cout << result[i] <<" ";
    }
    cout << endl;
    return 0;
}
