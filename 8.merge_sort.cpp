#include<iostream>
#include<vector>
using namespace std;
// reference Jack Cui 2018-4-25
void Merge(vector<int> &lis, int left, int mid, int right, vector<int>&temp){
    int i = left;
    int j = mid + 1;
    int k = 0;
    while(i <= mid && j <= right){ // 比较这两段当前指针指向值
        temp[k++] = lis[i] <= lis[j] ? lis[i++] : lis[j++];
    }
    while(i <= mid){    // 第二段完，第一段未完，复制第一段后面剩余的
        temp[k++] = lis[i++];
    }
    while(j <= right){  // 第一段完，第二段未完，复制第二段后面剩余的
        temp[k++] = lis[j++];
    }
    k = 0;
    while(left <= right){ //将容器temp中复制到lis中
        lis[left++] = temp[k++];
    }
}

void MergeSort(vector<int> &lis, int left, int right, vector<int> &temp){
    if(left < right){
        int mid = (right + left) / 2;
        MergeSort(lis, left, mid, temp);
        MergeSort(lis, mid + 1, right, temp);
        Merge(lis, left, mid, right, temp);
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
    vector<int> temp(lis.size());
    MergeSort(lis, 0, lis.size(), temp);
    cout << "排序后" << endl;
    for (int i = 0; i < lis.size(); i++){
        cout << lis[i] <<" ";
    }
    cout << endl;
    return 0;
}
