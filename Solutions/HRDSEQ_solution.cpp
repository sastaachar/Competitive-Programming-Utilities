#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
#define pb push_back
#define all(a) a.begin(), a.end()
#define forn(i, n) for(ll i=0; i<(ll)(n); ++i)
#define forab(a, b) for(ll i=a; i<(ll)(b); ++i)
#define MOD 1000000007
const int N = 1e6; // According to size of maximum array allowed in the question

bool comp(int a, int b) 
{ 
    return (a > b); 
} 

int main()
{
    // Faster I/O 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
 
    // test case
    int t;
    cin >> t;

    // Constraints
    int a[130];
    // starting with 0
    a[0] = 0;

    // map for storing the index of a digit's last ocurrence 
    map <int, int> index;
    // set 0's last occured index 
    index[0] = 1;
    // creating result sequence
    forn(i, 129)
    {
      // if a digit is not ocurred before will have 0 as initial value
      if(index[a[i]] == 0)
       {
          // getting the index for newly ocurred digit's
          index[a[i]] = i;
          // setting next value 0 as per sequence
          a[i+1] = 0;
       }
       // digit have already occured
       else
       {
         // present index - last ocurrence index stored in map
         a[i+1] = i - index[a[i]];
         index[a[i]] = i; // set last occurrence digit's index 
       }
    }

    while(t--)
    {
        // get n value
        int n;
        cin >> n;
        // set x value in as and set count as 0
        int as = a[n+1], cnt = 0;
        // get the count of x
        forab(2, n+1)
        {
            if(as == a[i])
                cnt ++;
        }
        // print count
        cout << cnt + 1  << endl;
    }                                                
    return 0;
}
