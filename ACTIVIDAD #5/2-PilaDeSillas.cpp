//UTILIZANDO PILAS. PILA DE SILLAS

#include<iostream>
#include<string>
#include<stack>

using namespace std;

struct silla{
	
	string color;
	string tipo;
	string material;
	string marca;
	
};

typedef struct silla PSilla;

int main(){
	
	stack<PSilla> PilaDeSillas;
	
	bool continuar = true;
	
	do{
		
		char opcion = 's';
		cout << "\nCantidad actual de sillas: " << PilaDeSillas.size();
		cout << "\nDesea apilar otra silla? (s/n): ";
		cin >> opcion; cin.ignore();
		
		if(opcion == 's'){
			PSilla UnaSilla;
			cout << "\nColor: "; getline(cin, UnaSilla.color);
			cout << "Tipo: "; getline(cin, UnaSilla.tipo);
			cout << "Material: "; getline(cin, UnaSilla.material);
			cout << "Marca: "; getline(cin, UnaSilla.marca);
			PilaDeSillas.push(UnaSilla);
		}
		else if(opcion == 'n'){
			continuar = false;
		}
		else{
			cout << "Opcion Invalida!";
		}
		
	}while(continuar);
	
	cout << "\nDesapilando sillas...\n";
	while(!PilaDeSillas.empty()){
		
		PSilla SillaEncima = PilaDeSillas.top();
		cout << "Silla : " << SillaEncima.color;
		cout << ", " << SillaEncima.tipo;
		cout << ", " << SillaEncima.material;
		cout << ", " << SillaEncima.marca << "\n";
		
		PilaDeSillas.pop();
		
	}
	
	cout << "Pila de sillas vacia" << endl;
	
	return 0;
}
