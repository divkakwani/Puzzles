
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

typedef string grid;

int result(const grid& g) {
    // return 1 if X wins, return -1 if X loses, return 0 if drawn or undecided 
    if((g[0] == 'x' and g[1] == 'x' and g[2] == 'x') or
       (g[3] == 'x' and g[4] == 'x' and g[5] == 'x') or
       (g[5] == 'x' and g[6] == 'x' and g[7] == 'x') or 
       (g[0] == 'x' and g[3] == 'x' and g[6] == 'x') or
       (g[1] == 'x' and g[4] == 'x' and g[7] == 'x') or
       (g[2] == 'x' and g[5] == 'x' and g[8] == 'x') or
       (g[0] == 'x' and g[4] == 'x' and g[8] == 'x') or
       (g[2] == 'x' and g[4] == 'x' and g[6] == 'x'))
        return 1;
    
    if((g[0] == 'o' and g[1] == 'o' and g[2] == 'o') or
       (g[3] == 'o' and g[4] == 'o' and g[5] == 'o') or
       (g[6] == 'o' and g[7] == 'o' and g[8] == 'o') or 
       (g[0] == 'o' and g[3] == 'o' and g[6] == 'o') or
       (g[1] == 'o' and g[4] == 'o' and g[7] == 'o') or
       (g[2] == 'o' and g[5] == 'o' and g[8] == 'o') or
       (g[0] == 'o' and g[4] == 'o' and g[8] == 'o') or
       (g[2] == 'o' and g[4] == 'o' and g[6] == 'o'))
        return -1;
    
    for(int i = 0; i < 9; i++)
        if(g[i] == '.')
            return -100;

    return 0;
}

unordered_map<grid, int> states; 

int play_game(const grid& init, bool xturn) {
    int score = 0, final_score;
    final_score = xturn ? -1000 : 1000;

    int res = result(init);
    if(res != -100) {
        states.insert(make_pair(init, res));
        return res;
    }

    for(int i = 0; i < 9; i++) {
        if(init[i] == '.') {
            grid g = init;
            g[i] = xturn ? 'x' : 'o';
            score = play_game(g, !xturn);
            
            // minimax - X seeks to maximize his score; O seeks minimization
            if(xturn)
                final_score = max(final_score, score);
            else
                final_score = min(final_score, score);
        }
    }
    states.insert(make_pair(init, final_score));
    return final_score;
}

bool valid(const grid& g, bool xturn) {

    
    int res = result(g);
    grid temp = g;
    for(int i = 0; i < 9; i++)
        if(g[i] == 'x')
            temp[i] = '.';
    int res2 = result(temp);
    if(res == 1 and res2 == -1)
        return false;

    
    int ocnt = 0, xcnt = 0;
    for(int i = 0; i < 9; i++)
        if(g[i] == 'x')
            xcnt++;
        else if(g[i] == 'o')
            ocnt++;

    if(xturn and ocnt == xcnt)
        return true;
    if(!xturn and xcnt == ocnt+1)
        return true;
    
    return false;
}

int main() {
    nosync;

    grid init = {'.', '.', '.', '.', '.', '.', '.', '.', '.'};
    play_game(init, true);

    ll t;
    cin >> t;

    while(t--) {
        grid g = ".........";
        for(int i = 0; i < 9; i++) {
            cin >> g[i];
        }
        bool xturn = valid(g, true);
        if(!xturn and !valid(g, false)) {
            cout << "invalid" << endl;
            continue;
        }
        bool vld = (states.find(g) != states.end());
        if(!vld) {
            cout << "invalid" << endl;
            continue;
        }
        int res =  states[g];
        if((res == 1 and xturn) or (res == -1 and !xturn))
            cout << "win" << endl;
        else if ((res == 1 and !xturn) or (res == -1 and xturn))
            cout << "lose" << endl;
        else
            cout << "tie" << endl;
    
    }

}
