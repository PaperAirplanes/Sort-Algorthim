#include<iostream>
#include<vector>
using namespace std;

int IndexSearch(vector<int> &lis, int n){
    int left = 0;
    int right = n -1;
    int value = lis[n];
    while(left <= right){
        int middle = left + (right - left)/2;
        if (lis[middle] >= value) right = middle - 1;
        else left = middle + 1;
    }
    int indexInsert = left < n ? left : -1;
    return indexInsert;
}

vector<int> BinaryInsertSort0(vector<int> &lis){
    vector<int> result;
    result = lis;
    for (int i = 1; i < result.size(); i++){
        cout << "第 " << i <<" 次排序: " ;
        int indexInsert = IndexSearch(result, i);
        if (indexInsert != -1){
            int temp = result[i];
            int j = i - 1;
            while(j >= indexInsert){
                result[j+1] = result[j];
                j--;
            }
            result[j + 1] = temp;
        }
        for (int k = 0; k < result.size(); k++){
            cout << result[k] << " ";
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
    vector<int> result = BinaryInsertSort0(arr);
    cout << "排序后" << endl;
    for (int i = 0; i < result.size(); i++){
        cout << result[i] <<" ";
    }
    cout << endl;
    return 0;

}
