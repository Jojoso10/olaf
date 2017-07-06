//For 2D threat each column as a Fenwick tree, by adding a nested for in each operation
struct Fenwick{
	static const int sz=1000001;
	tipo t[sz];
	void adjust(int p, tipo v){//valid with p in [1, sz), O(lgn)
		for(int i=p; i<sz; i+=(i&-i)) t[i]+=v; }
	tipo sum(int p){//cumulative sum in [1, p], O(lgn)
		tipo s=0;
		for(int i=p; i; i-=(i&-i)) s+=t[i];
		return s;
	}
	tipo sum(int a, int b){return sum(b)-sum(a-1);}
	//get largest value with cumulative sum less than or equal to x;
	//for smallest, pass x-1 and add 1 to result
	int getind(tipo x) {//O(lgn)
	  	int idx = 0, mask = n;
	  	while(mask && idx < n) {
	   		int z = idx + mask;
        if(x >= t[z])
		  		idx = z, x -= t[z];
	   		mask >>= 1;
	  	}
	  	return idx;
	}};
