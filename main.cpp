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

int main() {

    //graph to store circuit
    vector<int> circuit_graph[n];

    //node to node connectivity graph of the circuit
    int **primitive_graph;

    // this is where OS tries to do a segmentation fault :))
    primitive_graph = new int* [n];
    for(int i = 0; i < n; i++)
        primitive_graph[i] = new int [n];

    //get the graph
    get_graph(primitive_graph);

    //generate node to node connectivity graph based on the primitive graph
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(primitive_graph[i][j] == 1)
                circuit_graph[i].push_back(j);

    //edges of spanning tree of the circuit graph
    //each edge is a pair of two nodes
    set<pair<int, int> > tree_nodes;

    //generate a spanning tree
    generate_tree(circuit_graph, tree_nodes);



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

void generate_tree(vector<int> graph[], set<pair<int, int> > s_tree)
{
    //a set to put nodes so we make tree acyclic
    set<int> s_tree_nodes;
    pair<int, int> edge;

    //check each edge to see if we can add it to tree
    for(int i = 0; i < n; i++)
        for(int j = 0; j < graph[i].size(); j++)
            //see if node is not added before
            if(s_tree_nodes.find(graph[i][j]) == s_tree_nodes.end())
            {
                //add edge to tree
                s_tree_nodes.insert(graph[i][j]);
                edge.first = i;
                edge.second = j;
                s_tree.insert(edge);
            }

}
