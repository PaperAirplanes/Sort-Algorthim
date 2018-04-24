#include<iostream>
#include<vector>
using namespace std;
//reference: Jack Cui
vector<int> SelectSort0(vector<int> &lis){
    vector<int> result = lis;
    for(int i = 0; i < result.size(); i++){
        int index = i;
        for (int j = i + 1; j < result.size(); j++){
            if(result[index] > result[j]){
                index = j;       // index�������浱ǰ����Сֵ
            }
        }
        int temp = result[index];  //����i��index��ֵ
        result[index] =  result[i]; // Ҳ����ʹ��swap(result[i], result[index])
        result[i] = temp;
        cout << "�� " << i + 1 <<" ������: " ;
        for(int k = 0; k < result.size(); k++){
            cout << result[k] <<" ";
        }
        cout <<endl;
    }
    return result;
}

int main(){
    int ted;
    vector<int> arr;
    while(cin >> ted) {
        arr.push_back(ted);
    }
    cout << "����ǰ" <<endl;
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout<<endl;
    vector<int> result = SelectSort0(arr);
    cout << "�����" << endl;
    for (int i = 0; i < result.size(); i++){
        cout << result[i] <<" ";
    }
    cout << endl;
    return 0;
}
