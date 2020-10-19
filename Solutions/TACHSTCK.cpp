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

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	
	int n,d; cin>>n>>d; 
	vl arr; vln(arr,n); sort(arr.begin(),arr.end());
	ll i=0,count=0;
	while(i+1 < n) 
		if(arr[i+1] - arr[i++] <= d && ++i) 
			++count;
	cout<<count<<"\n";

}