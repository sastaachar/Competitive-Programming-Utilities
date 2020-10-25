#include<bits/stdc++.h>
#define fr(siz,i) for(int i=0;i<siz;i++)
#define frr(siz,i,a) for(int i=a;i<siz;i++)
#define ff(siz) for(int sasta=0;sasta<siz;sasta++)
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define pll pair< ll , ll >
#define vi vector<int>
#define vvi vector< vi >
#define vl vector<ll>
#define vvl vector< vl >
#define vin(arr,n) ff(n){int x; cin>>x; arr.pb(x);}
#define vln(arr,n) ff(n){ll x; cin>>x; arr.pb(x);}
#define top front
const int maxn=(int)(2e5+5);
const ll mod=(ll)(1e9+7);
//ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int lcs( string& s1, string& s2, int m, int n) {
	//1 line answer
	//return !m*n ? 0 : (s1[ m-1 ] == s2[ n-1 ] ? 1+lcs( s1, s2, m-1, n-1 ) : max (lcs( s1, s2, m-1, n),lcs( s1, s2, m, n-1)));

	//if( n == 0 || m == 0)
	if( !m*n )
		return 0;
	if( s1[ m-1 ] == s2[ n-1 ] ) {
		return 1+lcs( s1, s2, m-1, n-1 );
	} else {
		return max (
				lcs( s1, s2, m-1, n),
				lcs( s1, s2, m, n-1)
			);
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int t; cin>>t;
	while(t--) {
		string s1, s2; 
		cin >> s1 >> s2;
		cout << lcs( s1, s2, s1.length(), s2.length());
	}
	return 0;
}