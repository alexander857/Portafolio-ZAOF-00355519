//buscar un elemento en un arreglo de forma recursiva

#include<iostream>

using namespace std;

//prototipos de las funciones
int BuscarElemento(int arreglo[10], int elemento, int& N);

int main(){
	//declaracion de variables
	int elemento = 0, N = 0, Valor = 0;
	int arreglo[10] = {1,2,3,4,5,6,7,8,9,10};
	
	//pedimos el elemento al usuario
	cout << "Ingrese un numero entero: "; cin >> elemento;
	
	Valor = BuscarElemento(arreglo,elemento,N); //se llama la funcion que busca el elemento que retorna 1 si lo encontro y 0 si no
	
	//se verifica si se encontro o no el elemento en el arreglo
	if(Valor == 1){
		
		cout << "\nEl numero " << elemento << " ha sido encontrado!" << endl;
		
	}
	else{
		
		cout << "\nEl numero " << elemento << " no ha sido encontrado!" << endl;
		
	}
	return 0;
}

//funcion que busca el elemento que ingeso el usuario de forma recursiva
int BuscarElemento(int arreglo[10], int elemento, int& N){
	
	if(elemento == arreglo[N]){ //si el elemento que ingreso el usuario se encuentra en el arreglo, de una vez se retorna 1
		
		return 1;
		
	}
	else if(N == 10){ //si N == 10 es porque ya se recorrio todo el arreglo y no se hayo el elemento, retorna 0.
		 
		return 0;
		
	}
	else{
		//si el elemento en la posicion N aun no es igual al del usuario, N aumenta en 1
		N++;
		
		//se hace la llamada recursiva y hoy buscara en la posicion N = 1, si no lo encuentra, N aumenta de nuevo y asi hasta encontrarlo o no.
		BuscarElemento(arreglo,elemento,N);
		
	}
	
}
