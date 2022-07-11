#include "bits/stdc++.h"
using namespace std;
#define ll long long

vector<ll> bits;

void addBit(ll x)
{
    for(ll bit = 0; bit < 32; bit++) {
        if(x & (1ll << bit)) bits[bit]++;
    }
}

void removeBit(ll x) 
{
    for(ll bit = 0; bit < 32; bit++) {
        if(x & (1ll << bit)) bits[bit]--;
    }
}

ll getOR()
{
    ll OR = 0;
    for(ll bit = 0; bit < 32; bit++) {
        if(bits[bit]) OR += (1ll << bit);
    }
    return OR;
}

void solve()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];

    ll j = 0;
    ll sz = LONG_MAX;
    bits = vector<ll>(32, 0);

    for(ll i = 0; i < n; i++) {
        addBit(a[i]);

        if(getOR() >= x) {
            while(getOR() >= x and j <= i) {
                removeBit(a[j]);
                j++;
            }
            sz = min(sz, i-j+2);
        }
    }

    j = 0;
    fill(bits.begin(), bits.end(), 0);
    vector<pair<ll, ll>> ans;

    for(ll i = 0; i < n; i++) {
        addBit(a[i]);

        if(getOR() >= x) {
            while(getOR() >= x and j <= i) {
                removeBit(a[j]);
                j++;
            }
            if(i-j+2 == sz) ans.push_back({j-1, i});
        }
    }

    cout << ans.size() << '\n';
    for(pair<ll, ll> it: ans) {
        cout << it.first+1 << ' ' << it.second+1 << '\n';
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t; cin >> t;
    for(ll i = 0; i < t; i++) solve();
}
