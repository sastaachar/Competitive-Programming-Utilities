void kadaneMin(vl arr) {
	ll n = arr.size();
	ll cur_min = arr[n-1], dpMinR[ n-1 ] = arr[ n-1 ];

	for(int i=n-2; i >= 0; i-- ) {
		if( cur_min > 0 ) 
			cur_min = arr[i];
		else 
			cur_min += arr[i];
		dp[i] = min( dp[i+1], cur_min);
	}

}

void kadaneMax(vl arr) {
	ll n = arr.size();
	ll cur_max = arr[n-1], dpMaxR[ n-1 ] = arr[ n-1 ];

	for(int i=n-2; i >= 0; i-- ) {
		cur_max = max( cur_max+arr[i], arr[i]);
		dp[i] = max( dp[i+1], cur_max);
	}

}