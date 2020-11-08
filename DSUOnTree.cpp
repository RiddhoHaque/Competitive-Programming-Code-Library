/* 
 *  Input:
 *  n : Number of vertices in tree
 *  adj[] : adjacency list for tree representation
 * 	root : root of the tree
 *  
 *  Solves all queries on subtree of each node in O(n*log n)
 * 
 *  Just add necessary modifications to answer the given queries
 *  in the places mentioned.
 *  
 *  Simply call dsuOnTrees() afterwards 
 */

#define NODES 100105

int n;
vector <int> adj[NODES];
int sz[NODES];
int par[NODES];

int root;
bool big[NODES];

void sizeDfs(int nd){
	sz[nd]=1;
	for(auto v : adj[nd]){
		if(v!=par[nd]){
			par[v]=nd;
			sizeDfs(v);
			sz[nd]+=sz[v];
		}
	}
}

void add(int nd, int x){
	
	/*
	 * 	Do calculations for answering queries 
	 */
	
	for(auto v: adj[nd]){
		if( v!=par[nd] && !big[v]){
			add(v, x);
		}
	}
}

void dfs(int nd, bool keep){
	int mx=-1, bigChild=-1;
	for(auto v: adj[nd]){
		if(v!=par[nd] && sz[v]>mx){
			mx=sz[v], bigChild=v;
		}
	}
	for(auto v : adj[nd]){
		if(v!=par[nd] && v!=bigChild) dfs(v, false); 
	}
	if(bigChild!=-1){
		dfs(bigChild, true);
		big[bigChild]=true;
	}
	
	add(nd, 1);
	
	/*
	 * Answer all queries on the subtree of this node here
	 */
	
	if(bigChild!=-1) big[bigChild]=false;
	if(keep==0) add(nd, -1);
}

void dsuOnTree(int _root){
	
	/*
	 * Add necessary initializations
	 * to all data structures used to answer the queries
	 */
	
	
	root=_root;
	par[root]=-1;
	sizeDfs(root);
	dfs(root, true); //Calculates answers to all queries in O(n*logn)
}

