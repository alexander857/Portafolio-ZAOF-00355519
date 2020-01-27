#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Articulo{
    string nombre;
    int peso, fechaV;
    float precio;
    
};
vector<Articulo> bodega;

bool compNombre(Articulo a, Articulo b){
    return a.nombre < b.nombre;
}
bool compPeso(Articulo a, Articulo b){
    return a.peso < b.peso;
}
bool compPrecio(Articulo a, Articulo b){
    return a.precio < b.precio;
}

void agregar(), buscar(), eliminar(), mostrar(), ordenar(), Vencen(), ConMasPeso(), ValenMas();


int main(){
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\n1) Agregar articulos a la bodega.\n";
        cout << "2) Buscar articulos.\n";
        cout << "3) Eliminar articulos.\n";
        cout << "4) Mostrar todo lo que contenga la bodega.\n";
        cout << "5-Mostrar articulos con fecha de vencimiento\n";
        cout << "6-Mostrar articulos con +300g de peso\n";
        cout << "7-Mostrar articulos con +$50 de precio\n";
        cout << "8) Ordenar\n";
        cout << "9) Salir\n";
        cout << "Opcion: ";
        cin >> opcion; cin.ignore();
        
        switch(opcion){
            case 1: agregar(); break;
            case 2: buscar(); break;
            case 3: eliminar(); break;
            case 4: mostrar(); break;
            case 5: Vencen(); break;
            case 6: ConMasPeso(); break;
            case 7: ValenMas(); break;
            case 8: ordenar(); break;
            case 9: continuar = false; break;
            default: cout << "Opcion no valida.\n"; break;
        }
    }while(continuar);

    return 0;
}

void agregar(){

    Articulo unArticulo;
    cout << "\nNombre: "; getline(cin, unArticulo.nombre);
    cout << "Peso: "; cin >> unArticulo.peso; cin.ignore();
    cout << "Precio: "; cin >> unArticulo.precio; cin.ignore();
    cout << "Posee fecha de vencimiento?\n";
    cout << "1-Si\n2-No\n";
    cout << "Opcion: "; cin >> unArticulo.fechaV; cin.ignore();
    bodega.insert(bodega.end(), unArticulo);
    cout << "\nArticulo ingresado exitosamente!\n";

}
void buscar(){
    string unNombre;
    cout << "\nNombre del articulo a buscar: ";
    getline(cin, unNombre);
    
    bool encontrado = false;
    for (int i = 0; i < bodega.size(); i++) {
        if(bodega[i].nombre == unNombre){
            encontrado = true;
            break;
        }
    }
    
    if(encontrado)
        cout << "\nArticulo si se encuentra en la bodega.\n";
    else
        cout << "\nArticulo no se encuentra en la bodega.\n";
}
void eliminar(){
    string unNombre;
    cout << "\nNombre del articulo a eliminar: ";
    getline(cin, unNombre);
    
    for(auto iter = bodega.begin(); iter != bodega.end(); ++iter){
        if(iter->nombre == unNombre){
            iter = bodega.erase(iter);
            cout << "\nArticulo eliminado exitosamente.\n";
            break;
        }
    }
}
void mostrar(){
    cout << "\nBODEGA: " << endl;

    for (int i = 0; i < bodega.size(); i++) {
        cout << "\n";
        cout << "* " << bodega[i].nombre << " pesa " << bodega[i].peso;
        cout << " gramos, vale $" << bodega[i].precio;
        if(bodega[i].fechaV == 1){
            cout << " y es un articulo perecedero ";
        }
        else{
            cout << " y no es un articulo perecedero ";
        }
        
    }
    cout << "\n";
}
void ordenar(){
    int opcion = 0;
    cout << "\nCriterio de ordenamiento:\n";
    cout << "1) Alfabetico\n";
    cout << "2) Peso\n3)Precio\n";
    cout << "Opcion: ";
    cin >> opcion; cin.ignore();
    
    if(opcion == 1)
        sort(bodega.begin(), bodega.end(), compNombre);
    else if(opcion == 2)
        sort(bodega.begin(), bodega.end(), compPeso);
    else if(opcion == 3)
        sort(bodega.begin(), bodega.end(), compPrecio);
        
    cout << "Bodega ordenada exitosamente\n";
}

void Vencen(){
    int k = 0;

    cout << "\nARTICULOS DE LA BODEGA PERECEDEROS" << endl;
    for (int i = 0; i < bodega.size(); i++) {
        
        if(bodega[i].fechaV == 1){
            cout << "\n";
            cout << "* " << bodega[i].nombre << " pesa " << bodega[i].peso;
            cout << " gramos, vale $" << bodega[i].precio;
            cout << " y es perecedero ";
        }
        else{
            k++;
        }
    }
    if(k == bodega.size()){
        cout << "\nNO HAY ARTICULOS PERECEDEROS EN LA BODEGA!" << endl;
    }
    cout << "\n";
}

void ConMasPeso(){
    int k = 0;

	cout << "\nARTICULOS EN LA BODEGA QUE PESAN MAS DE 300g" << endl;
    for(int i = 0; i < bodega.size(); i++){
        if(bodega[i].peso > 300){
            cout << "\n";
            cout << "* " << bodega[i].nombre << " pesa " << bodega[i].peso;
            cout << " gramos, vale $" << bodega[i].precio;
            if(bodega[i].fechaV == 1){
                cout << " y es un articulo perecedero ";
            }
            else{
                cout << " y no es un articulo perecedero ";
            }
        }
        else{
            k++;
        }
    }
    if(k == bodega.size()){
        cout << "\nNO HAY ARTICULOS DE MAS DE 300g DE PESO EN LA BODEGA!" << endl;
    }
    cout << "\n";
}

void ValenMas(){
    int k = 0;

	cout << "\nARTICULOS DE LA BODEGA QUE VALEN MAS DE $50" << endl;
    
    for(int i = 0; i < bodega.size(); i++){
        if(bodega[i].precio > 50){
            cout << "\n";
            cout << "* " << bodega[i].nombre << " pesa " << bodega[i].peso;
            cout << " gramos, vale $" << bodega[i].precio;
            if(bodega[i].fechaV == 1){
                cout << " y es un articulo perecedero ";
            }
            else{
                cout << " y no es un articulo perecedero ";
            }
        }
        else{
            k++;
        }
    }
    if(k == bodega.size()){
        cout << "\nNO HAY ARTICULOS DE MAS DE $50 EN LA BODEGA!" << endl;
    }
     cout << "\n";
}