#include <bits/stdc++.h>
using namespace std;
#include<vector>
void findMedian(int *arr, int n)   
{ 
    vector<int>v;
    for(int i=0; i<n ; i++){
        v.push_back(arr[i]);
         sort(v.begin(), v.end());
        if(i%2==0){
            cout<<v[i/2]<<" ";
        }
        else{
            cout<<(v[i/2] +v[(i/2)+1])/2<<" ";
        }
    }
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    findMedian(arr,n);

    delete[] arr;
}
