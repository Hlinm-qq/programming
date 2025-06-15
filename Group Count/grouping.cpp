#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main(){
    string str;
    int alpha[27];
    int t, n;
    int group, number;
    int curr_g, exist_g;
    cin >> t;
    while(t--){
        group = 0, number = 1;
        memset(alpha, 0, sizeof(alpha));
        cin >> n;
        for(int i=1; i<=n; i++){
            curr_g = exist_g = 0;
            cin >> str;
            group++;
            for(int j=0; j<str.length(); j++){
                if(alpha[(int)str[j] - (int)'a' + 1]){
                    exist_g = alpha[(int)str[j] - (int)'a' + 1];
                    if(!curr_g){
                        curr_g = exist_g, group--;
                    }
                }
                if(curr_g != exist_g && curr_g){
                    group--;
                    for(int k=1; k<=26; k++){
                        if(alpha[k] == exist_g) alpha[k] = curr_g;
                    }
                }
            }
            for(int j=0; j<str.length(); j++){
                alpha[str[j] - 'a' + 1] = (curr_g) ? curr_g : i;
            }
        }
        cout << group << endl;
    }
}