void s(int v[], int aux){
	int menor, troca;

	for(int i=0; i<n-1; i++){
		menor = i;
		for(int j=i+1; j<n; j++){
			if(v[j] < v[menor]){
				menor = j;
			}
		}
		if(i != menor){
			troca = v[i];
			v[i] = v[menor];
			v[menor] = troca;
		}
	}
}

void b(int v[], int n){
	int aux, troca;

	for(int i=0; i<n-1; i++){
		troca = 0;
		for(int j=0; j<n-i-1; j++){
			if(v[j] > v[j+1]){
				troca = v[j];
				v[j] = v[j+1];
				v[j+1] = troca;
				troca = 1;
			}
		}
		if(!troca) break;
	}
}

void s(int v[], int n){
	int menor, troca;

	for(int i=0; i<n-1; i++){
		menor = i;
		for(int j=i+1; j<n; j++){
			if(v[j] < v[menor]){
				menor = j;
			}
		}
		if(i != menor){
			troca = v[i];
			v[i] = v[menor];
			v[menor] = troca;
		}
	}
}
