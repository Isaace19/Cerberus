/*
Name: Isaac Abella
Description: Implementing my very own KDTREE!!!! Yippie!!!!

I want to jump into the fire and create a higher dimension non-euclidian space
sorting data structure
*/

#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <random>
#include <vector>

// starting with a spherical kdtree before dipping into non-euclidian spaces

// so I must build my kdtree to split planes in latitude and longitudinal direction

class Node
{
public:
    int data;
    Node *right;
    Node *left;
};

class KDTree
{
private:
    Node *root;

public:
    KDTree();
    void construct_tree(std::vector<int> &points);
};
