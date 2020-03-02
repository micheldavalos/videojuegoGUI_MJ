#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <iostream>
#include <iomanip>
using namespace std;

class Personaje
{
public:
    Personaje();
    void setNombre(string n);
    string getNombre();
    int getSalud() const;
    void setSalud(int value);

    int getFuerza() const;
    void setFuerza(int value);

    string getTipo() const;
    void setTipo(const string &value);

    friend ostream & operator <<(ostream &out,
                                 const Personaje &p)
    {
        cout << right;
        out << setw(10) << p.nombre;
        out << setw(10) << p.tipo ;
        out << setw(7) << p.fuerza;
        out << setw(5) << p.salud;

        return out;
    }

    friend istream& operator >>(istream &in,
                                Personaje &p)
    {
        string s;
        int valor;

        cout << "Nombre: ";
        getline(cin, s);
        p.setNombre(s);

        cout << "Tipo: ";
        getline(cin, s);
        p.setTipo(s);

        cout << "Fuerza: ";
        cin >> valor;
        p.setFuerza(valor);

        cout << "Salud: ";
        cin >> valor; cin.ignore();
        p.setSalud(valor);

        return in;
    }

    bool operator<(const Personaje &p)const
    {
        return nombre < p.nombre;
    }

    bool operator==(const Personaje &p) const
    {
        return nombre == p.nombre;
    }

private:
    string nombre;
    int salud;
    int fuerza;
    string tipo;
};

#endif // PERSONAJE_H
