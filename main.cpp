//Ejercicio 01
/*Usar estructuras y grabar datos a un archivo, utilizar funciones
Descripción del problema. Escribir una función Salario 
que calcule los salarios de un trabajador para un número dado
de horas trabajadas y un salario hora. Las horas que superen las 40 horas
semanales se pagarán como extras con un salario hora 1.5 veces el salario
ordinario. Así mismo se deberá calcular el monto a pagar de IGSS por
cada trabajador.

El programa deberá contener un menú para:
1. Invocar dicha función y grabar datos a un archivo.
2. Adicionalmente deberá tener una opción para leer el archivo y grabar
los datos en memoria.
3. Una opción para mostrar cuanto se paga de total de planilla e IGGS.
*/

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

struct trabajador{
	string nombre;
	float salarioHora;
	float horasTrabajadas;
	float horasExtra;
	float salarioBase;
	float salarioHoraExtra;
	float igss;
	float salarioTotal;
};

void mp();
void agregarTrabajador();
void leerArchivo();

int main(){
	mp();
}

void mp(){
	MenuPrincipal:
		int i;
		system("CLS");
		cout<<"Menu principal"<<endl;
		cout<<"1. Agregar trabajador"<<endl;
		cout<<"2. Leer archivo"<<endl;
		cout<<"3. Reporte"<<endl;
		cout<<"4. Salir"<<endl;
		cout<<"----------------------"<<endl;
		cout<<"Seleccione una opcion: ";
		cin>>i;
		
		switch(i){
			case 1:
				{agregarTrabajador();}
				system("Pause");
				system("CLS");
				goto MenuPrincipal;
				break;
			case 2:
				{leerArchivo();}
				system("Pause");
				system("CLS");
				goto MenuPrincipal;
			case 3:
				cout<<"Reporte"<<endl;
				system("Pause");
				goto MenuPrincipal;
			case 4:
				system("CLS");
				cout<<"Gracias por usar el sistema. Presione Enter para salir.";
				exit(1);
				break;
			default:
				system("CLS");
				cout<<"Opcion seleccionada no existe."<<endl;
				cout<<"Intentelo nuevamente."<<endl;
				system("Pause");
				goto MenuPrincipal;
				break;
		}
};

void agregarTrabajador(){
	int maximoHorasLaborales = 40;
	float igss = 0.1067;
	float valorHoraExtra = 1.5;
	
	ofstream archivo;
	string nombreArchivo;
	fflush(stdin);
	system("CLS");
	
	cout<<"Indique nombre del archivo: ";
	getline(cin, nombreArchivo);
	
	archivo.open(nombreArchivo.c_str(),ios::app);
	if(archivo.fail()){
		archivo.close();
		cout<<"Se presento un problema con el archivo. Intentelo de nuevo.";
		exit(1);
	}
	
	system("CLS");
	archivo.close();
	
	string nombre;
	float salarioHora = 0;
	float horasTrabajadas = 0;
	float horasExtra = 0;
	float salarioExtra = 0;
	float salarioBase = 0;
	float salarioTotal = 0;
	float calculoIgss = 0;
	char opcion;
	
	fflush(stdin);
	cout<<"Ingrese nombre del empleado: "<<endl;
	getline(cin, nombre, '\n');
	
	cout<<"Ingrese salario por hora: ";
	cin>>salarioHora;
	
	cout<<"Ingrese horas trabajadas: ";
	cin>>horasTrabajadas;
	
	if(horasTrabajadas > maximoHorasLaborales){
		horasExtra = horasTrabajadas - maximoHorasLaborales;
		salarioBase = (salarioHora * maximoHorasLaborales);
	}else{
		salarioBase = (salarioHora * horasTrabajadas);
	}
		
	calculoIgss = (igss * salarioBase);
	
	if(horasExtra > 0){
		salarioExtra = (horasExtra * valorHoraExtra * salarioHora);
	}
	
	salarioTotal = (salarioBase - calculoIgss) + salarioExtra;
	
	system("CLS");
	
	cout<<"<- Datos del empleado ->"<<endl;
	cout<<"Nombre: "<<nombre<<endl;
	cout<<"Salario por hora normal: "<<salarioHora<<endl;
	cout<<"Total horas trabajadas: "<<horasTrabajadas<<endl;
	cout<<"Total horas extra: "<<horasExtra<<endl;
	cout<<"Sueldo base: "<<salarioBase<<endl;
	cout<<"Sueldo por horas extra: "<<salarioExtra<<endl;
	cout<<"Total igss: "<<calculoIgss<<endl;
	cout<<"Sueldo total: "<<salarioTotal<<endl;
	cout<<"--------------------------------------"<<endl;
	
	cout<<"¿Desea guardar este registro (y/n)?";
	cin>>opcion;
	
	if(toupper(opcion) == 'Y'){
		archivo.open(nombreArchivo.c_str(),ios::app);
		if(archivo.fail()){
			archivo.close();
			cout<<"Se presento un problema con el archivo. Intentelo de nuevo.";
			exit(1);
		}
		
		system("CLS");
		
		archivo<<nombre<<"\t"
	 	<<salarioHora<<"\t"
	 	<<horasTrabajadas<<"\t"
	 	<<horasExtra<<"\t"
	 	<<salarioBase<<"\t"
	 	<<calculoIgss<<"\t"
	 	<<salarioExtra<<"\t"
	 	<<salarioTotal
	 	<<endl;
		
		archivo.close();
		
		cout<<"Registro agregado exitosamente."<<endl;
	}else{
		cout<<"Saliendo. Regresando al menu principal.";
	}
};

