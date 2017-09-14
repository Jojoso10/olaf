const int MAXC = 1000;
ll C[MAXC+1][MAXC+1];
forn(i, MAXC + 1){ //C[n][k] = C(n, k)
    C[i][0] = C[i][i] = 1;
    forr(k, 1, i) C[i][k] = (C[i-1][k] + C[i-1][k-1]) % MOD;
}
ll lucas(ll n, ll k, int p){ // Calcula C(n, k)%p teniendo C[p][p] 
    ll ans = 1;              // precalculado.
    while(n + k){ ans = (ans * C[n%p][k%p]) % p; n/=p; k/=p; }
    return ans;
}

