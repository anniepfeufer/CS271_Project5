
//==================================
// graph.h
//==================================

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


#ifndef GRAPH_H
#define	GRAPH_H

//==================================
// Graph Class
//==================================
template <typename D, typename K>
class Graph
{
private:
	struct vertex //node structure 
	{
		D data;
		K key;
		int index;
		int color;
		int d;
		vertex* pred;
	};

	vector<vertex*> V; //vector of pointers to vertices 
	vector<vector<vertex*> > Adj; //dynamic array of pointer to nodes 



public:
			Graph			(vector<K> keys, vector<D> data, vector<vector<K> > edges );
   		   ~Graph  			( void );
void 		bfs				( K start_key );
vertex*  	get			    ( K key ){
	for ( int i = 0; i < V.size(); i++ )
	{
		if (V[i]->key == key)
			return V[i];
	}
	return NULL;
}		
//void 		reachable		( vertex* u, vertex* v );
//void		print_path		( vertex* u, vertex* v );
//void		print_path_r	( vertex* u, vertex* v );
//void		edge_class		( vertex* u, vertex* v );
//void		bfs_trees		( K start_key );
};


//#include "graph.cpp"

#endif