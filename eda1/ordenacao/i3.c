void i(int v[], int n){
	int i, j, atual;

	for(i=1; i<n; i++){
		atual = v[i];
		for(j=i; (j>0)&&(atual<v[j-1]); j--){
			v[j] = v[j-1];
		}
		v[j] = atual;
	}
}
