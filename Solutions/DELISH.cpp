#include<bits/stdc++.h>
#define fr(siz,i) for(ll i=0;i<siz;i++)
#define frr(siz,i,a) for(ll i=a;i<siz;i++)
#define ff(siz) for(ll sasta=0;sasta<siz;sasta++)
#define ll long long
#define pb push_back
#define pii pair<ll,ll>
#define pll pair< ll , ll >
#define vi vector<ll>
#define vvi vector< vi >
#define vl vector<ll>
#define vvl vector< vl >
#define vin(arr,n) ff(n){ll x; cin>>x; arr.pb(x);}
#define vln(arr,n) ff(n){ll x; cin>>x; arr.pb(x);}
#define top front
const ll maxn=(ll)(2e5+5);
const ll mod=(ll)(1e9+7);
//ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

vl dpMaxL(10000);
vl dpMinL(10000);
vl dpMaxR(10000);
vl dpMinR(10000);

void kadaneMin(vl arr) {
	ll n = arr.size();
	ll cur_min = arr[n-1];
	dpMinR[ n-1 ] = arr[ n-1 ];

	for(int i=n-2; i >= 0; i-- ) {
		if( cur_min > 0 ) 
			cur_min = arr[i];
		else 
			cur_min += arr[i];
		dpMinR[i] = min( dpMinR[i+1], cur_min);
	}

}

void kadaneMax(vl arr) {
	ll n = arr.size();
	ll cur_max = arr[n-1];
	dpMaxR[ n-1 ] = arr[ n-1 ];

	for(int i=n-2; i >= 0; i-- ) {
		cur_max = max( cur_max+arr[i], arr[i]);
		dpMaxR[i] = max( dpMaxR[i+1], cur_max);
	}

}


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll t; cin>>t;
	while(t--) {
		ll n; cin>>n;
		vl arr; vln(arr,n);
		ll maxDif = -1;

		kadaneMin(arr);
		kadaneMax(arr);
		ll cur_maxL, cur_minL, curDif;

		for(ll i=0; i < n; i++) {

			if( i == 0 ) {
			
				dpMaxL[ 0 ] = arr[0];
				dpMinL[ 0 ] = arr[0];
				cur_minL = arr[0];
				cur_maxL = arr[0];

				curDif = max( abs( arr[i] - dpMinR[i+1] ), 
								 abs( dpMaxR[i+1] - arr[i] ) );
							
			} else if ( i == n-1 ) {

				ll curDif = max( abs( dpMaxL[ i-1 ] - arr[i] ) , 
								 abs( arr[i] - dpMinL[ i-1 ] ) );
			
			} else {

                cur_maxL = max( cur_maxL+arr[i], arr[i]);
                if( cur_minL > 0)
                	cur_minL = arr[i];
                else 
                	cur_minL += arr[i];

				dpMaxL[ i ] = max( dpMaxL[i-1], cur_maxL );
				dpMinL[ i ] = min( dpMinL[i-1], cur_minL ); 
				
				ll curDif = max( max( abs(dpMaxL[i] - dpMinR[i+1]), 
				                      abs(dpMaxR[i+1] - dpMinL[i]) ),
				                 max( abs(dpMaxL[i-1] - dpMinR[i]), 
				                      abs(dpMaxR[i] - dpMinL[i-1]) ) );    

			}
				if( curDif > maxDif ) 
					maxDif = curDif;
		}
		
		//debugging---------------------------
		cout << "\ndpMinL\n";
		fr(n,i)
		    cout << dpMinL[i] << " ";
	    cout << "\ndpMaxL\n";
		fr(n,i)
		    cout << dpMaxL[i] << " ";
	    cout << "\ndpMinR\n";
		fr(n,i)
		    cout << dpMinR[i] << " ";
	    cout << "\ndpMaxR\n";
	    fr(n,i)
		    cout << dpMaxR[i] << " ";
	    cout << "\n";
	    //--------------------------------------
	    
		cout << maxDif << "\n";
	}
	return 0;
}