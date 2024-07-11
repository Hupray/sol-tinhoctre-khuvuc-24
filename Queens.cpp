#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0);
#define ll long long
#define fi first
#define se second
#define bit(mask , i) ((mask >> i) & 1)
#define pli pair<ll , int>
using namespace std;

const ll inf = 1e18 , mod = 1e9 + 7 , maxn = 8 + 5;

int n;
ll a[maxn][maxn] , kq = 0;

void sol(int i , ll d1 , ll d2 , ll d3 , ll sum , int k , int slot)
{
    if(i >= n){
        if(k == 0) kq = max(kq , sum);
        return ;
    }
    if(slot < k) return ;
    if(k >= 0)for(int j = 0 ; j < n ; j++)
    {
        if(bit(d1 , j) == 0 && bit(d2 , i + j) == 0 && bit(d3 , i - j + n - 1) == 0) if(k > 0 && k >= slot - 1){
            sol(i + 1 , d1 | (1 << j) , d2 | (1 << (i + j)) , d3 | (1 << (i - j + n - 1)) , sum + a[i][j] , k - 1 , slot - 1);
            //cout << i << ' ' << j << ' ' << sum << '\n';
        }
        sol(i + 1 , d1 , d2 , d3 , sum , k , slot - 1);
    }
}
int main()
{
    fast
    int k ; cin >> n >> k;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++) cin >> a[i][j];
    sol(0 , 0 , 0 , 0 , 0 , k , n);
    cout << kq;
    return 0;
}
