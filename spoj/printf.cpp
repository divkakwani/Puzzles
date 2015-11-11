
#include <bits/stdc++.h>

using namespace std;

/* Author: Divyanshu Kakwani */

/** Boilerplate */

// type aliases
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;      // for unweighted graph
typedef vector< vector< ii > > vvii;    // for weighted graph


// Constants
#define INF(T) numeric_limits<T>::max()

// Shorthands for frequently occuring code
#define rep(i, a, b)    for(int i = (a); i < (b); i++)
#define inpN(a, n)      rep(hZxWQ, 0, n) cin >> a[hZxWQ]; 
#define fill(a, v)      (memset(a, v, sizeof a))
#define in(a, b)        ((b).find(a) != (b).end())
#define max(a, b)       ((a) > (b) ? (a) : (b))
#define min(a, b)       ((a) < (b) ? (a) : (b))
#define isInt(a)        int(a) == (a) ? true : false
#define el              cout << endl;
#define mp              make_pair

#define DEBUG

// Debugging macros
#ifdef DEBUG
#define show(x)         cerr << #x << ": " << x << endl;
#define showCont(C)     cerr << "Contents of " #C; el \
                        for(auto& elt : C) { cerr << elt << "\t";} el
#define stop            exit(-123);
#else
#define show(x) 
#define showCont(C)
#define stop
#endif

// Miscellaneous
#define nosync ios_base::sync_with_stdio(0);


int main() {
    nosync;

    int t;
    cin >> t;

    while(t--) {
    
        string s;
        cin >> s;

        int pos = s.find('\"');
        int pos2 = s.find('\"', pos+1);
        string format = s.substr(pos+1, pos2-pos);

        vector<int> types;
        vector<string> splits;
        int last_i = 0;
        for(int i = 0; i < format.length(); i++) {
            if(format[i] == '%') {
                splits.push_back(s.substr(last_i, i-1));
                ++i;
                if(format[i] == 'c')
                    types.push_back(1);
                else if(format[i] == 'd')
                    types.push_back(2);
                else if(format[i] == 'f')
                    types.push_back(3);
                else
                    types.push_back(4);
                last_i = i+1;
            }
        }
        splits.push_back(s.substr(last_i));

        string res;

        int index = pos2+1;
        int i = 0;
        while(1) {

            res += splits[i];
            // skip white-spaces
            while(s[index] == ' ') index++;
            // skip comma
            index++;
            // skip whitespaces
            while(s[index] == ' ') index++;
            
            switch(types[i]) {
                case 1:
                    index++;
                    char c = s[index];
                    res += string(c);
                    index++;
                    break;
                case 2:
                    int i = ::atoi(s.substr(index).c_str());

                    break;
                case 3:
                    break;
                case 4:
                    break;
            
            }
             
        }
    }


}
