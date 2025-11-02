/*
Header for spatial tree implementation for the broadphase collision detection
Author: Isaac Abella
Date: October 20, 2025
Description: Fully implemented AABB Tree for spatial partitioning
*/

#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <mdspan>
#include <random>
#include <vector>

/*namespace shapes
{
class AABB
{
public:
    AABB();
    ~AABB();

private:
    // members and tests for the AABB & other shapes
    void get_surface_points();
    void get_surface_area();
    void get__surface_volume();
    void get_center_point();
};

namespace s_node
{
class Node
{
public:
    // set node data members and methods
    bool is_leaf() const;
    void set_left(Node *node);
    void set_right(Node *node);
    void update_data(int val);
    Node *get_sibling() const;
    Node *insert_recursive(int val);

private:
    // private node structure
    struct CN
    {
        int data;
        Node *left;
        Node *right;
        CN(int val) : data(val), left(nullptr), right(nullptr) {}
    };
    CN *root;
};

class Edge
{
public:
private:
};
} // namespace s_node

namespace s_tree
{
// coming full circle to implement a KDTree for spatial partitioning!
template <typename coordinates, ssize_t Dimensions> class Point
{
public:
}; // namespace s_tree
} // namespace s_tree
} // namespace shapes */
