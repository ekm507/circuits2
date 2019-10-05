#include <iostream>
#include <vector>
#include <cstdlib>
#include <set>
#include <utility>

using namespace std;

//number of nodes in graph
const int n = 10;

//get primitive circuit graph
//NOW it makes a random graph
void get_graph(int**);

//generates random int
int random_int(int);

//generate a spinning tree for the graph
void generate_tree(vector<int>[], set<pair<int, int> >);

//generate node-neighbour matrix from node-node-connectivity matrix
void generate_graph(vector<int>[], int**);

//make a rooted spinning tree.
int make_tree(vector<vector<int> > tree, vector<int> circuit_graph[]);

int main() {

    cout << "hi!\n";

    //graph to store circuit
    vector<int> circuit_graph[n];

    //node to node connectivity graph of the circuit
    int **primitive_graph;

    //dynamically alloc the graph array
    // this is where OS tries to do a segmentation fault :))
    primitive_graph = new int* [n];
    for(int i = 0; i < n; i++)
        primitive_graph[i] = new int [n];

    //get the graph
    get_graph(primitive_graph);

    //generate node to node connectivity graph based on the primitive graph
    generate_graph(circuit_graph, primitive_graph);

    //edges of spanning tree of the circuit graph
    //each edge is a pair of two nodes
    set<pair<int, int> > tree_nodes;

    //generate a spanning tree
    generate_tree(circuit_graph, tree_nodes);

    //generate leveled spanning tree of the graph
    vector<vector<int> > tree;
    make_tree(tree, circuit_graph);


    return 0;
}

void get_graph(int** graph)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            graph[i][j] = random_int(1);
}

//generates random numbers less than or equal to 'max'
int random_int(int max)
{
    return rand() % (max + 1);
}


//generate node-neighbour matrix from node-node-connectivity matrix
void generate_graph(vector<int> circuit_graph[], int** primitive_graph)
{
    //add neighbours for each node
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(primitive_graph[i][j] == 1)
                circuit_graph[i].push_back(j);
}
