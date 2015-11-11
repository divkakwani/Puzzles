
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


/* Grammar 
 *
 * Brackets -> bracket Brackets | epsilon
 * bracket  -> {index.nesting} (Brackets) | epsilon
 *
 */

string stream;
char lookahead;
int idx = 0;
int nesting[1000];
int braces[1000];

/* return nesting levels inside and no of brackets inside */
pair<int, int> bracket();
pair<int, int> Brackets();
void match(char);

ii Brackets() {
    if(lookahead == '(') {
        ii x = bracket(); 
        ii y = Brackets();
        return ii(max(x.first, y.first), x.second + y.second);
    }
    else {
        return ii(0, -1);
    }
}

ii bracket() {
    if(lookahead == '(') {
        match('('); 
        ii x = Brackets();
        braces[idx] = x.second+1;
        nesting[idx] = x.first+1;
        match(')');
        return ii(x.first + 1, x.second+1);
    }
    else
        return ii(0, -1);
}

void match(char c) {
    lookahead = stream[++idx];
}


int main() {
    nosync;

    cin >> stream;
    lookahead = stream[0];
    Brackets();

    show("nesting");

    for(int i = 0; i < stream.length(); i++)
        cout << i << ": " << nesting[i] << endl;

    show("Braces");

    for(int i = 0; i < stream.length(); i++)
        cout << i << ": " << braces[i] << endl;
}
