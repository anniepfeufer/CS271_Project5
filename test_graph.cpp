

#include <fstream>
#include <sstream>
#include "graph.cpp"

Graph<int, int>* generate_graph(){
    vector<int> keys;
    keys.push_back(1);
    keys.push_back(2);
    keys.push_back(3);

    vector<int> data;
    data.push_back(4);
    data.push_back(5);
    data.push_back(6);

    vector<int> inner1;
    inner1.push_back(1);
    inner1.push_back(2);
    vector<int> inner2;
    inner2.push_back(2);
    inner2.push_back(3);
    vector<int> inner3;
    inner3.push_back(3);
    inner3.push_back(1);

    vector<vector<int> > edges;
    edges.push_back(inner1);
    edges.push_back(inner2);
    edges.push_back(inner3);
    
    Graph<int, int>* g= new Graph<int, int>(keys, data, edges);
    return g;
}


int main(){
    Graph<int, int>* g=generate_graph();
    delete g;
    return 0;
}