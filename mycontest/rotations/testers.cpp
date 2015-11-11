
#include <bits/stdc++.h>

using namespace std;


inline int modulo (int n, int m) {
    return ((n % m) + m) % m;
}

int main() {
    
   int t;
   cin >> t;

   while (t--) {
   
        string s;
        int lt_rots, rt_rots, queries, index;

        cin >> s >> lt_rots >> rt_rots >> queries;


        /* 
         * The problem boils down to this: given an index
         * x into the rotated string, where does it lie in 
         * the original string?
         * 
         * Firstly, note that the index of the first char
         * of the string prior to the rotations is 0.
         * Every left rotation causes the starting index to
         * increment and every right rotation causes it to
         * decrement.
         * eg: Original string: abcd; start index = 0;
         *                      ^
         *     One-left rotation: abcd; start index = 1;
         *                         ^
         * So, after `l` left rotations and `r` right rotations,
         * the index of the first character is (0 + l - r).
         *
         * Consider the indices as a ring:
         *                  0  <--
         *              11       1
         *          10              2
         *      9                       3
         *          8               4
         *              7       5
         *                  6
         *
         * After each rotation, the arrow moves clockwise (if left-rotation) or 
         * counter-clockwise (if right-rotation).
         * As seen previously, the start index = (0 + l - r) which corresponds
         * to (0 + l -r) mod (|S|) in the ring.
         *
         *
         */
        int start = modulo(0 + lt_rots - rt_rots, s.length());
        
        while (queries--) {
            cin >> index;
            cout << s[modulo(start + index, s.length())] << endl; 
        }
   }

}
