// Dado un arreglo y una operacion asociativa con neutro:
// get(i, j) opera sobre el rango [i, j).
typedef int node; // Tipo de los elementos del arreglo
typedef int alt;  // Tipo de la alteracion
#define operacion(x, y) (x + y)
const node neutro = 0; const alt neutro_alt = 0;
#define MAXN 100000
struct RMQ {
	int sz;
	node t[4*MAXN];
	alt dirty[4*MAXN];
	node &operator [](int p){ return t[sz + p]; }
	void init(int n){ // O(n lg n)
		sz = 1 << (32 - __builtin_clz(n));
		forn(i, 2*sz){
      t[i] = neutro;
      dirty[i] = neutro_alt;
    }
	}
	void push(int n, int a, int b){ // Propaga el dirty a sus hijos
		if(dirty[n] != neutro_alt){
			t[n] += dirty[n]*(b - a); // Altera el nodo 
			if(n < sz){
				dirty[2*n] += dirty[n];
				dirty[2*n + 1] += dirty[n];
			}
			dirty[n] = 0;
		}
	}
	node get(int i, int j, int n, int a, int b){ // O(lg n)
		if(j <= a || i >= b) return neutro;
		push(n, a, b); // Corrige el valor antes de usarlo
		if(i <= a && b <= j) return t[n];
		int c = (a + b)/2;
		return operacion(get(i, j, 2*n, a, c), get(i, j, 2*n + 1, c, b));
	}
	node get(int i, int j){ return get(i, j, 1, 0, sz); }
	// Altera los valores en [i, j) con una alteracion de val
	void alterar(alt val, int i, int j, int n, int a, int b){//O(lgn)
		push(n, a, b);
		if(j <= a || i >= b) return;
		if(i <= a && b <= j){
			dirty[n] += val;
			push(n, a, b);
			return;
		}
		int c = (a + b)/2;
		alterar(val, i, j, 2*n, a, c); alterar(val, i, j, 2*n + 1, c, b);
		t[n] = operacion(t[2*n], t[2*n + 1]);
	}
	void alterar(alt val, int i, int j){ alterar(val, i, j, 1, 0, sz); }
} rmq;
