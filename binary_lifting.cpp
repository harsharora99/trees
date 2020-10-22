#include<bits/stdc++.h>
using namespace std ;

const int N = 2e5 + 10 , L = 20 ;

vector < int > g[N] ;
int up[N][L] ;

int n ;

void read ()
{
    cin >> n ;

    for ( int i = 1 ; i < n ; i ++ )
    {
        int a , b ;
        cin >> a >> b ;

        g[a].push_back ( b ) ;
        g[b].push_back ( a ) ;
    }
}

int lev[N] ;

void dfs ( int node )
{
    for ( auto &i : g[node] )
    {
        if ( i == 1 || lev[i] > 0 )
            continue ;

        lev[i] = 1 + lev[node] ;
        up[i][0] = node ;

        dfs ( i ) ;
    }
}

void fill_data ()
{
    for ( int j = 1 ; j < L ; j ++ )
    {
        for ( int i = 1 ; i <= n ; i ++ )
        {
            up[i][j] = up[up[i][j - 1]][j - 1] ;
        }
    }
}

int lca ( int a , int b )
{
    if ( lev[a] > lev[b] )
        swap ( a , b ) ;

    int diff = lev[b] - lev[a] ;

    for ( int j = 0 ; j < L ; j ++ )
    {
        if ( (diff & (1 << j)) )
        {
            b = up[b][j] ;
        }
    }

    if ( a == b )
        return a ;

    for ( int j = L - 1 ; j > -1 ; j -- )
    {
        if ( up[a][j] != up[b][j] )
            a = up[a][j] , b = up[b][j] ;
    }

    return up[a][0] ;
}

int main()
{
    read() ;

    dfs ( 1 ) ;
    fill_data () ;

    int queries ;
    cin >> queries ;

    while ( queries -- )
    {
        int a , b ;
        cin >> a >> b ;

        cout << lca ( a , b ) << "\n" ;
    }

    return 0 ;
}
