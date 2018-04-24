#include<iostream>
#include<vector>
using namespace std;

vector<int> directInsertSort0(vector<int> &lis){
    vector<int> result;
    result = lis;
    for (int i = 1; i < result.size(); i++){
        cout << "µÚ " << i <<" ÌËÅÅÐò: " ;
        int temp = result[i];
        int j = i - 1;
        while(j >= 0 && result[j] > temp) {
            result[j+1] = result[j];
            j--;
        }
        result[j + 1] = temp;

        for (int s = 0; s < result.size(); s++){
            cout << result[s] << " ";
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
    cout << "ÅÅÐòÇ°" <<endl;
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout<<endl;
    vector<int> result = directInsertSort0(arr);
    cout << "ÅÅÐòºó" << endl;
    for (int i = 0; i < result.size(); i++){
        cout << result[i] <<" ";
    }
    cout << endl;
    return 0;

}
