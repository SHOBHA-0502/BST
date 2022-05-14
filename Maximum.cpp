#include<bits/stdc++.h>
using namespace std;

int highestFrequency(int arr[], int n) {
  map<int,int>m;
    for(int i=0 ; i<n ;i++){
        m[arr[i]]++;
    }
    int x =0;
    int ans;
    for(auto i : m){
       if(i.second >x){
        //    cout<< i.second<<"//"<<i.first<<"//";
           x = i.second;
           ans = i.first;
           
       } 
    }
    return ans;
    
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << highestFrequency(arr, n);

    delete[] arr;
}