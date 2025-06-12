#include <stdio.h>
#include <stdlib.h>

int bins(int* arr, int start, int end, int val){
    int mid;
    while(start <= end){
        mid = start + (end-start)/2;
        if(arr[mid] == val) return mid;
        if(arr[mid] < val) start = mid + 1;
        else end = mid -1;
    }
    return -1;
}

int main(){
    int n, q, val, temp;
    int * arrr = (int*) malloc(2000002 * sizeof(int));
    while (scanf("%d%d", &n, &q) != EOF){
        for(int i=1; i<=n; i++){
            scanf("%d", &arrr[i]);
        }
        while(q--){
            scanf("%d", &val);
            temp = bins(arrr, 1, n, val);
            if(temp == -1) printf("Break your bridge!\n");
            else printf("%d\n", temp);
        }
    }
    free(arrr);
}