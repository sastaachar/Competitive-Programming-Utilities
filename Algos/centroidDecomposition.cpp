#include<bits/stdc++.h>
#define fr(siz,i) for(int i=0;i<siz;i++)
#define frr(siz,i,a) for(int i=a;i<siz;i++)
#define ff(siz) for(int i=0;i<siz;i++)
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define pll pair< ll , ll >
#define vi vector<int>
#define vvi vector< vi >
#define vl vector<ll>
#define vvl vector< vl >
#define top front
const int maxn=(int)(2e5+5);
const ll mod=(ll)(1e9+7);
//ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;



//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ utility functions to find prime factors ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓//
#define MAXN   1000001
int spf[MAXN];
void sieve() {
    spf[1] = 1;
    frr(MAXN,i,2)
        spf[i] = i;

    for(int i=4; i<MAXN; i+=2)
        spf[i] = 2;

    for (int i=3; i*i<MAXN; i++) {
        if (spf[i] == i) {
            for (int j=i*i; j<MAXN; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
map<int,int> getFactorization(int x)
{
    map<int,int> ret;
    while (x != 1)
    {
        ++ret[spf[x]];
        x = x / spf[x];
    }
    return ret;
} 
//↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑ utility functions to find prime factors ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑//

struct node {
	bool v; //if visited 
	int id; //like adhaar id
    int height;
	vector< node* > bache; //child nodes
    node* baap; //parent node
	map< int , int > facs; //no facs given
};

node* newNode(int Id) {
	node* temp = new node;
	temp->id = Id;
	return temp;
}

void printGraph(map<int,node*> nodes) {
            for(auto itr: nodes) {
                node* t = itr.second;
                cout<<"Current Node : "<<t->id<<"\n";
                fr(t->ls.size(),i)
                    cout<<t->ls[i]->id<<" ";
                cout<<"\n";
        }
}

void printMap(map<int,int> nodes) {
    cout<<"MAP\n";
            for(auto itr: nodes)
                cout<<itr.first<<" "<<itr.second<<"\n";

}

bool getPath(node* start, node* dest, vector<node*> &path) {
    if(dest == start) {
        return true;
    }
    start->v = true;
    vector<node*> children =  start->ls;
    fr(children.size(),i) {
        if(!children[i]->v) {
            if( getPath(children[i],dest,path) ) {
                path.pb(children[i]);
                return true;
            }
        }
    }
    return false;
}



int main()
{
    // precalculating Smallest Prime Factor
    sieve();
    int t; cin>>t;
    while(t--) {
        map< int , node* > nodes;
        int n; cin>>n;
        fr(n,i)
            nodes[i+1] = newNode(i+1);

        fr(n-1,i) {
            int v,u; cin>>v>>u;
            nodes[v]->ls.pb(nodes[u]);
            nodes[u]->ls.pb(nodes[v]);
        }

        fr(n,i) {
            int  x; cin>>x;
            nodes[i+1]->facs = getFactorization(x);
        }
        int q; cin>>q;
        vector<node*> path;
        while(q--) {
            path.clear();
            int v,u; cin>>v>>u;
            for(auto itr : nodes)
                itr.second->v = false;
            //cout<<solve(nodes[v],nodes[u])<<"\n";
            getPath(nodes[v],nodes[u],path);
            path.pb(nodes[v]);
            map<int,int> total;
            fr(path.size(),i) {
                for(auto itr : path[i]->facs)
                    total[itr.first] += itr.second;
            }
            ll sum = 1;
            for(auto itr : total)
                sum = (sum * (itr.second+1))%1000000007;
            cout<<sum<<"\n";
        }
    }
    return 0;
}
