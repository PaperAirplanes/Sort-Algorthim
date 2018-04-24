#include<iostream>
#include<vector>
using namespace std;
//reference: Jack Cui
vector<int> ShellSort0(vector<int> &lis){
    vector<int> result = lis;
    int n = result.size();
    int t = 0;
    for(int gap = n >> 1; gap > 0; gap >>= 1){
        t++;
        cout << "�� " << t <<" ������: " ;
        for (int i = gap; i < n; i++){      //�ӵڶ��еĵ�һ��Ԫ�ؿ�ʼ��������
            int temp = result[i];
            int j = i - gap;                //�Ƚϵ�ǰһ��Ԫ��
            while(j >= 0 && result[j] > temp){   //ÿһ�н��в�������
                result[j + gap] = result[j];
                j -= gap;
            }
            result[j + gap] = temp;
        }
        for(int i = 0; i < result.size(); i++){
            cout << result[i] <<" ";
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
    vector<int> result = ShellSort0(arr);
    cout << "�����" << endl;
    for (int i = 0; i < result.size(); i++){
        cout << result[i] <<" ";
    }
    cout << endl;
    return 0;
}
