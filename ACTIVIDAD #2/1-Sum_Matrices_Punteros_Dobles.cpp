#include<iostream>
#include<iomanip>

using namespace std;

//prototipo de la funcion
void SumMatrix(int *p1, int *p2, int *p3, int tam);

int main(){

    //declaracion de variables
    int tam = 2;
    int matriz1[2][tam], matriz2[2][tam], matriz3[2][tam];

    //pedimos al usuario que digite los elementos de la matriz 1
    cout<<"Ingrese elementos de matriz 1:"<<endl;
    for(int i=0;i<2;i++){
        for(int j=0;j<tam;j++){
            cin>>matriz1[i][j];
        }
    }
    cout<<endl;

    //pedimos al usuario que digite los elementos de la matriz 2
    cout<<"Ingrese elementos de matriz 2:"<<endl;
    for(int i=0;i<2;i++){
        for(int j=0;j<tam;j++){
            cin>>matriz2[i][j];
        }
    }
    cout<<"\n"<<endl;

    //llamando a la funcion que suma las matrices
    SumMatrix(*matriz1,*matriz2,*matriz3,tam);

    //mostrando la matriz 1
    cout<<"Matriz 1:"<<endl;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cout<<setw(3)<<matriz1[i][j];
        }
        cout<<endl;
    }
    cout<<"\n"<<endl;

    //mostrando la matriz 2
    cout<<"Matriz 2:"<<endl;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cout<<setw(3)<<matriz2[i][j];
        }
        cout<<endl;
    }
    cout<<"\n"<<endl;

    //mostrando la matriz 3 que contiene la suma de los elementos de matriz 1 con matriz 2
    cout<<"Suma de los elementos de matriz 1 y 2:"<<endl;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cout<<setw(3)<<matriz3[i][j];
        }
        cout<<endl;
    }
    cout<<"\n"<<endl;


    return 0;
}

//funcion que suma los elementos de las matrices
void SumMatrix(int *p1, int *p2, int *p3, int tam){

    for(int i=0;i<tam;i++){
        for(int j=0;j<tam;j++){
            *(p3+i*tam+j) = *(p1+i*tam+j) + *(p2+i*tam+j); //sumando los elementos de la matriz 1 y 2 y guardando el resultado en la matriz 3
        }
    }

}