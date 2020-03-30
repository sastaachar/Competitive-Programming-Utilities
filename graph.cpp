#include<bits/stdc++.h>
using namespace std;

template <class Type>
class Graph {

  private:

  	bool weighted;
  	bool directed;
  	int cost;
 	map< Type, set< pair<Type,int> > > edges;


  public:

	Graph(bool if_weighhted=false, bool if_directed=false) {
		weighted = if_weighhted;
		directed = if_directed;
		cost = 0;
	}

	bool insert( Type from, pair<Type,int> to) {
		edges[from].insert(to);
        if(!directed)
            edges[to.first].insert(make_pair(from,to.second));
	}
    template <class type>
	friend ostream & operator << (ostream &out, const Graph<type> &g);

};


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
