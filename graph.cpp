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
	bool insert( Type from, pair<Type,int> to) {
		edges[from].insert(to);
        if(!directed)
            edges[to.first].insert(make_pair(from,to.second));
	}

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
