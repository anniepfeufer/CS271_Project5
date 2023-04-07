#include <iostream>
//#include "graph.h"
#include "vector"
#include "graph.cpp"
using namespace std;

int main(void)
{
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
    
    Graph<int, int> g=Graph<int, int>(keys, data, edges);

    /*
    vector<string> keys = {"R", "V", "S", "T", "U", "Y", "W", "X"};
    vector<int> data = {1, 2, 3, 5, 4, 6, 7, 8};
    vector<vector<string> > adjs= {{"V"},{"S"},{"R"},{"S","U","W"},{"Y"},{"W"},{"X"},{"U"}};
    Graph<int, string>* G = new Graph<int, string>(keys, data, adjs);
    */
}