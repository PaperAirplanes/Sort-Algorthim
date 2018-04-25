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
    return bits_max;             //�������ֵ�����λ��
}

int digit(int num, int d){
    int pos = 1;
    while(--d > 0){
        pos *= 10;
    }
    return (num / pos) % 10;     // ������ֵnum�ĵ�dλ�ϵ���ֵ
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
        for (int i = n - 1; i >= 0; i--){  //�Ӻ���ǰ���б���
            int m = digit(lis[i], k);      //�жϵ�ǰλ����ֵ
            temp[number[m] - 1] = lis[i];  //�ڵ�ǰλ��ֵ������ĩβ���
            number[m]--;                   //��ÿ��С�����ڶ�������ǰ����
        }
        for (int i = 0; i < n; i++) {
            lis[i] = temp[i];
        }
        cout <<"��"<< k <<"������";
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
    cout << "����ǰ" <<endl;
    for (int i = 0; i < lis.size(); i++){
        cout << lis[i] << " ";
    }
    cout << endl;
    vector<int> result = RadixSort(lis);
    cout << "�����" << endl;
    for (int i = 0; i < result.size(); i++){
        cout << result[i] <<" ";
    }
    cout << endl;
    return 0;
}
