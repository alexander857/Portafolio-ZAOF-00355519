#include<iostream>

using namespace std;

int buscarBinario(int* A, int x, int &low, int &high);

int main(){
	int x = 0, A[] = {1,3,4,5,17,18,31,33}, low = 0, high = 7, N = 0;
	
	cout << "Ingrese un numero a buscar: "; cin >> x;
	
	N = buscarBinario(A,x,low,high);
	
	if(N == -1){
		cout << "\nEl numero "<< x <<" no esta en el arreglo" << endl;
	}
	else{
		cout <<"\nEl numero "<< x <<" si esta en el arreglo, en la posicion "<< N << endl;
	}
	
	
	
	return 0;
}

int buscarBinario(int* A, int x, int &low,int &high){
		
	if(low > high){
		return -1;							
	}
		
	int mid = (low + high) / 2;
		
	if(x == A[mid]){
		return mid;
	}
		
	else if(x < A[mid]){
		
		high = mid - 1;	
		buscarBinario(A, x, low, high);				
			
	}
	else if(x > A[mid]){
		low = mid + 1;
		buscarBinario(A, x, low, high);
		
	}	

}
