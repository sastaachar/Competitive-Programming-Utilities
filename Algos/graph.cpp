#include<bits/stdc++.h>
using namespace std;

template <class Type>
class Graph {

  private:

  	//if the paths have cost associated to them , else 
  	//the path's cost is kept as 0 by default
  	bool weighted;
  	//for a given path a,b
  	//in directed graph only is true a-->b 
  	//in un-directed graph a-->b and b-->a is true
  	bool directed;
  	//if the graph is weighted then cost is stored here
  	int cost;
  	//Adjacency list
  	//For more info : https://www.geeksforgeeks.org/graph-and-its-representations/
 	map< Type, set< pair<Type,int> > > edges;
	//to keep track of existing nodes and to check visit status
	map< Type, bool> nodes; 	


  public:

  	//constructor
	Graph(bool if_weighhted=false, bool if_directed=false) {
		weighted = if_weighhted;
		directed = if_directed;
		cost = 0;
	}

	//basic insert  funtion
	//explicit is true, the path is craeted even if the nodes dont exist
	//default is false, so nodes are created and then path is made
	bool insert( Type from, pair<Type,int> to, bool explicit=false) {
			//add nodes to the list of nodes
		if ( !explicit ) {		
			nodes[from] = true;
			nodes[to.first] = true;
		} else {
			//if any of the node doesnt exist return false
			if ( nodes.find(from) == nodes.end() || nodes.find(to.first) == nodes.end() )
				return false;
		}

		//for directed
		edges[from].insert(to);
        
        //undirected
        if(!directed)
            edges[to.first].insert(make_pair(from,to.second));
		
		//return true if no new nodes have been made
        return true;  
	}

	//it will be usefull to create single node islands
	void add_node( Type node_name) {
		node[node_name] = false;
	}

	//to visit all nodes

	//just for printing output
    template <class type>
	friend ostream & operator << (ostream &out, const Graph<type> &g);

};

//just for printing output
template <class Type>
ostream & operator << (ostream &out, const Graph<Type> &g) {
   	for( auto edge : g.edges ) {
   		out << edge.first << " --> [ ";
   		for( auto path : edge.second) {
   			out << " ( " <<path.first<<" , "<<path.second<<" ) , ";
   		}
   		out << " ]\n";
   	}
    return out;
}


int main() {
	Graph<string> g(true);
	g.insert("Pune",make_pair("cbe",1680));
	g.insert("Pune",make_pair("klt",164));
	g.insert("cbe",make_pair("ksh",623));
	g.insert("ksh",make_pair("klt",1680));
	g.insert("klt",make_pair("Mumbai",164));
	g.insert("Pune",make_pair("klt",623));
	g.insert("Pune",make_pair("klt",623));
	cout << g;
}
