//arreglo de forma recursita mostrar elementos

#include<iostream>

using namespace std;

//prototipos de las funciones
int MostrandoArreglo(int array[10], int& N);

int main(){
	//declaracion de variables
	int tam = 10, N = 0;
	int array[tam] = {1,2,3,4,5,6,7,8,9,10};
	
	
	MostrandoArreglo(array,N); //se llama la funcion de mostrar los elementos del arreglo
	
	return 0;
}

int MostrandoArreglo(int array[], int& N){
	//mostrando de forma recursiva los numeros
	
	if(N == 10){ //si N (que es enviada por referencia a la funcion y tiene valor de 0) llega a 10, termina todo, ya que se habran
				//recorrido todos los espacios del arreglo
		
		return 0;
		
	}
	else{
		
		cout << array[N] << " "; //se muestra el primer elemento en la posicion N = 0
		
		N++;   //N aumenta en 1
		
		MostrandoArreglo(array,N); //el la siguiente llamada N es 1 asi que mostrara el elemento en la posicion 1 y volvera a aumentar N+
									//y asi hasta N == 10
		
	}
	
}
