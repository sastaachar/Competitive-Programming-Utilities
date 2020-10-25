class Solution {
void printt(vector<int> ls) {
   cout<<"{"; for(int i=0;i<ls.size();i++) cout << ls[i] << ","; cout<<"}";
    }
    
    void printv(vector< vector<int> > ls) {
       for(int i=0;i<ls.size();i++) printt(ls[i]);  
    }
    
    void printm( map<int, vector< vector<int> > > ls) {
       cout<<"|\n"; for(auto i=ls.begin();i!=ls.end();i++) {cout <<i->first<<" -> "; printv(i->second); cout <<"\n";}  
    }
    
    
    
    
    
    
    
    public:
    
    
    
    bool notIn(vector<vector<int>>& a, vector<int>& b) {
        for(int i=0;i<a.size();i++) 
            if(a[i] == b) 
                return false;
        return true;
    }
    vector<int> createSet(int a, int b, int i, int j) {
        vector<int> newSet;
        if(a > b) {
            newSet.push_back(b);
            newSet.push_back(a);
        } else {
            newSet.push_back(a);
            newSet.push_back(b);
        }
        return newSet;
    }
        
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        map< int , vector< vector<int> > > mp;
        vector<vector<int>>  ans;
        vector<vector<int>> dups;
        for(int i=0; i<nums.size()-1; i++ ) {
            for(int j=i+1; j<nums.size(); j++ ) {
                cout << i << j << "->\n";
                int cur = nums[i] + nums[j];
                // create new set
                vector<int> newSet = createSet(nums[i],nums[j]);
                               
                if( mp.find(cur) != mp.end() ) {     
                    vector< vector<int> > temp= mp[cur];
                    if(!notIn(temp,newSet) )   {
                        printt(newSet); cout << " in "; printv(temp); cout << "\n";
                        // entry can be [a,b,a,b]
                        if(2*(newSet[0] + newSet[1]) == target && notIn(dups,newSet)) {
                            dups.push_back(newSet);
                            newSet.insert(newSet.begin(), newSet[0]);
                            newSet.push_back(newSet[1]);
                            ans.push_back(newSet);
                            cout << nums[i] << nums[j];
                            printv(ans); cout << "\n";
                        }
                        continue;
                    }    
                } else {
                    vector< vector<int> > temp;
                    mp[nums[i] + nums[j]] = temp;                    
                }  
                // new entry so new pairings
                vector< vector<int> > temp = mp[ target - (nums[i] + nums[j]) ];
                for(int k=0;k<temp.size();k++ ) {
                    vector<int> temp2 = temp[k];
                    temp2.push_back(newSet[0]);
                    temp2.push_back(newSet[1]);
                    sort(temp2.begin(), temp2.end());
                    if(notIn(ans,temp2))
                        ans.push_back(temp2);
                }
                    
                mp[nums[i] + nums[j]].push_back(newSet);    
            }
        }
        
        return ans;
    }
};