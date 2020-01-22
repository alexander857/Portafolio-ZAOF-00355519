#include<iostream>

using namespace std;

//prototipo de la funcion
int buscarBinario(int* A, int x, int &low, int &high);

int main(){
	//variables declaradas
	int x = 0, A[] = {1,3,4,5,17,18,31,33}, low = 0, high = 7, N = 0;
	
	//se pide el numero que se buscara al usuario
	cout << "Ingrese un numero a buscar: "; cin >> x;
	
	//se llama la funcion que busca el numero en el arreglo
	N = buscarBinario(A,x,low,high);
	
	if(N == -1){
		cout << "\nEl numero "<< x <<" no esta en el arreglo" << endl;
	}
	else{
		cout <<"\nEl numero "<< x <<" si esta en el arreglo, en la posicion "<< N << endl;
	}
	
	
	
	return 0;
}

//funcion que busca el numero de forma binaria y recursivamente
int buscarBinario(int* A, int x, int &low,int &high){
		
	if(low > high){ //caso base
		return -1;			  //se retorna -1 si el numero no se encontro				
	}
		
	int mid = (low + high) / 2;
		
	if(x == A[mid]){
		return mid; //si el numero se encontro se retorna la posicion donde esta en el arreglo
	}
		
	else if(x < A[mid]){ //si el numero es menor se busca en la primera mitad del arreglo
		
		high = mid - 1;	
		buscarBinario(A, x, low, high);				
			
	}
	else if(x > A[mid]){ //si el numero es mayor se busca en la segunda mitad del arreglo
		low = mid + 1; 
		buscarBinario(A, x, low, high);
		
	}	

}
