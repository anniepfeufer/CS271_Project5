#include <iostream>
#include "graph.h"
#include "vector"
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
    
    vector<vector<int> > edges ={{1, 2}, {2,3}, {3,1}};
    Graph<int, int> g=Graph<int, int>(keys, data, edges);
}