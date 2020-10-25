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

bool isPrime(int n) {
	fr(sqrt(n)+1,i)
		if(!n%i)
			return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n1,n2;
	cin >> n1 >> n2;

	int primes[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

	vi selected;
	fr(25,i) if( primes[i] >= n1 && primes[i] <= n2 )
				selected.pb(primes[i]);

	set <int> combinations;
	fr(selected.size(),i)
		fr(selected.size(),j)
			if(i != j)
				combinations.insert( stoi(to_string(selected[i]) + to_string(selected[j]) ) );

	vi VECcombinations;
	for(auto itr=combinations.begin(); itr != combinations.end(); itr++)
        VECcombinations.pb(*itr);

	vi primeCombinations;
	fr(VECcombinations.size(),i)
		if(isPrime(VECcombinations[i]))
			primeCombinations.pb(VECcombinations[i]);

	int a = *min_element(primeCombinations.begin(), primeCombinations.end()),
		b = *max_element(primeCombinations.begin(), primeCombinations.end()),
		len = primeCombinations.size();
	int cur;
	fr(len-2,i) {
		cur = a + b;
		a = b;
		b = cur;
	}
	cout << cur ;
	return 0;
}
