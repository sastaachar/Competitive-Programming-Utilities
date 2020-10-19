#include <bits/stdc++.h>
#define fr(siz, i) for (int i = 0; i < siz; i++)
#define frr(siz, i, a) for (int i = a; i < siz; i++)
#define ff(siz) for (int sasta = 0; sasta < siz; sasta++)
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<ll>
#define vvl vector<vl>
// clang-format off
#define vin(arr,n) ff(n){int x; cin>>x; arr.pb(x);}
#define vln(arr,n) ff(n){ll x; cin>>x; arr.pb(x);}
#define pv(arr) fr(arr.size(),i){cout<<arr[i]<<" ";}cout<<"\n";
// clang-format on
#define top front
const int maxn = (int)(2e5 + 5);
const ll mod = (ll)(1e9 + 7);
using namespace std;

// random number generators
vi get_n_random(int n, int r = 10e5, int l = 0) {
    vi randomNumbers;
    ff(n) randomNumbers.pb(rand() % r + l);
    return randomNumbers;
}
int get_1_random(int r = 10e9, int l = 0) {
    return rand() % r + l;
}
string get_1_random_string(int len = 20) {
    string s = "";
    ff(len) {
        s += (char)('a' + get_1_random() % 26);
    }
    return s;
}

class Solution {
   public:
    // function here
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s == "" || words.size() == 0) return vector<int>{};

        vi ans;
        int len = words[0].length(), n = words.size(), str_len = s.length();
        // divide into blocks there can be 'len' sets
        map<string, int> word_counter;
        fr(n, j) word_counter[words[j]] += 1;
        int unique_words = word_counter.size();

        fr(len, i) {
            // first block = {i , i+1 , ... i+(len-1) }
            //cout << "---" << i << "---\n";
            // initialize counter for words

            map<string, int> counter;

            int count = 0;

            int left = i, right = i;
            while (right + len <= str_len) {
                string block = s.substr(right, len);
                //cout << block << "\n";
                // add block to set

                cout << block << " checking\n";
                if (counter[block] == word_counter[block]) {
                    // remove blocks until its ok to use this 1

                    if (word_counter[block] == 0) {
                        cout << block << " unknown\n";
                        counter.clear();
                        count = 0;
                        right += len;
                        left = right;
                        continue;
                    }

                    while (counter[block] != word_counter[block] - 1) {
                        string prev_block = s.substr(left, len);
                        cout << prev_block << " removing\n";
                        if (counter[prev_block] == word_counter[prev_block])
                            --count;
                        --counter[prev_block];
                        left += len;
                    }
                    continue;
                }

                ++counter[block];
                cout << block << " adding\n";

                int num_of_blocks = (right - left) / len + 1;

                if (num_of_blocks <= n) {
                    // only check last block
                    if (word_counter[block] == counter[block])
                        ++count;

                } else if (num_of_blocks > n) {
                    // move right too
                    string prev_block = s.substr(left, len);
                    left += len;
                    --counter[prev_block];
                    cout << prev_block << " removing\n";
                    bool prev_count = word_counter[prev_block] == counter[prev_block],
                         cur_count = word_counter[block] == counter[block];

                    if (prev_count && cur_count) {
                        ++count;
                    } else {
                        // if the count got messed up in this iteration
                        if (!prev_count && counter[prev_block] == word_counter[prev_block] - 1)
                            --count;
                        if (!cur_count && counter[prev_block] == word_counter[prev_block] + 1)
                            --count;
                    }
                }

                if (count == unique_words) {
                    ans.pb(left);
                    cout << "got 1\n";
                }

                right += len;
            }

            // sliding window for each block
        }
        return ans;
    }
    bool check(string s, vector<string> words) {
        if (s == "")
            return words.size() == 0;

        fr(words.size(), i) {
            if (words[i].length() > s.length())
                return false;

            if (s.substr(0, words[i].length()) == words[i]) {
                vector<string> new_words = words;
                new_words.erase(new_words.begin() + i);
                if (check(s.substr(words[i].length(), s.length() - words[i].length()), new_words)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool check2(string s, vector<string> words) {
        map<string, int> mp;
        int ws = words[0].size();
        fr(words.size(), i) {
            mp[words[i]] += 1;
        }
        int count = 0;
        fr(words.size(), i) {
            string block = s.substr(i * ws, ws);
            if (mp[block])
                --mp[block];
            else
                return false;
        }
        return true;
    }

    vector<int> brute(string s, vector<string>& words) {
        vi ans;

        int len = 0;
        fr(words.size(), i) len += words[i].length();

        fr(s.length(), i) {
            // match each words
            if (check(s.substr(i, len), words)) {
                ans.pb(i);
            }
        }
        return ans;
    }

    bool test(int t) {
        srand(time(0));
        // generate humber of words
        int count = 0;
        Solution s;

        ff(t) {
            int n = get_1_random(10, 1);
            vector<string> words;
            int wlen = get_1_random(10, 1);
            ff(n) {
                words.pb(get_1_random_string(wlen));
            }

            string str = "";

            fr(3, j) {
                map<int, bool> gotIt;
                string s = "";
                int m = get_1_random(n + 10, n);
                fr(m, i) {
                    int ra = get_1_random(n);
                    if (gotIt[ra]) continue;
                    s += words[ra];
                    gotIt[ra] = true;
                }
                str += s;
                if (get_1_random() % 2)
                    str += get_1_random_string(2);
            }
            vi ans1 = s.brute(str, words);
            vi ans2 = s.findSubstring(str, words);
            sort(ans1.begin(), ans1.end());
            sort(ans2.begin(), ans2.end());
            if (ans1 != ans2) {
                cout << str << "\n";
                pv(words);

                pv(ans1);
                pv(ans2);

            } else {
                ++count;
            }
        }
        cout << "Pass % : " << (double)(count) / t << "\n";
    }

    bool test() {
        srand(time(0));
        // generate humber of words
        int count = 0;
        Solution s;

        int t;
        cin >> t;

        ff(t) {
            string str;
            cin >> str;
            vector<string> words;
            int n;
            cin >> n;
            int wlen;
            cin >> wlen;
            ff(n) {
                string x;
                cin >> x;
                words.pb(x);
            }

            vi ans1 = s.brute(str, words);
            vi ans2 = s.findSubstring(str, words);

            if (ans1 != ans2) {
                cout << str << "\n";
                pv(words);

                pv(ans1);
                pv(ans2);

            } else {
                ++count;
            }
        }
        cout << "Pass % : " << (double)(count) / t << "\n";
    }

    void print(vector<int> ans) {
        // print ans here
        pv(ans);
    }
};

int main() {
    Solution s;

    // take inputs
    s.test();
    //call fn
    //s.print(s.findSubstring());

    return 0;
}
