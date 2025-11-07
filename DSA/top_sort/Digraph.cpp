/*
Name: Isaac Abella
Netid: iabella
Student #: 000641840

Description: Construct a directed graph that can hold verticies, edges, weight, ids, and other node graph information.

 */

// Challenge 05: Graph Paths

#include <iostream>
#include <vector> // used for graph implementation
#include <string>
#include <unordered_map>

// use the stack for a dfs, and queue for a bfs
#include <stack>
#include <set>
#include <queue>

class Node; // use forward declaration to avoid compilation errors

// create an edge centric directed graph to store our nodes and edges
// Class edge manages the edges between nodes in our graph
class Edge
{
public:
    Node *source;
    Node *sink;
    int weight;
};

// Class Node is the node containing the id of the current node and the incoming
// and outgoing edges that connect it to it's neighbors if possible.
class Node
{
public:
    std::string id; // id is based on the source and sink
    std::vector<Edge *> in_edge;
    std::vector<Edge *> out_edge;

    Node(const std::string &id) : id(id) {}
};

class digraph
{
public:
    // We could make this an implementation without unordered map, but the memory mamagement
    // with manual pointers is rough/outdated. And the searching through a vector is linear.
    // Therefore using a map offers better mem. management and searching complexity.
    std::unordered_map<std::string, Node *> Nodes;
    std::vector<Edge *> Edges;

    // create a set of indegrees and verticies for our directed graph in order to run a topological sort

    ~digraph()
    {
        for (Edge *edge : Edges)
        {
            delete edge;
        }
        for (auto &pair : Nodes)
        {
            delete pair.second;
        }
    }

    // Helper function to find or create nodes by their id
    Node *initialize_node(const std::string &id)
    {
        if (Nodes.find(id) == Nodes.end())
        {
            Nodes[id] = new Node(id);
        }
        return Nodes[id];
    }

    // Add in edges for source and sink, creating new nodes if DNE
    void add_Edges(const std::string &source_id, const std::string &sink_id, int weight = 0)
    {
        Node *source = initialize_node(source_id);
        Node *sink = initialize_node(sink_id);

        Edge *edge = new Edge();
        edge->source = source;
        edge->sink = sink;
        edge->weight = weight;

        source->out_edge.push_back(edge);
        sink->in_edge.push_back(edge);
        Edges.push_back(edge);
    }
    // implement a display of digraph before sorting

    // Displays the network but still working on it... will use for future projects.
    void display(std::unordered_map<std::string, Node *> &Nodes)
    {
        // fixing dereference of how we access the nodes for display
        for (uint i = 0; i < Nodes.bucket_count(); ++i)
        {
            std::cout << "PRINTING OUT NETWORK...\n";
            for (auto &it : Nodes)
            {
                std::cout << it.first << std::endl;
            }
        }
    }

    // verify a topological sort path:
    void topological()
    {
        std::queue<Node *> queue;
        std::set<Node *> results;
    }

    // implement traversal algorithm of our graph implementation for both DFS and BFS

    // For our purposes of this challenge, using a DFS would be best since we are only concerned with
    // verifying the existence of a path to src to sink, not the shortest path.

    // However we can implement both.

    bool dfs(Node *start, Node *target)
    {
        // create a stack of unvisted nodes, s. And create a set of edges e.
        std::stack<Node *> stack;
        std::set<Node *> visited;
        stack.push(start); // push new node into the stack for traversal

        while (!stack.empty())
        {
            Node *node = stack.top();
            stack.pop();

            if (node == target)
            {
                return true;
            }

            if (visited.find(node) == visited.end())
            {
                visited.insert(node);
                for (Edge *edge : node->out_edge)
                {
                    stack.push(edge->sink);
                }
            }
        }
        return false;
    };

    bool bfs(Node *start, Node *target)
    {
        std::queue<Node *> queue;
        std::set<Node *> visited;

        queue.push(start);
        visited.insert(start);

        while (!queue.empty())
        {
            Node *node = queue.front();
            queue.pop();

            if (node == target)
            {
                return true;
            }

            for (Edge *edge : node->out_edge)
            {
                // edge->sink is our neighbor outgoing node from our current node
                if (visited.find(edge->sink) == visited.end())
                {
                    queue.push(edge->sink);
                    visited.insert(edge->sink);
                }
            }
        }
        return false;
    };

    // process the graph and find if the path between source to sink exists
    // we easily swap out the if (dfs) with bfs if preferred.
    void process_digraph(Node *src_node, Node *sink_node, int graph_number)
    {
        if (dfs(src_node, sink_node))
        {
            std::cout << "In Graph " << graph_number << " there is a path from "
                      << src_node->id << " to " << sink_node->id << '\n';
        }
        else
        {
            std::cout << "In Graph " << graph_number << " there is no path from "
                      << src_node->id << " to " << sink_node->id << '\n';
        }
    };
};

// Main Execution
int main(int argc, char *argv[])
{

    int graph_number = 0;

    while (true)
    {
        digraph g;

        int nedges, npaths;
        if (!(std::cin >> nedges))
        {
            break; // if no more input, than break out of while loop
        }

        if (nedges == 0)
        {
            break; // break out if there is no edge
        }
        graph_number++;

        // parse nedges and add in our source and edges
        for (int i = 0; i < nedges; ++i)
        {
            std::string src, sink;
            std::cin >> src >> sink;
            g.add_Edges(src, sink);
        }

        // add in to meet gradescript expectations with output formatting
        std::cin >> npaths;
        if (graph_number > 1)
        {
            std::cout << std::endl;
        }

        // parse all paths, than verify if there is a connection between nodes
        for (int i = 0; i < npaths; ++i)
        {
            std::string src, sink;
            std::cin >> src >> sink;

            Node *src_node = g.initialize_node(src);
            Node *sink_node = g.initialize_node(sink);

            g.process_digraph(src_node, sink_node, graph_number);
        }
    }

    return (0);
}