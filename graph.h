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
		D data;
		K key;
		
	}

	Node* V; //dynamic array of vertices 
	int size; //number of verticies in the graph
	vector<K>* Adj; //dynamic array of pointer to nodes 

public:
	Graph(vector<K> keys, vector<D> data, vector<vector<K>> edges){
		size=size(keys);
		V= new Node<D,K>[size]
		Adj=new vector<K>[size]
		for (int i=0; i<size; i++){
			Node<D,K> curr;
			curr.data=data.at(i);
			curr.key=keys.at(i);
			V[i]=curr;
			Adj[i]=
		}
	}
};