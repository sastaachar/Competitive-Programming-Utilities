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
    int level;
	vector< node* > ls; //child nodes
    node* parent; //parent node
	map< int , int > facs; //no facs given
};

node* newNode(int Id) {
	node* temp = new node;
	temp->id = Id;
    temp->parent = NULL;
    temp->level = 0;
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


ll solve(node* start, node* dest) {
    map<int,int> total;
    node *a = start,*b = dest;
    if(b->level < a->level)
        swap(a,b);
    while( a->level != b->level ) {
        //cout<<b->id<<" ";
        for( auto itr : b->facs)
            total[itr.first] += total[itr.second];
        b = b->parent;
    }
    while(a != b) {
        //cout<<b->id<<" "<<a->id<<" ";
        for( auto itr : b->facs)
            total[itr.first] += total[itr.second];
        for( auto itr : a->facs)
            total[itr.first] += total[itr.second];
        a = a->parent;
        b = b->parent;
    }
    //cout<<a->id<<"\n";
    for( auto itr : b->facs)
        total[itr.first] += total[itr.second];
    //now a and b are at lca
    ll sum = 1;
    for( auto itr : total)
        sum = (sum*(itr.second+1))%mod;
    return sum;
}

void rootIt(node* root) {

    vector<node*> children =  root->ls;
    fr(children.size(),i) {
        node* cur = children[i];
        vector<node*> gchildren =  cur->ls;
        fr(gchildren.size(),i) {
            if( gchildren[i] == root ) {
                cur->ls.erase(cur->ls.begin()+i);
                break;
            }
        }
        cur->parent = root;
        cur->level = root->level+1;
        rootIt(cur);
    }
}

void printTree(node* root) {

    cout<<"Me : "<<root->id<<" Level : "<<root->level<<"\n";
    if(root->parent)
        cout<<"My parent : "<<root->parent->id<<"\t";



    cout<<"My children : ";
    fr(root->ls.size(),i) {
        cout<<root->ls[i]->id<<" ";
    }
    cout<<"\n";
    fr(root->ls.size(),i) {
        printTree(root->ls[i]);
    }

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

        //create rooted tree
        nodes[1]->level = 0;
        rootIt(nodes[1]);
        printTree(nodes[1]);

        int q; cin>>q;
        vector<node*> path;
        while(q--) {
            path.clear();
            int v,u; cin>>v>>u;
            cout<<solve(nodes[v],nodes[u])<<"\n";
        }
    }



    return 0;
}
