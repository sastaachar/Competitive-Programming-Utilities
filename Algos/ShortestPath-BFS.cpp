#include <bits/stdc++.h>
using namespace std;

int conv(pair<int, int> pos, int w, int h) {
    // maps 2d cordinated to 1d
    // for ROW-MAJOR

    return pos.second * w + pos.first;
}

vector<pair<int, int>> getChildren(pair<int, int> pos, int w, int h) {
    // this represents the diagonal movements
    vector<vector<int>> offset = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    vector<pair<int, int>> children;

    for (int i = 0; i < offset.size(); i++) {
        int newX = offset[i][0] + pos.first, newY = offset[i][1] + pos.second;
        if (newX >= 0 && newX < w && newY >= 0 && newY < h)
            children.push_back({newX, newY});
    }

    return children;
}

int FindPath(const int nStartX, const int nStartY,
             const int nTargetX, const int nTargetY,
             const unsigned char* pMap, const int nMapWidth, const int nMapHeight,
             int* pOutBuffer, const int nOutBufferSize) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    pair<int, int> start = {nStartX, nStartY},
                   target = {nTargetX, nTargetY};

    map<int, int> parent;
    queue<pair<int, int>> q;

    q.push(start);
    parent[conv(start, nMapWidth, nMapHeight)] = -1;

    bool foundPath = false;
    while (!q.empty()) {
        pair<int, int> root = q.front();
        q.pop();

        if (root == target) {
            foundPath = true;
            break;
        }

        int rootI = conv(root, nMapWidth, nMapHeight);
        vector<pair<int, int>> children = getChildren(root, nMapWidth, nMapHeight);

        for (int i = 0; i < children.size(); i++) {
            int child = conv(children[i], nMapWidth, nMapHeight);
            if (pMap[child] == 1 && parent.find(child) == parent.end()) {
                q.push(children[i]);
                parent[child] = rootI;
            }
        }
    }

    if (!foundPath)
        return -1;

    int cur = conv(target, nMapWidth, nMapHeight);
    vector<int> temp;
    while (parent[cur] != -1) {
        temp.push_back(cur);
        cur = parent[cur];
    }

    if (nOutBufferSize < temp.size())
        return temp.size();

    for (int i = 0; i < temp.size(); i++) {
        pOutBuffer[i] = temp[temp.size() - 1 - i];
    }
    return temp.size();
}

int main() {
    unsigned char pMap[] = {0, 0, 1, 0, 1, 1, 1, 1, 1};
    int pOutBuffer[7];

    int len = FindPath(2, 0, 0, 2, pMap, 3, 3, pOutBuffer, 7);

    cout << len << "\n";
    for (int i = 0; i < len; i++) {
        cout << pOutBuffer[i] << " ";
    }
    cout << "\n";

    return 0;
}