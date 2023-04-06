
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
    bfs(u);
    vertex* ver = get(v);
    if ( ver != NULL && ver->color != 0 )
        return true;
    return false;
}


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
    print_path_r( get(u), get(v) );
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
void        Graph<D,K>::print_path_r        ( vertex* s, vertex* v )
{
    if ( v->key == s->key )
        cout << s->key << endl;
    else if ( v->pred == NULL )
        cout << "no path" << endl;
    else
    {
        print_path_r( s, v->pred );
        ccout << " -> " << v->key;
    }
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
string        Graph<D,K>::edge_class      ( K u, K v )
{
    dfs();
    vertex* a=get(u);
    vertex* b=get(v);
    if (Adj[u->index][v]!=NULL){
        //not sure if this is right way, want to check that there IS an existing edge
        if (b->pred=a)
            return "tree edge";
        else if ( (a->d > b->d) && (b->f > a->f) )
            return "forward edge";
        else if ( (a->d < b->d) && (b->f < a->f) )    
            return "back edge";
        else 
            return "cross edge"
    }
    return "no edge";
}

//============================================
// bfs_tree
// description: 
// PARAMETERS:
// RETURN:
// pre-conditions:
// pos-conditions:
//============================================
template <typename D, typename K>
void        Graph<D,K>::bfs_tree        ( K start_key )
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
    cout << s->key << endl;
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
                if ( v != 0 )
                    cout << " ";
                cout << Adj[u->index][v]->key;
                Q.push(Adj[u->index][v]);
            }

        }
        if ( !Q.empty() && Q.front()->d == u->d+1)
            cout << endl;
    }
    return;
}

//============================================
// dfs
// description: 
// PARAMETERS:
// RETURN:
// pre-conditions:
// pos-conditions:
//============================================
template <typename D, typename K>
void        Graph<D,K>::dfs         ( void )
{
    for ( int u = 0; u < V.size(); u++ )
    {
        V[u]->color = 0;        // 0 = white
        V[u]->pred = NULL;
    }
    int time = 0;
    for ( int u = 0; u < V.size(); u++ )
    {
        if ( V[u]->color == 0 )
            time=dfs_visit( V[u], time );
    }

    for ( int i = 0; i < V.size(); i++)
    {
        cout << "V[i] key = " << V[i]->key << endl;
        if ( V[i]->pred != NULL )
            cout << "V[i] pred = " << (V[i]->pred)->key << endl;
        cout << "V[i] d = " << V[i]->d << endl;
        cout << "V[i] f = " << V[i]->f << endl;

    }
}

//============================================
// dfs_visit
// description: 
// PARAMETERS:
// RETURN:
// pre-conditions:
// pos-conditions:
//============================================
template <typename D, typename K>
int        Graph<D,K>::dfs_visit           ( vertex* u, int time )
{
    time = time + 1;
    u->d = time;
    u->color = 1;
    for ( int v = 0; v < Adj[u->index].size(); v++ )
    {
        if ( Adj[u->index][v]->color == 0 )
        {
            Adj[u->index][v]->pred = u;
            time=dfs_visit( Adj[u->index][v], time );
        }
    }
    time = time + 1;
    u->f = time;
    return time;
}









