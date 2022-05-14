https://docs.google.com/spreadsheets/d/1AvttpBj-JnxFurMzu8Vi0QnxEKD66nhPbTUZIMFhWaw/edit#gid=0
#include <vector>
using namespace std;

int buyTicket(int *arr, int n, int k) {
    priority_queue<pair<int,int>>q;
    for(int i =0 ; i<n ; i++){
        q.push({arr[i],-i});
    }

int count =0;
while(q.size()!=0 ){
    
    if(q.top().second == -k){
        count++;
        break;
    }
    else if(q.top().first <arr[k]){
        q.pop();
    }
    else{
        count++;
        q.pop();
    }
}
return count;
}


int main() {
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << buyTicket(arr, n, k);

    delete[] arr;
}