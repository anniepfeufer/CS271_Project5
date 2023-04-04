
#include "graph.h"
/*
template <typename D, typename K>
Node<D,K>* Graph<D,K>::get(K k){
    for (int i=0; i<size; i++){
        if (V[i].key==k){
            return V[i];
        }
    }
    return nullptr;
}
*/

//==================================
// graph.cpp
//==================================



//============================================
// constructor
// description: creates V and Adj from keys, data, and edges
// PARAMETERS:
// RETURN:
// pre-conditions:
// pos-conditions:
//============================================
template <typename D, typename K>
    Graph<D,K>::Graph       (vector<K> keys, vector<D> data, vector<vector<K> > edges )
{
    //V = {};
    //V.resize(keys.size());            //resize to keys 
    for ( int i = 0; i < keys.size(); i++ )//can we combine these into one loop for time? all3 go through same size vectors
    {
        vertex* v_node = new vertex;
        v_node->data = data[i];
        v_node->key = keys[i];
        v_node->index = i;
        v_node->color = 0;
        v_node->d = -8;
        v_node->pred = NULL;
        V.push_back(v_node);
    }

    //Adj.resize(keys.size());//resize to keys
    for ( int i = 0; i < edges.size(); i++ )
    {
        vector<vertex*> curr_adj = {};
        for ( int j = 0; j < edges[i].size(); j++ )
        {
            for ( int n = 0; n < keys.size(); n++ )
            {
                if (keys[n] == edges[i][j])
                {
                    curr_adj.push_back(V[n]);
                }
            }
        }
        Adj.push_back(curr_adj);
    }   

    for ( int i = 0; i < keys.size(); i++)
    {
        cout << " i = " << i << endl;
        cout << "V[i] key = " << V[i]->key << endl;
        cout << "V[i] data = " << V[i]->data << endl;
        cout << "V[i] index = " << V[i]->index << endl;
        for ( int j = 0; j < edges[i].size(); j++ )
            cout << "edges at  i = " <<  Adj[i][j]->key << endl;
    }

}

//============================================
// destructor
// description: 
// PARAMETERS:
// RETURN:
// pre-conditions:
// pos-conditions:
//============================================
template <typename D, typename K>
        Graph<D,K>::~Graph      ( void )
{
    return;
}


//============================================
// BFS
// description: 
// PARAMETERS:
// RETURN:
// pre-conditions:
// pos-conditions:
//============================================
template <typename D, typename K>
void        Graph<D,K>::bfs     ( K start_key )
{
    vertex* s = get(start_key);
    queue<vertex*> Q;
    for ( int u = 0; u < V.size(); u++ )
    {
        V[u]->color = 0;
        V[u]->d = -8;
        V[u]->pred = NULL;
    }
    s->color = 1;
    s->d = 0;
    s->pred = NULL;
    Q.push(s);
    while ( !Q.empty() )
    {
        vertex* u = Q.front();
        Q.pop();
        for ( int v = 0; v < Adj[u->index].size(); v++ )
        {
            if ( Adj[u->index][v]->color == 0 )
            {
                Adj[u->index][v]->color = 1;
                Adj[u->index][v]->d = u->d + 1;
                Adj[u->index][v]->pred = u;
                Q.push(Adj[u->index][v]);
            }
        }
    }
    /*
    for ( int i = 0; i < V.size(); i++)
    {
        cout << " i = " << i << endl;
        cout << "V[i] key = " << V[i]->key << endl;
        cout << "V[i] data = " << V[i]->data << endl;
        cout << "V[i] index = " << V[i]->index << endl;
        cout << "V[i] color = " << V[i]->color << endl;
        cout << "V[i] d = " << V[i]->d << endl;
        if ( V[i]->pred != NULL)
            cout << "V[i] pred = " << (V[i]->pred)->key << endl;
    }
    */
    return;
}

//============================================
// reachable
// description: 
// PARAMETERS:
// RETURN:
// pre-conditions:
// pos-conditions:
//============================================
template <typename D, typename K>
bool        Graph<D,K>::reachable       ( K u, K v )
{
    vertex* n = get(v);
    bfs(u);
    if ( n->color == 0 )
        return false;
    return true;
}
/*
//============================================
// print_path
// description: 
// PARAMETERS:
// RETURN:
// pre-conditions:
// pos-conditions:
//============================================
template <typename D, typename K>
void        Graph<D,K>::print_path      ( K u, K v )
{
    bfs(u);
    get(u);
    get(v);
    print_path_r( u, v );
    return;
}

//============================================
// print_path_r
// description: 
// PARAMETERS:
// RETURN:
// pre-conditions:
// pos-conditions:
//============================================
template <typename D, typename K>
void        Graph<D,K>::print_path_r        ( vertex* u, vertex* v )
{
    if ( v->key == u->key )
        cout << v->key << endl;
    else if ( v->pred == NULL )
        cout << "no path" << endl;
    else
        print_path_r( u, v );
        cout << v->key << endl;
}

//============================================
// edge_class
// description: 
// PARAMETERS:
// RETURN:
// pre-conditions:
// pos-conditions:
//============================================
template <typename D, typename K>
void        Graph<D,K>::edge_class      ( K u, K v )
{
    return;
}

//============================================
// bfs_trees
// description: 
// PARAMETERS:
// RETURN:
// pre-conditions:
// pos-conditions:
//============================================
template <typename D, typename K>
void        Graph<D,K>::bfs_trees       ( K start_key )
{
    return;
}
*/









