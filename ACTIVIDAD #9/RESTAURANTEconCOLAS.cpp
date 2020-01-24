//POLLO CAMPERO

#include<iostream>
#include<string>

using namespace std;

struct Pedidos{
	string cliente;
	int mesa;
	int PiezasDePollo;
	int PapasFritas;
	int AderezoPicante;
	int Bebida;
};

typedef Pedidos T;
Pedidos noValido;

// Registros: nodo y Cola
struct Nodo{
    T elemento;
    struct Nodo* siguiente;
};

struct Cola{
    Nodo* frente;
    Nodo* final;
};

// Prototipos de funciones para Cola
void initialize(Cola *q);
bool empty(Cola *q);
T front(Cola *q);
T back(Cola *q);
void enqueue(Cola *q, T x);
T dequeue(Cola *q);
int size(Cola *q);

struct Restaurante{
    Cola colaPedidos;
    int combosPreparados;
};

Restaurante Campero;

//funciones del programa
void agregar();
void consultar();
void servir();
void vertodos();
void LimiteEntreFunciones();

int main(){
	//definiendo lo que retornaria una funcion si esta vacia la cola
	noValido.cliente = " ";
	noValido.mesa = -1;
	noValido.PiezasDePollo = -1;
	noValido.PapasFritas = -1;
	noValido.AderezoPicante = -1;
	noValido.Bebida = -1;
	
   initialize(&Campero.colaPedidos);
    Campero.combosPreparados = 0;
    
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\nBIENVENIDO A CAMPERO!\n\n";
        cout << "\n1) Agregar un pedido\n";
        cout << "2) Consultar el estado actual\n";
        cout << "3) Despachar un pedido\n";
        cout << "4) Ver todos los pedidos\n";
        cout << "5) Salir\n";
        cout << "Opcion elegida: ";
        cin >> opcion; cin.ignore();
        
        switch(opcion){
            case 1: agregar(); break;
            case 2: consultar(); break;
            case 3: servir(); break;
            case 4: vertodos(); break;
            case 5: continuar = false; break;
            default: cout << "Opcion invalida!\n"; break;
        }
    }while(continuar);
	
	
	return 0;
}
// Implementacion de funciones de la cola
void initialize(Cola *q){
    q->frente = NULL;
    q->final = NULL;
}

bool empty(Cola *q){
    return (q->frente==NULL) ? true : false;
}

T front(Cola *q){
    if(empty(q)){
        cout << "Underflow!" << endl;
        return noValido;
    }
    return (q->frente)->elemento;
}

T back(Cola *q){
    if(empty(q)){
        cout << "Underflow!" << endl;
        return noValido;
    }
    return (q->final)->elemento;
}

void enqueue(Cola *q, T x){
    Nodo *unNodo = new Nodo;
    unNodo->elemento = x;
    unNodo->siguiente = NULL;
    
    if(q->final==NULL)
        q->frente = unNodo;
    else
        (q->final)->siguiente = unNodo;
        
    q->final = unNodo;
}

T dequeue(Cola *q){
    if(empty(q)){
        cout << "Underflow!" << endl;
        return noValido;
    }
    Nodo *unNodo = q->frente;
    T x = unNodo->elemento;
    q->frente = unNodo->siguiente;
    if(q->frente==NULL)
        q->final = NULL;
    delete(unNodo);
    return x;
}

int size(Cola *q){
    Cola colaTemporal;
    initialize(&colaTemporal);
    
    int contador = 0;
    // Transfiriendo desde q hasta colaTemporal
    while(!empty(q)){
        T elemento = dequeue(q);
        enqueue(&colaTemporal, elemento);
        contador++;
    }
    // Transfiriendo desde colaTemporal hasta q
    while(!empty(&colaTemporal)){
        T elemento = dequeue(&colaTemporal);
        enqueue(q, elemento);
    }
    return contador;
}

//funciones del programa

void agregar(){
	
	LimiteEntreFunciones();
	  // Solicitar datos del pedido
    Pedidos unPedido;
    cout << "\nNombre del cliente: "; getline(cin, unPedido.cliente);
    cout << "Numero de la mesa: "; cin >> unPedido.mesa; cin.ignore();
    cout << "Piezas de Pollo: "; cin >> unPedido.PiezasDePollo; cin.ignore();
    cout << "Papas Fritas (bolsitas): "; cin >> unPedido.PapasFritas; cin.ignore();
    cout << "Aderezo Picante: "; cin >> unPedido.AderezoPicante; cin.ignore();
    cout << "Bebidas (CocaCola): "; cin >> unPedido.Bebida; cin.ignore();
    
    // Agregar a la cola
    enqueue(&Campero.colaPedidos, unPedido);
    
    
    LimiteEntreFunciones();
}

void consultar(){
	LimiteEntreFunciones();

	cout << "\nPedidos en espera: " << size(&Campero.colaPedidos) << endl;
    cout << "Total Combos por Preparar: " << size(&Campero.colaPedidos) << endl;
    cout << "Total Combos Preparados: " << Campero.combosPreparados << endl;
    
    LimiteEntreFunciones();
}

void servir(){
	LimiteEntreFunciones();
	
	if(empty(&Campero.colaPedidos)){
		cout << "\nNO HAY PEDIDOS A DESPACHAR!!" << endl;
	}
	else{
		Pedidos pedidoDespachado = dequeue(&Campero.colaPedidos);
	    cout << "\nCliente " << pedidoDespachado.cliente << " su pedido esta listo\n";
	    cout << "Se encuentra en la mesa " << pedidoDespachado.mesa << endl;
	    Campero.combosPreparados++;
	}
	LimiteEntreFunciones();
}

void vertodos(){
	LimiteEntreFunciones();
	
	Cola colaTemporal;
    initialize(&colaTemporal);
    
    if(empty(&Campero.colaPedidos)){
    	cout << "\nNO HAY PEDIDOS!!" << endl;
	}
	else{
		
	   // Transfiriendo desde laBendicion.colaPedidos hasta colaTemporal
	    while(!empty(&Campero.colaPedidos)){
	        Pedidos unPedido = dequeue(&Campero.colaPedidos);
	        enqueue(&colaTemporal, unPedido);
	        
	        cout << "\nInfo del pedido: " << unPedido.cliente << "\n";
	        cout << "\tPiezas de Pollo: " << unPedido.PiezasDePollo << "\n";
	        cout << "\tPapas Fritas (bolsitas): " << unPedido.PapasFritas << "\n";
	        cout << "\tAderezo Picante: " << unPedido.AderezoPicante << "\n";
	        cout << "\tBebidas (CocaCola): " << unPedido.Bebida << "\n\n";
	    }
	    // Transfiriendo desde colaTemporal hasta laBendicion.colaPedidos
	    while(!empty(&colaTemporal)){
	        T elemento = dequeue(&colaTemporal);
	        enqueue(&Campero.colaPedidos, elemento);
	    }
		
	}
 	LimiteEntreFunciones();
}

//dibujar un limite entre menus para que se vea un poco mas ordenado en consola
void LimiteEntreFunciones(){
	
	cout << "\n";
	for(int i = 0; i <50; i++){
		cout << "=";
	}
	cout << "\n";
}
