#include "videojuego.h"
#include <fstream>
#include <iomanip>
#include <algorithm>

Videojuego::Videojuego()
{
    i = 0;
}

void Videojuego::agregar(const Personaje &p)
{
    arreglo.push_back(p);
}

void Videojuego::mostrar()
{
    cout << left;
    cout << setw(10) << "Nombre"
         << setw(10) << "Tipo"
         << setw(7)  << "Fuerza"
         << setw(5)  << "Salud" << endl;
    for (size_t j = 0; j < arreglo.size(); j++) {
            Personaje &p = arreglo[j];

            cout << p << endl;

//        cout << "Nombre: " << p.getNombre() << endl;
//        cout << "Tipo:   " << p.getTipo() << endl;
//        cout << "Fuerza: " << p.getFuerza() << endl;
//        cout << "Salud:  " << p.getSalud() << endl;
    }
}

void Videojuego::respaldar(const string &ubicacion)
{
    fstream archivo(ubicacion, ios::out);

    if (archivo.is_open()) {
        for (size_t j = 0; j < arreglo.size(); j++) {
                Personaje &p = arreglo[j];

                archivo << p.getNombre() << endl;
                archivo << p.getTipo() << endl;
                archivo << p.getFuerza() << endl;
                archivo << p.getSalud() << endl;
        }
    }
}

void Videojuego::recuperar(const string &ubicacion)
{
    fstream archivo(ubicacion, ios::in);

    if (archivo.is_open()) {
        while (!archivo.eof()) {
            Personaje p;
            string linea;

            getline(archivo, linea);
            if (archivo.eof()) {
                break;
            }
            p.setNombre(linea);

            getline(archivo, linea);
            p.setTipo(linea);

            getline(archivo, linea);
            int fuerza = stoi(linea);
            p.setFuerza(fuerza);

            getline(archivo, linea);
            int salud = stoi(linea);
            p.setSalud(salud);

            agregar(p);
        }
    }
}

void Videojuego::insertar(const Personaje &per, size_t p)
{
    arreglo.insert(arreglo.begin()+p, per);
}

void Videojuego::inicializar(const Personaje &per, size_t n)
{
    arreglo = vector<Personaje>(n, per);
}

void Videojuego::eliminar(size_t p)
{
    arreglo.erase(arreglo.begin()+p);
}

void Videojuego::sort()
{
    ::sort(arreglo.begin(), arreglo.end());
}

void Videojuego::sort_salud()
{
    ::sort(arreglo.begin(), arreglo.end(), [](const Personaje &a, const Personaje &b){return a.getSalud() < b.getSalud();});
}

Personaje *Videojuego::buscar(const Personaje &p)
{
//    vector<Personaje>::iterator it;
    auto it = find(arreglo.begin(), arreglo.end(), p);

    if (it == arreglo.end()) {
        return nullptr;
    }
    else {
        return &(*it);
    }
}












