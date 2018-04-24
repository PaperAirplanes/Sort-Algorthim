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
        cout << "第 " << t <<" 次排序: " ;
        for (int i = gap; i < n; i++){      //从第二列的第一个元素开始进行排序
            int temp = result[i];
            int j = i - gap;                //比较的前一个元素
            while(j >= 0 && result[j] > temp){   //每一列进行插入排序
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
    cout << "排序前" <<endl;
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout<<endl;
    vector<int> result = ShellSort0(arr);
    cout << "排序后" << endl;
    for (int i = 0; i < result.size(); i++){
        cout << result[i] <<" ";
    }
    cout << endl;
    return 0;
}
