// Advanced Data structrue -- Suffix Trees

/*
*****************************
Name: Isaac Abella
Netid: iabella
ID: 000641840

Description: Create a tree data structure which stores a string and all of the possible substrings of that string into a tree. 

The benefits is that you can have fast insertions and lookup of possible substrings. This can solve things like the longest
common subsequence problem of strings extremely fast since it's almost linear in time. 

The downside to this data structure is that the actual storing of the substrings requires more memory in tradeoff of the faster
times that you get from implementing this data structure.

Solution: Create a suffix tree to find the substring matches as fast as possible
*****************************
*/

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// node of tree
struct Node{
    unordered_map<char, Node*> child;
    int start;
    int* end;
    int Suffix_Index;

    Node (int start, int* end) : start(start), end(end), Suffix_Index(-1) {}
};

// create suffix tree
class tree{
public:
    Node* root;
    std::string text; // input string to store

    tree(const std::string& str){
        // create the essentials of the tree
        text = str;
        int n = text.length();

        root = new Node(-1, new int(-1));
        build_tree(n);
    }

    void build_tree(int n);             // creates tree of n length
    void search(const string& pattern); // searches for patterns
    void free_tree(Node* node);         // memory cleanup
};

// dynamic memory allocation
void tree::free_tree(Node* node){
    for(auto & child : node->child){
        free_tree(child.second);
    }
    delete node->end;
    delete node;
}


