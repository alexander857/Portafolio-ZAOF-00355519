#include<iostream>
#include<string>
#include<queue>

using namespace std;

struct actividades{
	string titulo;
	string hora;
	string descripcion;
	string tipo;
	int DuracionMin;
};

typedef struct actividades ACTI;

struct agenda{
	queue <actividades> ACTIVIDADES;
	queue <actividades> ACTIVIDADES2;
	int actividadesDia;
	int actividadesRealizadas;	
};

 
agenda AGENDA;

//funciones
void InsertarAct(), BorrarAct(), BorrarTodasAct(), VerActividades(), LimiteEntreFunciones();

int main(){
	
	AGENDA.actividadesDia = 0;
	AGENDA.actividadesRealizadas = 0;
	
	int opcion = 0;
	bool continuar = true;
	
	do{
		cout << "\n1-Agregar una actividad\n";
		cout << "2-Borrar una actividad\n";
		cout << "3-Borrar todas las actividades\n";
		cout << "4-Ver actividades\n";
		cout << "5-Salir\n";
		cout << "Opcion: "; cin >> opcion;
		cin.ignore();
		
		switch(opcion){
			case 1: InsertarAct(); break;
			case 2: BorrarAct(); break;
			case 3: BorrarTodasAct(); break;
			case 4: VerActividades(); break;
			case 5: continuar = false;
			default: cout << "Opcion invalida!\n"; break;
		}
		
	}while(continuar);
		
	return 0;
}

//funcion para ingresar una actividad
void InsertarAct(){
	LimiteEntreFunciones(); //dibuja el limite entre menus
	
	//ingresar datos de la actividad
	ACTI unaActividad;
	cout << "\nTitulo de la actividad: "; getline(cin, unaActividad.titulo);
	cout << "Hora de la actividad: "; getline(cin, unaActividad.hora);
	cout << "Descricion de la actividad: "; getline(cin, unaActividad.descripcion);
	cout << "Tipo de la actividad: "; getline(cin, unaActividad.tipo);
	cout << "Tiempo de duracion de la actividad (mim): "; cin >> unaActividad.DuracionMin; cin.ignore();
	
	//agregando a la cola
	AGENDA.ACTIVIDADES.push(unaActividad);
	AGENDA.actividadesDia++;
	
	LimiteEntreFunciones(); //dibuja el limite entre menus
}

//funcion para eliminar una actividad
void BorrarAct(){
	LimiteEntreFunciones(); //dibuja el limite entre menus
	
	//eliminando una actividad
	ACTI actividadABorrar = AGENDA.ACTIVIDADES.front();
	cout << "\nActividad a eliminar: " << actividadABorrar.titulo;
	cout << "\nTrataba sobre: " << actividadABorrar.descripcion;
	cout << "\nDuracion (min): " << actividadABorrar.DuracionMin << endl;
	
	int opcion = 0;
	cout << "\nSEGURO QUE DESEA ELIMINAR LA ACTIVIDAD?\n";
	cout << "\n1-Si, ya la he realizado\n";
	cout << "2-No, aun no la he realizado\n";
	cout << "\nOpcion: "; cin >> opcion;
	
	if(opcion == 1){
		//eliminando la actividad
		AGENDA.ACTIVIDADES.pop();
		cout << "\nLA ACTIVIDAD [" << actividadABorrar.titulo << "] HA SIDO ELIMINADA!\n";
		AGENDA.actividadesRealizadas++;
	}

	LimiteEntreFunciones(); //dibuja el limite entre menus
}

//funcion para eliminar todas las actividades
void BorrarTodasAct(){
	char opcion = 0;
	LimiteEntreFunciones(); //dibuja el limite entre menus
	
	cout << "\nESTA SEGURO QUE QUIERE ELIMINAR TODAS LAS ACTIVIDADES?\n";
	cout << "\nS-Si, estoy seguro!\n";
	cout << "Si no esta seguro presione cualquier tecla!\n";
	cout << "\nOpcion: "; cin >> opcion;
	
	if(opcion == 's' || opcion == 'S'){
		
		cout << "\nActividades totales eliminadas: " << AGENDA.ACTIVIDADES.size() << endl;
	
		while(!AGENDA.ACTIVIDADES.empty()){		
			//eliminando todas las actividades
			AGENDA.ACTIVIDADES.pop();
			AGENDA.actividadesRealizadas++;
		}
		cout << "\nSE HAN ELIMINADOS TODAS LAS ACTIVIDADES!" << endl;
	}
	
	LimiteEntreFunciones(); //dibuja el limite entre menus
}

//funcion para ver todas las actividades
void VerActividades(){
	int i = 1;
	LimiteEntreFunciones(); //dibuja el limite entre menus
		
	//se muestran las actividades registradas
	cout << "\nActividades actuales en la agenda: " << AGENDA.ACTIVIDADES.size() << endl;
	cout << "Actividades realizadas: " << AGENDA.actividadesRealizadas << endl;
	cout << "Actividades totales: " << AGENDA.actividadesDia << endl;
	
	//pasando datos de una cola a otra para mostrarlos en pantalla
	while(!AGENDA.ACTIVIDADES.empty()){
			
		ACTI unaActividad = AGENDA.ACTIVIDADES.front();
			
		AGENDA.ACTIVIDADES2.push(AGENDA.ACTIVIDADES.front());
			
		cout << "\nACTIVIDAD " << i << ": " << endl;
		cout << "Titulo de la actividad: " << unaActividad.titulo << endl;
		cout << "Hora de la actividad: " << unaActividad.hora << endl;
		cout << "Descripcion de la actividad: " << unaActividad.descripcion << endl;
		cout << "Tipo de la actividad: " << unaActividad.tipo << endl;
		cout << "Tiempo de duracion de la actividad (min): " << unaActividad.DuracionMin << endl;
			
		i++;
			
			//sacando de agenda original
		AGENDA.ACTIVIDADES.pop();
	}
		
		//regresando los datos a la cola original
	while(!AGENDA.ACTIVIDADES2.empty()){
			
		AGENDA.ACTIVIDADES.push(AGENDA.ACTIVIDADES2.front());
			
		AGENDA.ACTIVIDADES2.pop();
			
	}
	
	LimiteEntreFunciones(); //dibuja el limite entre menus
}

//dibujar un limite entre menus para que se vea un poco mas ordenado en consola
void LimiteEntreFunciones(){
	
	cout << "\n";
	for(int i = 0; i <50; i++){
		cout << "*";
	}
	cout << "\n";
}
