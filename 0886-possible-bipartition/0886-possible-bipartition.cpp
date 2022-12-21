class Solution {
public:
    vector <int> f;
int find(int x) {
    if (f[x] != x)
        f[x] = find(f[x]);
    return f[x];
}
void unify(int x, int y) {
    x = find(x);
    y = find(y);
    f[x] = y;
}
bool possibleBipartition(int n, vector<vector<int>>& a) {
    f.resize(n + 1);
    iota(f.begin(), f.end(), 0);
    vector <vector <int>> m(n + 1);
    for (auto &z : a) {
        m[z[0]].push_back(z[1]);
        m[z[1]].push_back(z[0]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m[i].size(); j++) {
            if (find(i) == find(m[i][j]))
                return false;
            unify(m[i][0], m[i][j]);
        }
    }
    return true;
}
};