#include <iostream>
#include <algorithm>
using namespace std;
#define np long long int

np bs(np*data, np l, np r, np x){
    int mid;
    while(l<=r){
        mid = l+ (r-l)/2;
        if(data[mid] == x) return mid;
        else if(data[mid] < x) l = mid+1;
        else r = mid -1;
    }
    return -1;
}

int main(){
    np n, a, q, x, unique_num, ans, index;
    np data[100005], data_single[100005], data_total[100005];
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> data[i];
    }
    sort(data, data+n);
    data_single[0] = -1;
    for(int i=0, j=0; i<n; i++){
        if(data[i] != data_single[j]){
            j++;
            data_single[j] = data[i];
            data_total[j] = 1;
        }
        else{
            data_total[j]++;
        }
        unique_num = j;
    }
    cin >> q;
    while(q--){
        cin >> x;
        index = bs(data_single, 1, unique_num, x);
        ans = 0;
        if(index != -1){
            ans = data_total[index];
        }
        cout << ans << endl;
    }
}