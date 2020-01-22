#include<iostream>
#include<string>

using namespace std;

struct silla{
	
	string color;
	string tipo;
	string material;
	string marca;
	
};
typedef struct silla PSilla; //typedef es darle como un "apodo a la estructura" evita poner en todo el codigo struct silla

struct nodo{
	PSilla elemento;
	struct nodo *siguiente;
};
typedef struct nodo *Pila;

//prototipo de funciones
void initialize(Pila *s);
bool empty(Pila *s);
void push(Pila *s, PSilla e);
PSilla pop(Pila *s);
PSilla top(Pila *s);

int main(){
	Pila pilaDeSillas;
	initialize(&pilaDeSillas);
	
	bool continuar = true;
	
	do{
		char opcion = 's';
	//	cout << "\nCantidad actual de sillas: " << ;
		cout << "\nDesea apilar otra silla? (s/n): ";
		cin >> opcion; cin.ignore();
		
		if(opcion == 's'){
			PSilla unaSilla;
			cout << "\nColor: "; getline(cin, unaSilla.color);
			cout << "Tipo: "; getline(cin, unaSilla.tipo);
			cout << "Material: "; getline(cin, unaSilla.material);
			cout << "Marca: "; getline(cin, unaSilla.marca);
			push(&pilaDeSillas, unaSilla);
			
		}
		else if(opcion == 'n'){
			continuar = false;
		}
		else{
			cout << "Opcion no valida!" << endl;
		}
	
		
		
	}while(continuar);
	
	cout << "\nDesapilando sillas...\n";
	while(!empty(&pilaDeSillas)){
		PSilla SillaEncima = top(&pilaDeSillas);
		cout << "Silla : " << SillaEncima.color;
		cout << ", " << SillaEncima.tipo;
		cout << ", " << SillaEncima.material;
		cout << ", " << SillaEncima.marca << "\n";
		
		pop(&pilaDeSillas);
	}
	
	cout << "Pila de sillas vacia" << endl;
	
	return 0;
}

//implemento de funciones
void initialize(Pila *s){
    *s = NULL;
}

bool empty(Pila *s){
    return *s == NULL;
}

void push(Pila *s, PSilla e){
    struct nodo *unNodo = new struct nodo;
    unNodo->elemento = e;
    unNodo->siguiente = *s;
    
    *s = unNodo;
}

PSilla pop(Pila *s){
    if(!empty(s)){
        struct nodo *unNodo = *s;
        PSilla e = (*s)->elemento;
        *s = (*s)->siguiente;
        delete(unNodo);
        return e;
    }
    else{ // Underflow!
        PSilla sillaNoExiste;
        sillaNoExiste.color = " ";
        sillaNoExiste.tipo = " ";
        sillaNoExiste.material = " ";
        sillaNoExiste.marca = " ";
        return sillaNoExiste;
	}
}

PSilla top(Pila *s){
    if(!empty(s))
        return (*s)->elemento;
    else{ // Underflow!
        PSilla sillaNoExiste;
        sillaNoExiste.color = " ";
        sillaNoExiste.tipo = " ";
        sillaNoExiste.material = " ";
        sillaNoExiste.marca = " ";
        return sillaNoExiste;
	}
}
