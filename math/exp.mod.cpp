ll pot(ll b, ll e){ // O(log e)
	if(!e) return 1;
	ll q = pot(b, e/2); q = (q * q) % MOD;
	return (e % 2 ? (b * q) % MOD : q);
}
