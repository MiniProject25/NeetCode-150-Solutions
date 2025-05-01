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
    vector<vector<int>> board;
    unordered_set<char> rows;
    unordered_set<char> cols;
    unordered_set<char> sq;

    // for the rows
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != '.' && rows.find(board[i][j]) != rows.end())
                cout << false;
            if (board[i][j] != '.')
                rows.insert(board[i][j]);
        }
        rows.clear();
    }

    cout << "Done with the rows!\n";

    // for the cols
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[j][i] != '.' && cols.find(board[j][i]) != cols.end())
                cout << false;
            if (board[j][i] != '.')
                cols.insert(board[j][i]);
        }
        cols.clear();
    }

    cout << "Done with the cols!\n";

    // for the 3x3 squares
    int ctr = 0;
    int ctri = 0;
    int ctrj = 0;
    while (ctr < 9)
    {
        for (int i = ctri; i < ctri + 3; i++)
        {
            for (int j = ctrj; j < ctrj + 3; j++)
            {
                if (board[i][j] != '.' && sq.find(board[i][j]) != sq.end())
                {
                    cout << "Failed at i = " << i << " j = " << j << "\n";
                    cout << false;
                }

                if (board[i][j] != '.')
                    sq.insert(board[i][j]);
                cout << "i: " << i << " j: " << j << '\n';
            }
        }
        ctr++;
        ctrj = (ctrj != 6) ? ctrj + 3 : 0;
        if (ctr == 3 || ctr == 6)
        {
            ctri += 3;
        }
        sq.clear();
    }

    cout << "Done with the Squares!\n";

    cout << true;
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
