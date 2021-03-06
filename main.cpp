//Ejercicio 01
/*Usar estructuras y grabar datos a un archivo, utilizar funciones
Descripci�n del problema. Escribir una funci�n Salario 
que calcule los salarios de un trabajador para un n�mero dado
de horas trabajadas y un salario hora. Las horas que superen las 40 horas
semanales se pagar�n como extras con un salario hora 1.5 veces el salario
ordinario. As� mismo se deber� calcular el monto a pagar de IGSS por
cada trabajador.

El programa deber� contener un men� para:
1. Invocar dicha funci�n y grabar datos a un archivo.
2. Adicionalmente deber� tener una opci�n para leer el archivo y grabar
los datos en memoria.
3. Una opci�n para mostrar cuanto se paga de total de planilla e IGGS.
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
void salario();
void leerArchivo();
void reporte();

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
				{salario();}
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
				{reporte();}
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

void salario(){
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
	
	cout<<"�Desea guardar este registro (y/n)?";
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
	 	if(i == 0){
		 	cout<<"Id "<<"\t"
			    <<"Nombre"<<"\t"
				<<"Sal_x_Hr"<<"\t"
				<<"Hr_trab"<<"\t"
				<<"Hr_xtr"<<"\t"
				<<"Sal_base"<<"\t"
				<<"Igss"<<"\t"
				<<"Sal_x_Hr_xtr"<<"\t"
				<<"Sal_tot"<<endl;
		}
		
		cout<<i<<"\t"
			<<lista[i].nombre<<"\t"
			<<lista[i].salarioHora<<"\t"
			<<lista[i].horasTrabajadas<<"\t"
			<<lista[i].horasExtra<<"\t"
			<<lista[i].salarioBase<<"\t"
			<<lista[i].igss<<"\t"
			<<lista[i].salarioHoraExtra<<"\t"
			<<lista[i].salarioTotal<<endl;
	 }
};

void reporte(){
	 ifstream archivo;
	 string nombreArchivo,s, linea;
	 int lineas, i = 0;
	 float salario, igss;
	 
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
	 
	 igss = 0;
	 salario = 0;
	 
	 for(int i = 0; i < lineas; i++){	
		igss = igss + lista[i].igss;
		salario = salario + lista[i].salarioTotal;
	 }
	 system("CLS");
	 cout<<"Reporte de planilla"<<endl;
	 cout<<"Salario total a pagar: "<<salario<<endl;
	 cout<<"Igss total a pagar: "<<igss<<endl;
	 cout<<"----------------------"<<endl;
};
