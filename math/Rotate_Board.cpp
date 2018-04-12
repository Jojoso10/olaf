//rotates matrix A(n, m) 90 degrees clockwise
//using auxiliary matrix aux(faster)
void rot_mat(tipo (&A)[MAXN][MAXN]){
	tipo aux[MAXN][MAXN];
	forn(i, n) forn(j, m) aux[m-j-1][i] = A[i][j];
	memcpy(A, aux, sizeof(A)); swap(n, m);
}

