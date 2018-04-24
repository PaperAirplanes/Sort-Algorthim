#include<iostream>
#include<vector>
using namespace std;

int division(vector<int>&lis, int left, int right){
    int base = lis[left];
    while(left < right){
        while(left < right && lis[right] >= base){ //从尾端从右向左遍历，找小于base的数
            right--;
        }
        lis[left] = lis[right];
        while(left < right && lis[left] <= base){  //从尾端从左向右遍历，找大于base的数
            left++;
        }
        lis[right] = lis[left];
    }
    lis[left] = base;                              //前后指针相遇
    return left;
}
void QuickSort0(vector<int> &lis, int left, int right){
    if (left < right){
        int base_index = division(lis, left, right);
        QuickSort0(lis, left, base_index - 1);
        QuickSort0(lis, base_index + 1, right);
    }
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
    QuickSort0(lis, 0, lis.size() - 1);
    cout << "排序后" << endl;
    for (int i = 0; i < lis.size(); i++){
        cout << lis[i] <<" ";
    }
    cout << endl;
    return 0;
}
