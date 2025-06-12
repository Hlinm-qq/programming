#include <stdio.h>
#include <stdlib.h>
#define lln long long int


int main(){
  	lln cae;
    lln n=0, q=0;
    while(scanf("%lld %lld", &n, &q) != EOF){
        lln * n_array = (lln *) malloc(2000005 * sizeof(lln ));
      	// lln n_array[2000005]={0};
        lln a=0, b=0;
        lln ha=0, hb=0;
     	lln max=0, temp=0;
        for(lln i= 1; i<=n; i++){
            scanf("%lld", &n_array[i]);
            n_array[i] += n_array[i-1];
        }
        while(q--){
            scanf("%lld %lld", &a, &b);
            if(a < b){
                temp = n_array[b] - n_array[a-1];
            }
            else if(a > b){
                temp = n_array[n] - n_array[a-1] + n_array[b];
            }
            else
                temp = n_array[a] - n_array[a-1];
            if (max < temp){ 
                max = temp;
                ha = a; hb = b;
            }
        }
        printf("Max_range: (%lld,%lld); Value: %lld\n", ha, hb, max);
        free(n_array);
    }    
}