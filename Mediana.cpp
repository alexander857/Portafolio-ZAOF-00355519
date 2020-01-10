//MEDIANA DE UN ARREGLO DE ENTEROS

#include<iostream>
#include<math.h>

using namespace std;

//prototipos de las funciones

int main(){
	//declaracion de variables
	int n = 0, m = 0, m2 = 0;
	float ME = 0.0;
	float numeros[n];
	
	//el usuario ingresa el tamaño del arreglo
	cout<<"Ingrese el tamano del arreglo: ";cin>>n;
	
	//llenando el arreglo
	cout<<endl;
	for(int i=0;i<n;i++){
		
		cout<<"Ingrese un entero: ";cin>>numeros[i];
		
	}
	cout<<"\n"<<endl;
	
	//calculando la mediana de los datos del areglo
	if(n%2 != 0){
		
		
		m = (n+1)/2; /*variable m resive el resultado de el total de elementos + 1 entre 2. (Formula para saber la ubicacion del numero que seria la mediana si el total de datos
						es impar*/
		
		for(int i=0;i<n;i++){
			
			ME = numeros[m-1]; /*ME resive el numero que esta en la posicion [m-1] del arreglo donde esta el numero que corresponde a la mediana. (m-1 ya que el arreglo empieza
								en 0, m = 3 significa la posicion 3 en el arreglo donde se han recorrido 4 casillas, por eso le resto 1 para que sea la posicion 3 real en el arreglo*/ 
			
		}
		
	}
	//si el numero de elementos del arreglo es par
	else{
		
		m2 = n/2;  /*variable m2 resive el resultado de dividir el numero de elementos entre 2 y ese resultado es la posicion en la que esta uno de los numeros que formaran la mediana
					ya que cuando el #elementos es par se toman los dos valores de en medio*/
					
		m = m2 + 1; //luego el siguiente numero para la mediana es el que esta en la siguiente posicion, por eso le sumo 1 y se guarda esa posicion en m
		
		for(int i=0;i<n;i++){
			
			ME = (numeros[m2-1] + numeros[m-1]) / 2; //la mediana sera sumar los 2 numeros que se encuentran en las posiciones encontradas y la suma dividirla entre 2 
			
		}
		
	}
	
	cout<<"La mediana de los numeros es: "<<ME<<endl; //se muestra la mediana en pantalla	
	
	return 0;
}

