#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fi first
#define se second
#define bit(mask , i) ((mask >> i) & 1)

using namespace std;

const ll inf = 1e18 , mod = 1e9 + 7 , maxn = 1e5 + 5;

ll d , sum[maxn] , cnt;
int n , k , a[maxn] , MIN[21][maxn];
bool check[maxn];

void build() {
    for(int i = 1 ; i <= n ; i++) MIN[0][i] = a[i];
    for(int k = 1 ; (1 << k) <= n ; k++) {
        for(int i = 1 ; i + (1 << k) - 1 <= n ; i++) {
            MIN[k][i] = min(MIN[k - 1][i] , MIN[k - 1][i + (1 << (k - 1))]);
        }
    }
}

int get(int l , int r) {
    if(l > r) return 1e9;
    int k = 31 - __builtin_clz(r - l + 1);
    return min(MIN[k][l] , MIN[k][r - (1 << k) + 1]);
}

ll getsum(ll l , ll r) {
    l = l - 1;
    ll sum1 = (l / n) * sum[n] + sum[l % n];
    ll sum2 = (r / n) * sum[n] + sum[r % n];
    return sum2 - sum1;
}

int getmin(ll l , ll r)
{
    if(r <= n) return get(l , r);
    int ans = 1e9 ;
    l = l % n;
    if(l == 0)l = n;
    r %= n;
    if(r == 0) r = n;
    if(l + d - 1 <= n)
    {
        return get(l , l + d - 1);
    }
    ans = min(ans , get(l , n));
    ans = min(ans , get(1 , r));
    if((l + d - n) / n  > 0)ans = min(ans , get(1 , n));
    return ans;
}

int main() {
    fast;
    cin >> n >> k >> d;
    for(int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    build();
    for(ll i = 1 ; i <= min((ll)n , n * k - d + 1) ; i++) {
        ll j = i + d - 1;
        if(2 * getmin(i , j) > (double)getsum(i , j) / d) 
        {
            check[i] = true;
        }
        //cout << check[i] << ' ';
        //cout << 2 * getmin(i , j) << ' ' << getsum(i , j) << '\n';
    }
    ll N = n * k - d + 1;
    for(int i = 1 ; i <= n ; i++) if(check[i])
    {
        cnt += N / n + (N % n >= i);
    }
    cout << cnt;
    return 0;
}
