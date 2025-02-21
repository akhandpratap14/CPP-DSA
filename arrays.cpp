#include<iostream>
#include <vector>

using namespace std;


int largestElement(vector<int> arr){
    int max = -1;
    for(int i = 0; i <= arr.size(); i++){
        if(arr[i] > max){
            max = arr[i];
        }   
    }
    return max;
}
int secondLargestElement(vector<int> arr){
    int sec_max = -1;
    int max = -1;
    for(int i = 0; i <= arr.size(); i++){
        if(arr[i] > sec_max){
            if(arr[i] > max){
                max = arr[i];
            }  
            if(arr[i] < max){
                sec_max = arr[i];
            }
        }   
    }
    return sec_max;
}



int main(){

    vector<int> arr;

    arr.push_back(23);
    arr.push_back(12);
    arr.push_back(45);
    arr.push_back(34);
    arr.push_back(89);
    arr.push_back(32);
    arr.push_back(76);
    arr.push_back(21);

    cout << "Largest Value : " << secondLargestElement(arr) << endl;

    return 0;
}