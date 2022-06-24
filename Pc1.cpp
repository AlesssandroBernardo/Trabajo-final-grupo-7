
#include "pch.h"
#include "Asignacion.hpp"
#include<iostream>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace System;
using namespace std;

int logo[12][29]{
     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
     {1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
     {0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
     {0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
     {0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
     {0,0,0,1,0,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,0,1,1,1,1,1},
     {0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0},
     {0,0,0,1,0,1,0,1,0,1,1,0,0,1,0,0,0,0,0,1,1,1,0,1,0,0,0,0,0},
     {0,0,0,1,0,1,1,1,0,1,0,1,0,1,1,1,1,0,0,1,0,1,0,0,1,1,1,0,0},
     {0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0},
     {0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0},
     {0,0,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,1,1,1,0,0},
};

void imprimirTablaHash(Hashtable* ht, int* keys) {
    cout << "SIZE TABLA: " << ht->size() << "\n";
    cout << "SIZE ACTUAL: " << ht->sizeActual() << "\n";

    for (int i = 0; i < ht->sizeActual(); i++) {
        cout << ht->buscar(keys[i]) << " : " << keys[i] << "\n";
    }
   
}

int sumChar(string name) {
    int n = 0;
    int i = 0;
    int sum = 0;

    while (i < name.size()) {
        n = name[i];
        sum = sum + n;
        i++;
    }

    return sum;
}

int buscarEnArbol() {
    int dato;
    cout << "Ingrese un dato para buscar en el arbol" << endl;
    cin >> dato;
    return dato;
}
void imprimir(int e) {
    cout << " " << e;
}
void GenerarArbol(ListaPersonas* listaP) {
    system("cls");
    ArbolBB<int>* arbol = new ArbolBB<int>(imprimir);
    for (int i = 0; i < listaP->getCantidad(); i++)
    {   
        arbol->insertar(listaP->getpersona(i)->getEdad());
    }
    int opcion;
    while (true) {
        system("cls");
        cout << "Arbol generado correctamente" << endl;

        cout << "[Ingrese una opcion]" << endl;
        cout << "[1] Ordenar arbol en preorden" << endl;
        cout << "[2] Ordenar arbol en postOrden" << endl;
        cout << "[3] Ordenar arbol en EnOrden" << endl;
        cout << "[4] Buscar Elemento" << endl;
        cout << "[5] Encontrar minimo" << endl;
        cout << "[6] Encontrar maximo" << endl;
        cout << "[0] Salir" << endl;
        cin >> opcion;
        switch (opcion)
        {
        case 1: arbol->preOrden();_getch(); break;
        case 2: arbol->postOrden(); _getch(); break;
        case 3: arbol->enOrden(); _getch(); break;
        case 4: 
            cout<<arbol->Buscar(buscarEnArbol()); _getch(); break;
        case 5: cout<<arbol->Maximo(); _getch(); break;
        case 6: cout<<arbol->Minimo(); _getch(); break;
        

        case 0: ; return;


        default:
            break;
        }
    }
        
}
void GuardarHashTable(ListaPersonas* p) {
    int size = p->getCantidad();
    Hashtable* ht = new Hashtable(size);
    int* keys = new int[size];
    int n;

    for (int i = 0; i < size; i++) {
        n = sumChar(p->getpersona(i)->getNombre());
        keys[i] = n;
        ht->insertar(n, p->getpersona(i)->getNombre());
    }
    imprimirTablaHash(ht, keys);
}

void mergeSortID(ListaPersonas* listaP) {
    vector<int*> listaIDs;
    int cant=0;
    for (int i = 0; i < listaP->getCantidad(); i++)
    {   
        listaIDs.push_back(new int(listaP->getpersona(i)->getid()));
        cant++;
    }
    mergeSort(listaIDs, cant);
    cout << "Lista de ID de los usuarios ordenados por mergeSort" << endl;
    for (int i = 0; i < listaP->getCantidad(); i++)
    {   
        cout << *listaIDs.at(i) << endl;
    }

}


void quickSortEdades(ListaPersonas* listaP) {
    vector<int*> edades;
    int cant = 0;
    for (int i = 0; i < listaP->getCantidad(); i++)
    {
        edades.push_back(new int(listaP->getpersona(i)->getEdad()));
        cant++;
    }
    quickSort(edades, 0,edades.size()-1);
    cout << "Lista de edades de los usuarios ordenados por quicksort" << endl;
    for (int i = 0; i < listaP->getCantidad(); i++)
    {
        cout << *edades.at(i) << endl;
    }

}
void guardarDatos(ListaPersonas* listaP) {


    ofstream archEsc("NombreUsuarios.txt");
    for (int i = 0; i < listaP->getCantidad(); i++)
    {
        archEsc << listaP->getpersona(i)->getNombre() << endl;
        archEsc << listaP->getpersona(i)->getApellido() << endl;
        archEsc << listaP->getpersona(i)->getEdad() << endl;
        archEsc << listaP->getpersona(i)->getGenero() << endl;
        archEsc << listaP->getpersona(i)->getid() << endl;
        archEsc << endl;
    }
    ifstream archLect("NombreUsuarios.txt");

    archLect.close();
}
void pintarLogo() {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 29; j++) {

            if (logo[i][j] == 0) Console::BackgroundColor = ConsoleColor::Black;
            if (logo[i][j] == 1) Console::BackgroundColor = ConsoleColor::White;
            cout << " ";
            Console::BackgroundColor = ConsoleColor::Black;
        }
        cout << endl;
    }
    cout << endl;

}

void agregarPersona(ListaPersonas* ListaP) {
    int id;
    string Nombre;
    string Apellido;
    string genero;
    int edad;
    char c;
   
    while (true) {
        cout << "Ingrese su ID:" << endl;
        cin >> id;

        if (cin.fail()==true) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Ingrese un dato valido" << endl;
        }
        else {
            break;
        }
       
    }
    
    cin.ignore();
    cout << "Ingrese su nombre: ";
    getline(cin, Nombre); cout << endl;
    cout << "Ingrese su apellido: ";
    getline(cin, Apellido); cout << endl;
    cout << "Ingrese su genero (Masculino-Femenino-Otro): ";
    getline(cin, genero); cout << endl;
    cout << "Ingrese su edad: ";
    cin >> edad;
    ListaP->InsertarPersona(id, Nombre, Apellido, genero, edad);
    guardarDatos(ListaP);
}

void comparacion_Lexicografica(ListaPersonas* ListaP) { //algoritmo de comparacion lexicografica
    string nombre_1;
    string nombre_2;
    char char1[20];
    char char2[20];
    int char1Size;
    int char2Size;
    bool k1,k2, keyWhile;
    k1 = k2 = false;
    keyWhile = true;
    while (keyWhile == true)
    {   
        cout << "Ingrese el primer nombre a comparar:" << endl;
        cin.ignore();
        getline(cin, nombre_1); cout << endl;
        cout << "Ingrese el segundo nombre a comparar:" << endl;
        getline(cin, nombre_2); cout << endl;
        
        for (int i = 0; i < ListaP->getCantidad(); i++)
        {   
            if (nombre_1 == ListaP->getpersona(i)->getNombre());
            char1[i] = nombre_1.at(i);
            k1 = true;
        }
        for (int i = 0; i < ListaP->getCantidad(); i++)
        {
            if (nombre_2 == ListaP->getpersona(i)->getNombre());
            char2[i] = nombre_2.at(i);
            k2 = true;
        }
        if (k1 = true && k2 == true) {
            keyWhile=false;
            cout << "Comparando la lexicografia de los nombres" << endl;
            cout << lexicographical_compare(char1, char1 + 20, char2, char2 + 20);
        }
        else {
            cout << "Uno o dos nombres no estan registrados, intentalo nuevamente" << endl;
        }
    }    
}



void agregarTarea(ListaPersonas* ListaP, ListaTareas* ListaT) {
    string nombreTarea;
    string tipoUrgencia;
    string estado;
    string fechaCreacion;
    string auxPersona;
    int aux = 0;
    cout << "Ingrese el nombre de la tarea: ";
    cin.ignore();
    getline(cin, nombreTarea); cout << endl;
    cout << "Ingrese el tipo de urgencia(urgente-aplazable): ";
    getline(cin, tipoUrgencia); cout << endl;
    cout << "Ingrese su estado(completo, incompleto): ";
    getline(cin, estado); cout << endl;
    cout << "Ingrese la fecha de creacion: ";
    getline(cin, fechaCreacion); cout << endl;
    cout << "Ingrese su nombre: ";
    getline(cin, auxPersona); std::cout << endl;
    for (int i = 0; i < ListaP->getCantidad(); i++)
    {
        if (ListaP->getpersona(i)->getNombre() == auxPersona) {
            ListaT->InsertarTarea(nombreTarea, tipoUrgencia, estado, fechaCreacion, ListaP->getpersona(i));
            aux = 1;
        }
    }
    if (aux == 0) {
        cout << "Usted no ha sido registrado" << endl;
    }

}

auto ordenarNombrePersonas = [&](ListaPersonas* listaP) {
    int i, j, min;
    string aux, nombres[10];
    cout << "ORDENADO ALFABETICAMENTE:" << endl;
    for (i = 0; i < listaP->getCantidad(); i++)    //Primer bucle recorre todo el arreglo
    {
        nombres[i] = listaP->getpersona(i)->getNombre();
    }
    for (i = 0; i < listaP->getCantidad(); i++)
    {
        min = i;
        for (j = i + 1; j < listaP->getCantidad(); j++) {
            if (nombres[j] < nombres[min]) {
                min = j;
            }
        }
        aux = nombres[i];
        nombres[i] = nombres[min];
        nombres[min] = aux;
    }
    for (i = 0; i < listaP->getCantidad(); i++)
    {
        cout << nombres[i] << endl;
    }
    ofstream archEsc("NombreUsuariosOrdenados.txt");
    for (int i = 0; i < 10; i++)
    {
        archEsc << nombres[i] << endl;
        archEsc << endl;
    }
    ifstream archLect("NombreUsuariosOrdenados.txt");

    archLect.close();
};


void mostrarPersonas(ListaPersonas* listaP) {
    for (int i = 0; i < listaP->getCantidad(); i++)
    {
        cout << listaP->getpersona(i)->getNombre() << endl;
    }
}

void mostrarTareas(ListaPersonas* listaP, ListaTareas* ListaT) {
    for (int i = 0; i < listaP->getCantidad(); i++)
    {
        cout << listaP->getpersona(i)->getNombre() << ":" << endl;

        for (int j = 0; j < ListaT->getCantidad(); j++)
        {
            if (listaP->getpersona(i)->getNombre() == ListaT->getTarea(j)->getPersona()->getNombre()) {
                cout << j + 1 << ".-" << ListaT->getTarea(j)->getNombrTarea() << "\t" << "Estado: " << ListaT->getTarea(j)->getEstado() << endl;
            }
        }
    }

}
void mostrarTareasTerminadas(ListaTareas* ListaT) {
    for (int i = 0; i < ListaT->getCantidad(); i++)
    {
        cout << "Usuario: " << ListaT->getTarea(i)->getPersona()->getNombre() << endl;
        if (ListaT->getTarea(i)->getEstado() == "completo") {
            for (int i = 0; i < ListaT->getCantidad(); i++) {
                cout << "Tareas terminadas de: " << ListaT->getTarea(i)->getPersona()->getNombre() << endl;
                cout << i + 1 << ListaT->getTarea(i)->getNombrTarea() << endl;
            }
        }
    }
}

void cambiarEstadoTarea(ListaTareas* ListaT) {
    string auxUsuario;
    string auxTarea;
    cout << "Ingrese un nombre de usuario registrado: " << endl;
    cin.ignore();
    getline(cin, auxUsuario); cout << endl;
    for (int i = 0; i < ListaT->getCantidad(); i++)
    {
        if (ListaT->getTarea(i)->getPersona()->getNombre() == auxUsuario) {
            cout << "Ingrese la tarea para cambiar su estado: " << endl;
            for (int i = 0; i < ListaT->getCantidad(); i++)
            {
                if (ListaT->getTarea(i)->getPersona()->getNombre() == auxUsuario) {
                    cout << i + 1 << ".-" << ListaT->getTarea(i)->getNombrTarea() << endl;
                }
            }
            getline(cin, auxTarea); cout << endl;
            if (ListaT->getTarea(i)->getNombrTarea() == auxTarea) {
                ListaT->getTarea(i)->setEst("completo");
            }
        }
        else {
            cout << "El nombre puesto no es de un usuario registrado, intentelo nuevamente" << endl; break;
        }
    }
}
void mostrarTareasIncompletas(ListaTareas* listaT) {
    for (int i = 0; i < listaT->getCantidad(); i++)
    {
        if (listaT->getTarea(i)->getEstado() == "incompleto") {
            cout << "Tareas incompletas:" << endl;
            cout << listaT->getTarea(i)->getNombrTarea() << " -> " << listaT->getTarea(i)->getPersona()->getNombre() << endl;
        }
    }
}
void OrdInsercion(ListaPersonas* lp) { //Tiempo Asintotico = O(n^2)
    int edad[20];//1
    int pos, aux;

    for (int i = 0; i < lp->getCantidad(); i++) {
        edad[i] = lp->getpersona(i)->getEdad();
        pos = i;
        aux = edad[i];

        while ((pos > 0) && (edad[pos - 1] > aux)) {

            edad[pos] = edad[pos - 1];
            pos--;
        }
        edad[pos] = aux;

    }

    cout << "\nLista de personas ordenadas" << endl;
    cout << "\tEDAD \t\t NOMBRE" << endl;

    for (int i = 0; i < lp->getCantidad(); i++) {
        for (int j = 0; j < lp->getCantidad(); j++) {
            int x = lp->getpersona(j)->getEdad();
            if (edad[i] == x)
                cout << "\n " << x << "\t-\t" << lp->getpersona(j)->getNombre() << endl;
        }
    }

}
void ordenaroNombres(ListaPersonas* listaP, ListaTareas* listaT) {// tiempo asintotico = o(n^2)


    string auxN;
    string auxA;
    string auxG;
    int auxE;
    int auxID;

    for (int i = 0; i < listaP->getCantidad() - 1; i++)//1+n(1+...+2)
    {
        for (int j = 0; j < listaP->getCantidad() - 1; j++)//1+n(2+..+2)
        {
            if (tolower(listaP->getpersona(j)->getNombre()[0]) > tolower(listaP->getpersona(j + 1)->getNombre()[0])) {//1

                auxN = listaP->getpersona(j)->getNombre();//2
                auxE = listaP->getpersona(j)->getEdad();//2
                auxA = listaP->getpersona(j)->getApellido();//2
                auxID = listaP->getpersona(j)->getid();//2
                auxG = listaP->getpersona(j)->getGenero();//2

                listaP->getpersona(j)->setNombre(listaP->getpersona(j + 1)->getNombre());//3
                listaP->getpersona(j)->setedad(listaP->getpersona(j + 1)->getEdad());//3
                listaP->getpersona(j)->setApellido(listaP->getpersona(j + 1)->getApellido());//3
                listaP->getpersona(j)->setId(listaP->getpersona(j + 1)->getid());//3
                listaP->getpersona(j)->setgenero(listaP->getpersona(j + 1)->getGenero());//3

                listaP->getpersona(j + 1)->setNombre(auxN);//2
                listaP->getpersona(j + 1)->setedad(auxE);//2
                listaP->getpersona(j + 1)->setApellido(auxA);//2
                listaP->getpersona(j + 1)->setId(auxID);//2
                listaP->getpersona(j + 1)->setgenero(auxG);//2
            }
        }
    }   //1+n(3+n(29))= 29n^2+3n+1
    cout << "Datos de usuarios ordenados por el nombre" << endl;//2
    for (int i = 0; i < listaP->getCantidad(); i++)//1+n(1+...+2)
    {
        cout << listaP->getpersona(i)->getNombre() << " " << listaP->getpersona(i)->getApellido() << endl;//4
        cout << listaP->getpersona(i)->getEdad() << " " << listaP->getpersona(i)->getGenero() << " " << listaP->getpersona(i)->getid() << endl << endl;//6

    }//1+n(13)
    _getch();
}// tiempo detallado = 29n^2 + 15n + 6



void limpiarPantalla() {
    system("cls");
    system("cls");

}

void mostrarMenu() {
    pintarLogo();
    cout << "Ingrese una opcion" << endl;
    cout << "01.- Agregar un usuario" << endl;
    cout << "02.- Agregar una tarea" << endl;
    cout << "03.- Ver lista de tareas" << endl;
    cout << "04.- Mostrar tareas terminadas" << endl;
    cout << "05.- Cambiar estado de una tarea" << endl;
    cout << "06.- Mostrar tareas incompletas" << endl;
    cout << "07.- Mostrar  y Guardar por Nombres (Ordenamiento de seleccion)" << endl;
    cout << "08.- OrdenarDatos (Metodo burbuja)" << endl;
    cout << "09.- Ordenar edades (Ordenamiento de insercion)" << endl;
    cout << "10.- Ordenar IDS por MergeSort" << endl;
    cout << "11.- Ordenar edades por Quicksort" << endl;
    cout << "12.- HashTable" << endl;
    cout << "13.- Limpiar consola" << endl;
    cout << "14.- Comparacion lexicografica" << endl;
    cout << "15.- Generar Arbol por edades" << endl;


    cout << "0.- Salir" << endl;
}


void main() {

    ListaPersonas* listaP = new ListaPersonas();
    ListaTareas* listaT = new ListaTareas();
    int opcion;
    while (true)
    {

        mostrarMenu();
        cin >> opcion;
        switch (opcion)
        {
        case 1: agregarPersona(listaP); break;
        case 2: agregarTarea(listaP, listaT); break;
        case 3: mostrarTareas(listaP, listaT); break;
        case 4: mostrarTareasTerminadas(listaT); break;
        case 5: cambiarEstadoTarea(listaT); break;
        case 6: mostrarTareasIncompletas(listaT); break;
        case 7: ordenarNombrePersonas(listaP); break;
        case 8: ordenaroNombres(listaP, listaT); break;
        case 9: OrdInsercion(listaP); break;
        case 10:mergeSortID(listaP); break;
        case 11:quickSortEdades(listaP); break;
        case 12:GuardarHashTable(listaP); break;
        case 13:limpiarPantalla(); break;
        case 14:comparacion_Lexicografica(listaP); break;
        case 15:GenerarArbol(listaP); break;


        case 0:return;


        default:
            break;
        }
    }
    delete listaP;
    delete listaT;

    cin.get();
}
