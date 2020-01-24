#include <iostream>
#include <string>
using namespace std;

struct continente{
	
	string nombre;
	string capital;
	int Habitantes;
	int PromEdad;
	
};

struct continente Paises[5];
int CantidadPaises = 0;

void entrada(), buscarPais(), PoblacionTotal(), CapitalMayorPoblacion(), PromEdad();

int main(){
	
	bool continuar = true;
	
	do{
		int opcion = 0;
		
		cout<<"\n1. Ingresar un Pais\n";
		cout<<"2. Buscar un Pais\n";
		cout<<"3. Poblacion Total del continente\n"; 
		cout<<"4. Capital con mayor poblacion\n";
		cout<<"5. Promedio de edad del continente\n";
        cout <<"6. Salir\n";
        cout<<"Opcion: ";
        cin>>opcion;
        cout<<"\n";
        cin.ignore();
		
		switch(opcion){
			
			case 1: entrada(); break;
			case 2: buscarPais(); break;
			case 3: PoblacionTotal(); break;
			case 4: CapitalMayorPoblacion(); break;
			case 5: PromEdad(); break;
			case 6: continuar = false;
			
		}
		cout<<"\n";
		
	}while(continuar);
	
	return 0;
}

//se ingresan paises por el usuario
void entrada(){
	
	if(CantidadPaises < 5){
		
		cout<<"\nDigite el Pais: ";
		getline(cin, Paises[CantidadPaises].nombre);
		cout<<"Digite la capital: ";
		getline(cin, Paises[CantidadPaises].capital);
		cout<<"Digite el numero de habitantes: ";
		cin>>Paises[CantidadPaises].Habitantes;
		cout<<"Digite el promedio de Edad: ";
		cin>>Paises[CantidadPaises].PromEdad;
		
		CantidadPaises++;
		
	}
	else cout<<"Error, Ya no hay espacio!\n";
	
}

//busca un pais guardado
void buscarPais(){
   
    string unPais;
    
    cout << "Ingresar Pais a buscar: ";
    
    getline(cin, unPais);
    
    
    for (int i = 0; i < CantidadPaises; i++){
    	
        if(unPais.compare(Paises[i].nombre) == 0){
        	
            cout << "Informacion del Pais:\n";          
            cout << "Nombre: " << Paises[i].nombre <<endl;
            cout << "Capital: " << Paises[i].capital <<endl;
            cout << "Habitantes: " << Paises[i].Habitantes <<endl;
            cout << "Promedio de Edad: " << Paises[i].PromEdad <<endl;
          
            return;
        }
    }
    
    cout << "El pais que buscas no esta registrado!\n";
}

//calcula poblacion total del continente
void PoblacionTotal(){
	
	int TotalC = 0;
	
	for(int i = 0; i < CantidadPaises; i++){
		
		TotalC += Paises[i].Habitantes;
		
	}
	
	cout<<"Total de Habitantes del continente: "<<TotalC;
	cout<<"\n";
	
}

//funcion que busca el pais con la mayor cantidad de habitantes	
void CapitalMayorPoblacion(){
	
	string MayorP = "ninguno"; //variable que guarla el nombre de la capital con mayor # de habitantes
	int mayor = 0;            //vaiable que va guardando la cantidad de habitantes que tiene esa capital con mayor #
	
	for(int i = 0; i < CantidadPaises; i++){
		
		//se entra al condicional solo si la cantidad de habitantes en la posicion[i] es mayor a la que tiene guardada la variable mayor
		
		if(Paises[i].Habitantes > mayor){  //si el # de habiatntes es mayor a la variable mayor
			
			mayor = Paises[i].Habitantes; //la variable mayor guardara la cantidad de habiatantes
			MayorP = Paises[i].capital; //y la variable MayorP el nombre de la capital que tiene el mayor
			
		}
		
	}
	
	//se muestra el nombre de la capital con mayor # y sus habiatantes	
	cout<<"La capital con la mayor poblacion es: "<<MayorP<<" con "<<mayor<<" habitantes"<<endl; 
	
}

//fundion que calcula el promedio de edad del continente
void PromEdad(){
	int SumEdad = 0;
	int PromEdad = 0;
	
	for(int i = 0; i < CantidadPaises; i++){
		
		SumEdad += Paises[i].PromEdad;    //variable sumEdad acumula los promedios de edad de cada pais del continente
		
	}
	
	//se divide la suma total de los promedios de edad y se dividen entre el numero de paises que hay y se guarda el dato en PromEdad
	PromEdad = SumEdad/CantidadPaises;  
	
	cout<<"El promedio de edad del continente es: "<<PromEdad; //se muestra el promedio del continente
	
}	
