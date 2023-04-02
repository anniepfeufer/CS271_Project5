//==================================
// graph.h
//==================================

#include <iostream>
using namespace std;

//==================================
// Graph Class
//==================================
template <typename D, typename K>
class Graph
{
private:
	struct Node //node structure 
	{
		D vertex;
		K key;
		Node *next;
	}

	D* V; //dynamic array of vertices 
	Node* Adj; //dynamic array of pointer to nodes 

public:
	Graph(vector<K> keys, vector<D> data, vector<vector<K>> edges){
		
	}
}