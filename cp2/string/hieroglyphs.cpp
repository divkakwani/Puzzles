#include <bits/stdc++.h>

using namespace std;


int main() {

    int n;
    cin >> n;


    while(n--) {
    
        vector<string> matrix;
        string inp;

        for(int i = 0; i < 10; i++) {
            cin >> inp;
            matrix.push_back(inp);
        }
        int m = matrix[0].size() - 2;

        string message(80, ' ');
    
        int chr = 0;

        for(int i = 0; i < m; i++) {
            chr = 0;

            for(int j = 8; j > 0; j--) {
            
                chr <<= 1;
                if(matrix[j][i+1] != '/')
                    chr = chr | 1;
            }

            message[i] = chr;
        
        }


        cout << message.substr(0, m) << endl;


    }

}