void leerArchivo(){
	 ifstream archivo;
	 string nombreArchivo,s, linea;
	 int lineas, i = 0;
	 
	 fflush(stdin);
	 system("CLS");
	 
	 cout<<"Ingrese nombre del archivo: ";
	 getline(cin, nombreArchivo);
	 
	 archivo.open(nombreArchivo.c_str(), ios::in);
	 if(archivo.fail()){
	 	cout<<"Se presento un error al intentar abrir el archivo.";
	 	exit(1);
	 }	
	 
	 while(getline(archivo, s))
		lineas++;
		
     archivo.close();
     system("CLS");
     
     trabajador lista[lineas];
     
     archivo.open(nombreArchivo.c_str(), ios::in);
	 if(archivo.fail()){
	 	cout<<"Se presento un error al intentar abrir el archivo.";
	 	exit(1);
	 }
	 
	 for(int i = 0; i < lineas; i++){
	 	if(!archivo){
	 		cerr<<"No se pudo abrir el archivo."<<endl;
	 		system("Pause");
		 }
		 
		 archivo>>lista[i].nombre
		 >>lista[i].salarioHora
		 >>lista[i].horasTrabajadas
		 >>lista[i].horasExtra
		 >>lista[i].salarioBase
		 >>lista[i].igss
		 >>lista[i].salarioHoraExtra
		 >>lista[i].salarioTotal;
	 }
	 archivo.close();
	 
	 for(int i = 0; i < lineas; i++){
	 	cout<<"Registro: "<<i<<endl;
	 	cout<<"Nombre"<<setw(15)
			<<"Salario x Hora"<<setw(10)
			<<"Horas trabajadas"<<setw(10)
			<<"Horas extra"<<setw(10)
			<<"Salario base"<<setw(10)
			<<"Igss"<<setw(10)
			<<"Salario x Hora Extra"<<setw(10)
			<<"Salario total"<<setw(10)<<endl;
		
		cout<<lista[i].nombre<<setw(15)
			<<lista[i].salarioHora<<setw(10)
			<<lista[i].horasTrabajadas<<setw(10)
			<<lista[i].horasExtra<<setw(10)
			<<lista[i].salarioBase<<setw(10)
			<<lista[i].igss<<setw(10)
			<<lista[i].salarioHoraExtra<<setw(10)
			<<lista[i].salarioTotal<<setw(10)<<endl;
	 }
	 system("Pause");
};
