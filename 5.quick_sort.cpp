#include<iostream>
#include<vector>
using namespace std;

int division(vector<int>&lis, int left, int right){
    int base = lis[left];
    while(left < right){
        while(left < right && lis[right] >= base){ //��β�˴��������������С��base����
            right--;
        }
        lis[left] = lis[right];
        while(left < right && lis[left] <= base){  //��β�˴������ұ������Ҵ���base����
            left++;
        }
        lis[right] = lis[left];
    }
    lis[left] = base;                              //ǰ��ָ������
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
    cout << "����ǰ" <<endl;
    for (int i = 0; i < lis.size(); i++){
        cout << lis[i] << " ";
    }
    cout << endl;
    QuickSort0(lis, 0, lis.size() - 1);
    cout << "�����" << endl;
    for (int i = 0; i < lis.size(); i++){
        cout << lis[i] <<" ";
    }
    cout << endl;
    return 0;
}
