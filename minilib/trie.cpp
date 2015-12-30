
#include <iostream>
#include <array>
#include <bits/stdc++.h>

using namespace std;



struct node {
    node* children[26];
    node() { for(auto& c : children) c = nullptr; }
};


class Trie {
 private:
    node root;

 public:
    void insert_word(string s) {
        node* curr_node = &root;
        for (char ch : s) {
            int id = ch - 'a';
            if (curr_node->children[id] == nullptr)
                curr_node->children[id] = new node();
            curr_node = curr_node->children[id];
        }
    }

};

int main() {
    
}
