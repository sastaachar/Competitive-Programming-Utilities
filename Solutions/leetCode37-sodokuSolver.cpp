#include <bits/stdc++.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

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

class Solution {
   public:
    vector<char> valid(int i, int j, vector<vector<char>>& board) {
        int boxNo = (i / 3) * 3 + j / 3;
        int boxSx = (boxNo / 3) * 3, boxSy = (boxNo % 3) * 3;
        vi row(9, 0), clm(9, 0), box(9, 0);
        vector<char> validNums;
        fr(9, k) {
            if (board[k][j] != '.') clm[board[k][j] - '1'] = 1;

            if (board[i][k] != '.') row[board[i][k] - '1'] = 1;

            if (board[boxSx + k / 3][boxSy + k % 3] != '.') box[board[boxSx + k / 3][boxSy + k % 3] - '1'] = 1;
        }

        fr(9, k) {
            if (!row[k] && !clm[k] && !box[k])
                validNums.pb('1' + k);
        }

        return validNums;
    }
    void printN(int i, int j) {
        int boxNo = (i / 3) * 3 + j / 3;
        cout << boxNo << " ";
        int boxSx = (boxNo / 3) * 3, boxSy = (boxNo % 3) * 3;
        /*
        fr(9, k) {
            cout << boxSx + k / 3 << boxSy + k % 3 << " ";
            if (k % 3 == 2) cout << "\n";
        }*/
    }

    bool solved(vector<vector<char>>& board) {
        fr(9, i) {
            fr(9, j) {
                if (board[i][j] == '.') return false;
            }
        }
        return true;
    }

    // function here
    void solveSodoku(vector<vector<char>>& board) {
        this->print(board);
        sleep(0.8);
        system("clear");
        fr(9, i) {
            fr(9, j) {
                if (board[i][j] == '.') {
                    vector<char> validNums = valid(i, j, board);
                    fr(validNums.size(), k) {
                        board[i][j] = validNums[k];
                        solveSodoku(board);
                        board[i][j] = '.';
                    }
                    return;
                }
            }
        }
        this->print(board);
    }

    void print(vector<vector<char>>& board) {
        // print ans here
        fr(9, i) {
            fr(9, j) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "-----------------\n";
    }
};

int main(int argc, char* argv[]) {
    //    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Solution s;
    // take inputs

    vector<vector<char>> board(9, vector<char>(9, '.'));
    fr(9, i) {
        fr(9, j) {
            cin >> board[i][j];
        }
    }

    //call fn
    s.solveSodoku(board);
    s.print(board);

    return 0;
}