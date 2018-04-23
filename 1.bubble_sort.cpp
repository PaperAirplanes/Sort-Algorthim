#include<iostream>
#include<vector>
using namespace std;
vector<int> bubblesort(vector<int> & lis){
    vector<int> result;
    if(lis.empty()) {
        return result;
    }
    result = lis;
    int temp;
    for (int i = 0; i < result.size()-1; i++){
        cout << "µÚ" << i + 1 <<"ÌËÅÅÐò:" <<endl;
        for(int j = 0; j < result.size() - 1; j++){
            if (result[j + 1] < result[j]){
                temp = result[j + 1];
                result[j + 1] = result[j];
                result[j] = temp;
            }
            cout << "ÅÅÐòÖÐ£º";
            for(int s = 0; s < result.size(); s++){
                cout << result[s] << " ";
            }
            cout << endl;
        }
        cout << "ÅÅÐò½á¹û£º";
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
    cout << endl;
    vector<int> result = bubblesort(arr);
    cout << "ÅÅÐòºó" << endl;
    for (int i = 0; i < result.size(); i++){
        cout << result[i] <<" ";
    }
    cout << endl;
    return 0;
}
