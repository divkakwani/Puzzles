#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int inp[100000], t, n, i, j;
    int states[100000];
    cin >> t;
    while(t--) {
        cin >> n;
        for(i = 0; i < n; i++) {
            cin >> inp[i];
            states[i] = -20000; // - Infinity
        }
        states[0] = inp[0];
        for(i = 1; i < n; i++)
            if(states[i-1] + inp[i] > inp[i])
                states[i] = states[i-1] + inp[i];
            else
                states[i] = inp[i];
            
        cout << *max_element(states, states + n) << " ";
        
        for(i = 0; i < n; i++)
            states[i] = inp[i];
        
        for(i = 1; i < n; i++)
            for(j = 0; j < i; j++)
                if(states[j] + inp[i] > states[i])
                    states[i] = states[j] + inp[i];
  
        cout << *max_element(states, states + n) << endl;
        
    }
    return 0;
}

