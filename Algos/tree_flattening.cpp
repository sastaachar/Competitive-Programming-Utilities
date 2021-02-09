#include <bits/stdc++.h>
using namespace std;

/*
    ! TREE FLATTENING - euler's tour

*/

const int max_n = 100;
vector<int> tree[max_n];
/* 
    adjacency
    [vi , vi .. .. vi(99)]
*/

int flatTree[2 * max_n], startTree[max_n], endTree[max_n];
int timer = 0;

void flattenTree(int cur, int parent) {
    startTree[cur] = timer;
    flatTree[timer] = cur;
    ++timer;

    for (int child : tree[cur])
        if (child != parent)
            flattenTree(child, cur);

    endTree[cur] = timer;
    flatTree[timer] = cur;
    ++timer;
}

void addEdge(int a, int b) {
    tree[a].push_back(b);
    tree[b].push_back(a);
}

void printTrees(int s) {
    cout << "Flat tree : \n";
    for (int i = 0; i < 2 * s; i++) {
        cout << flatTree[i] << " ";
    }
    cout << "\nStarting tree : \n";
    for (int i = 0; i < s; i++) {
        cout << startTree[i] << " ";
    }
    cout << "\nTerminating tree : \n";
    for (int i = 0; i < s; i++) {
        cout << endTree[i] << " ";
    }
    cout << "\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    /*
                    1
                2       3
              4   5   6   0
  
        0 -> 3
        1 -> 2 3
        2 -> 1 4 5
        3 -> 0 1 6
        4 -> 2 
        5 -> 2
        6 -> 3

        taking 1 as root

    */

    addEdge(0, 3);
    addEdge(1, 2), addEdge(1, 3);
    addEdge(2, 4), addEdge(2, 5);
    addEdge(3, 6);

    // taking 1 as root (-1 cause no parent)
    flattenTree(1, -1);
    printTrees(7);

    // taking 3 as root (-1 cause no parent)
    flattenTree(3, -1);
    printTrees(7);

    return 0;
}
