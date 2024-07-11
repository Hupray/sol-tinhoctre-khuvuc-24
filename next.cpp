#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fi first
#define se second
#define bit(mask , i) ((mask >> i) & 1)

using namespace std;

const ll inf = 1e18 , mod = 1e9 + 7 , maxn = 1e6 + 5;

ll C[61][61];

void preprocess(int mx)
{
    for(int n = 1 ; n <= mx ; n++)
    {
        ll ans = 1;
        for(int k = 1 ; k <= n / 2 ; k++)
        {
            ans *= n - k + 1;
            ans /= k;
            C[n][k] = ans;
            C[n][n - k] = ans;
        }
    }
}

ll comb(int n , int k)
{
    if(k < 0 || k > n) return 0;
    if(k == n || k == 0) return 1;
    k = min(k , n - k);
    return C[n][k];
}

ll get(ll n , ll d)
{
    ll ans = 0;
    if(__builtin_popcount(n) == d) ans++;
    int on_bits = 0 ;
    for(int i = 0 ; (1ll << i) <= n ; i++) if(bit(n , i))
    {
        on_bits ++;
        ll mask = n ^ (1ll << i);
        ans += comb(i - 0 , d - (__builtin_popcount(n) - on_bits));
    }
    return ans;
}

void sol()
{
    ll n , k; cin >> n >> k;
    int d = __builtin_popcountll(n);
    ll bc = get(n , d);
    k = k + bc;
    ll ans = -1;
    ll l = n + 1 , r = 1e15;
    while(l <= r)
    {
        ll mid = (l + r) / 2;
        if(get(mid , d) >= k)
        {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans;
}

int main() {
    fast;
    ///*
    preprocess(60);
    int t; cin >> t;
    while(t--)
    {
        sol();
        cout << '\n';
    }
    //*/
    /*
    for(int i= 1 ; i <= 20 ; i++)
    {
        cout << i << ' ' ;
        for(int j = 10 ; j >= 0 ; j--) cout << bit(i , j);
        cout << ' ' << get(i , 1)<< '\n';
    }
    */
    return 0;
}
