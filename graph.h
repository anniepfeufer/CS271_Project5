
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
bool 		reachable		( K u, K v );
void		print_path		( K u, K v );
void		print_path_r	( vertex* u, vertex* v );
//void		edge_class		( K u, K v );
void		bfs_tree		( K start_key );
void		dfs				( void );
void		dfs_visit		( vertex* u, int time );
};


#include "graph.cpp"

#endif