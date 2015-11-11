
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

/* #define DEBUG */

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

ll bfs(const string& s, const string& sub, ll idx){ 
    show(s);
    show(sub);
    char best;

    vector<int> vec;
    for(int i = 0; i < s.length() - sub.length()+1; i++)
        if(idx != i and s[i] >= sub[0])
            vec.push_back(i);

    ll len = 1;
    int flag = 0;


    while(len <= sub.length() and vec.size() > 1) {

        vector<int> new_vec;

        if(len > 1 and best > sub[len-2])
            flag = 1;

        best = 'z'+1;

        for(int index : vec) {
            show(index);
            show(s[index+len-1]);
            show(sub[len-1]);
            if(!flag and s[index + len - 1] >= sub[len - 1] and s[index+len-1] <= best)
                best = s[index+len-1];
            else if(flag)
                best = min(best, s[index+len-1]);
        }
        show(best);

        if(best == 'z'+1)
            return -2;
    
        for(int index : vec)
            if(s[index+len - 1] == best)
                new_vec.push_back(index);

        vec = std::move(new_vec);
        len++;
    }

    return vec.size() == 0 ? -2 : vec[0];
}

int main() {
    nosync;
        
    string s;
    cin >> s;

    ll q, idx, len;

    cin >> q;

    while(q--) {
        cin >> idx >> len;
        idx--;
        string sub = s.substr(idx, len);
        cout << bfs(s, sub, idx)+1 << endl;
    }
}
