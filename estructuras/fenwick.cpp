// Para 2D: tratar cada columna como un Fenwick Tree, 
// agregando un for anidado en cada operacion.
struct Fenwick {
  static const int sz = 1000001;
  tipo t[sz];
  void adjust(int p, tipo v){ // p en [1, sz), O(lg n)
    for(int i = p; i < sz; i += (i & -i)) t[i] += v; 
  }
  tipo sum(int p){ // Suma acumulada en [1, p], O(lg n)
    tipo s = 0;
    for(int i = p; i; i -= (i & -i)) s += t[i];
    return s;
  }
  tipo sum(int a, int b){ return sum(b) - sum(a - 1); }
  // Obtener mayor valor con suma acumulada menor o igual que x.
  // Para el menor, pasar x - 1 y sumar 1 al resultado.
  int getind(tipo x){ // O(lg n)
    int idx = 0, mask = n;
    while(mask && idx < n) {
      int z = idx + mask;
      if(x >= t[z])
        idx = z, x -= t[z];
      mask >>= 1;
    }
    return idx;
  }
};
