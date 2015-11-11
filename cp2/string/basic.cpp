#include <bits/stdc++.h>

using namespace std;



int main() {

    string res;
    string delim(7, '.');
    res.reserve(1000);

    string output;

    while(getline(cin, res)) {
    
        if(res.substr(0, 7) == delim)
            break;
        output += res;
        output += " ";
    }

    output.erase(output.size() - 1, 1);
    
    transform(output.begin(), output.end(), output.begin(), ::tolower);

    stringstream ss(output);
    map<string, int> freq;
    set<string> tokens;
    
    while(ss >> res) {
        tokens.insert(res);
        freq[res]++;
    }

    cout << "Smallest: " <<*tokens.begin() << endl;
    cout << *max

    cout << output << endl;

}
