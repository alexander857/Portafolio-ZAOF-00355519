//SUMA DE NUMEROS NATURALES DESDE 1 HASTA N
#include<iostream>

using namespace std;


int suma(int num){
	int respuesta = 0;
	
	if(num == 1){ //si llega el numero a 1, se muestra el caso base
		
		cout<<"Num = " << num << " caso base " << endl;
		
		respuesta = 1;
	}
	else{
		int N = num - 1;
		respuesta = num + suma(N);
		cout << "n = " << num << " N = " << N << endl; //se van mostrando los numeros en cada recursion
		
		
	}
	
 return respuesta;	
}


int main(){
	int n = 0;
	
	cout << "Digite un numero: "; cin >> n; //pedimos al usuarion un numero entero
	
	int r = suma(n);  //se llama la funcion suma donde se hace la recurcion
	
	cout << "La suma desde 1 hasta el numero ingresado es: " << r << endl; //se muestra suma total
	
	return 0;
}
