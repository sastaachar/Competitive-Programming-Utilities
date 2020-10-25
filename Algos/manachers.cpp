class Solution {
public:
  
    string longestPalindrome(string s) {
        int len = 2*s.length() + 1; 
        int pLen[len];
        int C=0, R=0, cMax=0;
        for(int i=0; i<len; i++) { 
            pLen[i] = 0;
            // mirr = C - (i-C)
            int mirr = 2*C-i;
            
            // if i is in R
            if(i < R)
                pLen[i] = mirr >= 0 ? min(R-i, pLen[mirr]): 0;
            
            while( i+pLen[i]+1 < len &&
                    i-pLen[i]-1 >= 0 &&
                    ( (i+pLen[i]+1)%2 == 0 || 
                        s[ (i+pLen[i])/2 ] == s[ (i-pLen[i]-2)/2 ]) && ++pLen[i] );
            
            if( i + pLen[i] > R ) {
                C = i;
                R = i + pLen[i];
                if( pLen[i] > pLen[cMax] )
                    cMax = C;
            }       
        
        } 
        /*
        Single line :) */
        return cMax%2 == 0 ? s.substr( cMax/2 - pLen[cMax]/2, pLen[cMax] ) :
                        s.substr((cMax-1)/2 - (pLen[cMax] - pLen[cMax]%2)/2, (pLen[cMax] - pLen[cMax]%2) + 1 );    
        /*
        string ans; 
        if(cMax%2 == 0) {
            // pLen here will always be even
            ans = s.substr( cMax/2 - pLen[cMax]/2, pLen[cMax] );
        } else {
            int ssLen = pLen[cMax];
            ssLen -= ssLen%2;
            ans = s.substr((cMax-1)/2 - ssLen/2, ssLen + 1 );
        }
        
        return ans;        
        */
    }
};