#include <bits/stdc++.h>

using namespace std;

int reverse(int num){
    string s = to_string(num);
    reverse(s.begin(),s.end());
    int k = stoi(s);
    return k;
    
}

int main(){
    int n1,n2,k;
    cin>>n1>>n2>>k;
    int count =0;
    for(int i = n1; i<=n2; i++){
        int f = i - reverse(i);
        if(f%k ==0){
            count++;
        }
    }
    cout<<count;
}