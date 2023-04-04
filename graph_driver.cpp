#include <iostream>
#include "graph.h"
#include <vector> 
using namespace std;

int main(void)
{
    vector<string> keys = {"R", "V", "S", "T", "U", "Y", "W", "X"};
    vector<int> data = {1, 2, 3, 5, 4, 6, 7, 8};
    vector<vector<string> > adjs= {{"V"},{"S"},{"R"},{"S","U","W"},{"Y"},{"W"},{"X"},{"U"}};
    Graph<int, string>* G = new Graph<int, string>(keys, data, adjs);
/*
    vector<int> keys = {1, 2, 3};
    vector<int> data = {1, 2, 3};
    vector<vector<int> > adjs= {{2},{1},{1,2}};
    Graph<int, int>* G = new Graph<int, int>(keys, data, adjs);
*/
    //G->bfs("T");
    return 0;
}