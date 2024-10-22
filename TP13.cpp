/*
1 - Este programa contiene cuatro clases, una padre y otras tres heredadas. La primera clase representa las personas en general, la segunda se hereda 
de persona y representa los empleados, la tercera se hereda de persona y representa los estudiantes, y la cuarta se hereda de estudiantes y representa
los técnicos. Hay unos valores predefinidos para objetos de cada clase, y al compilar el programa, carga unos métodos que muestran la información
de cada objeto de cada clase. 
3 - La clase padre se llama Persona
4 - La clase Empleado y Estudiante heredan de Persona 
5 - Técnico, es una clase heredada de Estudiante
6 - El constructor de empleado hace dos cosas: guarda el valor que se introduce por la cabecera en su propio atributo (sueldo), y llama al constructor 
de la clase padre para guardar los otros valores.
7 - El método mostrarPersona(), muestra en pantalla los atributos del objeto de la clase Persona().
8 - El método para mostrar el salario del empleado es mostrarEmpleado().*/
#include<iostream>
#include<stdlib.h>
using namespace std;
class Persona{
    private: //Modifica el acceso de los atributos a privado
        string nombre;
        int edad;
    public: //Modifica el acceso de los métodos a público
        Persona(string,int); //Declara el constructor de la clase con sus atributos
        void mostrarPersona();
};
class Empleado : public Persona{
    private: //Modifica el acceso de los atributos a privado
        float sueldo;
    public: //Modifica el acceso de los métodos a público
        Empleado(string,int,float); //Declara el constructor de la clase con sus atributos y los atributos de la clase padre
        void mostrarEmpleado();
};
class Estudiante : public Persona{
    private: //Modifica el acceso de los atributos a privado
        float notaFinal;
    public: //Modifica el acceso de los métodos a público
        Estudiante(string,int,float);
        void mostrarEstudiante();
};
class Tecnico : public Estudiante{
    private: //Modifica el acceso de los atributos a privado
        string especialidad;
    public:
        Tecnico(string,int,float,string); //Declara el constructor de la clase y los atributos de la clase padre
        void mostrarTecnico();
};
//Define el constructor de la clase. Este guarda los valores introducidos por a través de la cabecera en los atributos de la clase.
Persona::Persona(string _nombre,int _edad){
    nombre = _nombre;
    edad = _edad;
}
void Persona::mostrarPersona(){
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Edad: "<<edad<<endl;
}
//Define el constructor de la clase, que solo guarda el valor que es único de la clase. Para el resto de atributos heredados, llama al constructor de la clase padre.
Empleado::Empleado(string _nombre,int _edad,float _sueldo) : Persona(_nombre,_edad){
    sueldo = _sueldo;
}
void Empleado::mostrarEmpleado(){
    mostrarPersona();
    cout<<"Sueldo: "<<sueldo<<endl;
}
//Define el constructor de la clase, que solo guarda el valor que es único de la clase. Para el resto de atributos heredados, llama al constructor de la clase padre.
Estudiante::Estudiante(string _nombre,int _edad,float _notaFinal) : Persona(_nombre,_edad){
    notaFinal = _notaFinal;
}
void Estudiante::mostrarEstudiante(){
    mostrarPersona();
    cout<<"Nota Final: "<<notaFinal<<endl;
}
//Define el constructor de la clase, que solo guarda el valor que es único de la clase. Para el resto de atributos heredados, llama al constructor de la clase padre.
Tecnico::Tecnico(string _nombre,int _edad,float _notaFinal,string _especialidad) : Estudiante(_nombre,_edad,_notaFinal){
    especialidad = _especialidad;
}
void Tecnico::mostrarTecnico(){
    mostrarEstudiante();
    cout<<"Especialidad: "<<especialidad<<endl;
}
int main(){
    Empleado empleado1("Juan",35,1300000);
    cout<<"-Empleado-"<<endl;
    empleado1.mostrarEmpleado();
    cout<<"\n";
       Estudiante estudiante1("Maria",21,16.7);
    cout<<"-Estudiante-"<<endl;
    estudiante1.mostrarEstudiante();
    cout<<"\n";
   
    Tecnico tecnico1("Alejandro",20,15.6,"Informatica");
    cout<<"-Tecnico-"<<endl;
    tecnico1.mostrarTecnico();
    cout<<"\n";
   
    return 0;
}