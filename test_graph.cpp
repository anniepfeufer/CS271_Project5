

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

void test_get(Graph<int,int>* g) {
    if (g->get(1)->data != 4){
        cout<<"incorrect data found from get"<<endl;
    }
   if (g->get(9) != nullptr) {
        cout<< "incorrect result, found non existent vertex"<<endl;
    }
    if (g->get(1)->key != 1){
        cout<<"incorrect data found from get"<<endl;
    }
}

void test_reachable(Graph<int, int>* g) {
    if (!(g->reachable(1,2))){
        cout<<"failed to recognize reachable vertex"<<endl;
    }
    if (!(g->reachable(1,1))){
        cout<<"failed to recognize reachable vertex"<<endl;
    }
    if (g->reachable(1,4)){
        cout<<"misrecognized nonexistant vertex as reachable"<<endl;
    }
}

void test_bfs(Graph<int,int>* g){
    g->bfs(1);
    if (g->get(1)->pred != nullptr){
        cout<<"bfs source incorrectly has a predecessor"<<endl;
    }
    if (g->get(2)->pred != g->get(1)){
        cout<<"bfs has incorrect predecessor"<<endl;
    }
    if (g->get(3)->pred == g->get(1)){
        cout<<"bfs has incorrect predecessor"<<endl;
    }

    g->bfs(2);
    if (g->get(2)->pred != nullptr){
        cout<<"bfs source incorrectly has a predecessor"<<endl;
    }
    if (g->get(1)->pred != g->get(3)){
        cout<<"bfs has incorrect predecessor"<<endl;
    }
    if (g->get(3)->pred == g->get(1)){
        cout<<"bfs has incorrect predecessor"<<endl;
    }
}

void test_print_path(Graph<int,int>* g){
    
}

int main(){
    Graph<int, int>* g=generate_graph();
    test_get(g); cout << "Testing get" << endl;
    test_reachable(g); cout<<"Testing reachable"<<endl;
    test_bfs(g); cout<<"Testing bfs"<<endl;
    test_print_path(g); cout<<"Testing print path"<<endl;
    delete g;
    return 0;
}