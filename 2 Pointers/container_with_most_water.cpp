#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// Macros
// ---------------------------
#define int long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define F first
#define S second

// ---------------------------
// Constants
// ---------------------------
const int MOD = 1e9 + 7;
const int INF = 1e18;
const int N = 2e5 + 5;

// ---------------------------
// Debugging Tools (only for local use)
// ---------------------------
#ifdef LOCAL
#define dbg(x)           \
    cerr << #x << " = "; \
    _print(x);           \
    cerr << endl;
#else
#define dbg(x)
#endif

void _print(int x) { cerr << x; }
void _print(string x) { cerr << x; }
void _print(char x) { cerr << x; }
void _print(double x) { cerr << x; }
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class U>
void _print(pair<T, U> p)
{
    cerr << "{";
    _print(p.F);
    cerr << ",";
    _print(p.S);
    cerr << "}";
}

// ---------------------------
// Fast IO
// ---------------------------
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

// ---------------------------
// Modular Arithmetic
// ---------------------------
int mod_add(int a, int b) { return ((a % MOD + b % MOD) % MOD + MOD) % MOD; }
int mod_sub(int a, int b) { return ((a % MOD - b % MOD) % MOD + MOD) % MOD; }
int mod_mul(int a, int b) { return ((a % MOD * b % MOD) % MOD + MOD) % MOD; }
int mod_pow(int a, int b)
{
    int res = 1;
    a %= MOD;
    while (b > 0)
    {
        if (b & 1)
            res = mod_mul(res, a);
        a = mod_mul(a, a);
        b >>= 1;
    }
    return res;
}
int mod_inv(int a)
{
    return mod_pow(a, MOD - 2); // Fermat's little theorem
}

void solve()
{
    vector<int> heights = {1,2,3,4,4,3,2,1};
    int i = 0, j = heights.size() - 1;
    int max = 0;

    while (i < j)
    {
        int prod = (min(heights[i], heights[j])) * (j - i);
        if (prod > max)
            max = prod;
        if (heights[i] > heights[j])
            j--;
        else
            i++;
    }

    cout << max;
}

// ---------------------------
// Main Function
// ---------------------------
int32_t main()
{
    fastio();

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
