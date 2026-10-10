#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if(!(cin >> n)) return 0;
    vector<pair<long long,long long>> pts(n);
    for(int i=0;i<n;++i){
        cin >> pts[i].first >> pts[i].second;
    }
    // sort by x-coordinate (all x are distinct)
    sort(pts.begin(), pts.end(), [](const auto &a, const auto &b){ return a.first < b.first; });
    // extract y-coordinates in x order, they form a permutation
    vector<long long> y;
    y.reserve(n);
    for(const auto &p: pts) y.push_back(p.second);
    long long ans = 0;
    long long max_suffix = LLONG_MIN;
    // scan from right to left: a point forms a rectangle with its next greater y to the right
    for(int i = n-1; i >= 0; --i){
        if(y[i] < max_suffix) ans++;
        else max_suffix = y[i];
    }
    cout << ans << "\n";
    return 0;
}
