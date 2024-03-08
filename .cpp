#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Clase abstracta para Persona
class Persona {
protected:
    int nIDPersona;
    string nombre;
    string apellido;
    string correo;

public:
    Persona(int id, const string& nombre, const string& apellido) : nIDPersona(id), nombre(nombre), apellido(apellido) {
        correo = nombre + "." + apellido + "@gmail.com"; // Generar correo
    }

    virtual void mostrarDatos() const = 0;

    virtual bool buscar(const string& letras) const {
        return nombre.find(letras) != string::npos || apellido.find(letras) != string::npos;
    }
};

// Clase Usuario
class Usuario : public Persona {
private:
    string direccion;

public:
    Usuario(int id, const string& nombre, const string& apellido, const string& dir) : Persona(id, nombre, apellido), direccion(dir) {}

    void mostrarDatos() const override {
        cout << "ID: " << nIDPersona << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Apellido: " << apellido << endl;
        cout << "Correo: " << correo << endl;
        cout << "Dirección: " << direccion << endl;
        cout << endl;
    }
};

// Clase Bibliotecario
class Bibliotecario : public Persona {
private:
    string fechaNacimiento;

public:
    Bibliotecario(int id, const string& nombre, const string& apellido, const string& fechaNac) : Persona(id, nombre, apellido), fechaNacimiento(fechaNac) {}

    void mostrarDatos() const override {
        cout << "ID: " << nIDPersona << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Apellido: " << apellido << endl;
        cout << "Correo: " << correo << endl;
        cout << "Fecha de Nacimiento: " << fechaNacimiento << endl;
        cout << endl;
    }
};

// Clase GestorUsuarios
class GestorUsuarios {
private:
    vector<Usuario> usuarios;
    vector<Bibliotecario> bibliotecarios;

public:
    // Método para agregar un usuario
    void agregarUsuario(const Usuario& usuario) {
        usuarios.push_back(usuario);
    }

    // Método para agregar un bibliotecario
    void agregarBibliotecario(const Bibliotecario& bibliotecario) {
        bibliotecarios.push_back(bibliotecario);
    }

    // Método para imprimir usuarios
    void imprimirUsuarios() const {
        cout << "\nLISTADO DE USUARIOS:" << endl;
        for (const auto& usuario : usuarios) {
            usuario.mostrarDatos();
        }
    }

    // Método para imprimir bibliotecarios
    void imprimirBibliotecarios() const {
        cout << "\nLISTADO DE BIBLIOTECARIOS:" << endl;
        for (const auto& bibliotecario : bibliotecarios) {
            bibliotecario.mostrarDatos();
        }
    }

    // Método para buscar usuarios
    void buscarUsuarios(const string& letras) const {
        cout << "\nBUSCAR USUARIO:" << endl;
        cout << "Número de coincidencias encontradas: ";
        int contador = 0;
        for (const auto& usuario : usuarios) {
            if (usuario.buscar(letras)) {
                usuario.mostrarDatos();
                contador++;
            }
        }
        cout << contador << endl;
    }

    // Método para buscar bibliotecarios
    void buscarBibliotecarios(const string& letras) const {
        cout << "\nBUSCAR BIBLIOTECARIO:" << endl;
        cout << "Número de coincidencias encontradas: ";
        int contador = 0;
        for (const auto& bibliotecario : bibliotecarios) {
            if (bibliotecario.buscar(letras)) {
                bibliotecario.mostrarDatos();
                contador++;
            }
        }
        cout << contador << endl;
    }
};

int main() {
    GestorUsuarios gestorUsuarios;
    int opcion;

    do {
        cout << "\nMENU" << endl;
        cout << "1. Agregar Usuario/Bibliotecario" << endl;
        cout << "2. Listar Usuarios/Bibliotecarios" << endl;
        cout << "3. Buscar Usuario/Bibliotecario" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int tipo;
                cout << "\nSeleccione el tipo de persona a agregar:" << endl;
                cout << "1. Usuario" << endl;
                cout << "2. Bibliotecario" << endl;
                cout << "Ingrese el tipo: ";
                cin >> tipo;

                int id;
                string nombre, apellido;
                cout << "Ingrese ID: ";
                cin >> id;
                cout << "Ingrese Nombre: ";
                cin >> nombre;
                cout << "Ingrese Apellido: ";
                cin >> apellido;

                if (tipo == 1) {
                    string direccion;
                    cout << "Ingrese Dirección: ";
                    cin >> direccion;
                    Usuario nuevoUsuario(id, nombre, apellido, direccion);
                    gestorUsuarios.agregarUsuario(nuevoUsuario);
                } else if (tipo == 2) {
                    string fechaNacimiento;
                    cout << "Ingrese Fecha de Nacimiento: ";
                    cin >> fechaNacimiento;
                    Bibliotecario nuevoBibliotecario(id, nombre, apellido, fechaNacimiento);
                    gestorUsuarios.agregarBibliotecario(nuevoBibliotecario);
                } else {
                    cout << "Opción no válida." << endl;
                }
                break;
            }
            case 2: {
                int tipo;
                cout << "\nSeleccione el tipo de persona a listar:" << endl;
                cout << "1. Usuarios" << endl;
                cout << "2. Bibliotecarios" << endl;
                cout << "Ingrese el tipo: ";
                cin >> tipo;

                if (tipo == 1) {
                    gestorUsuarios.imprimirUsuarios();
                } else if (tipo == 2) {
                    gestorUsuarios.imprimirBibliotecarios();
                } else {
                    cout << "Opción no válida." << endl;
                }
                break;
            }
            case 3: {
                int tipo;
                cout << "\nSeleccione el tipo de persona a buscar:" << endl;
                cout << "1. Usuario" << endl;
                cout << "2. Bibliotecario" << endl;
                cout << "Ingrese el tipo: ";
                cin >> tipo;

                string letras;
                cout << "Ingrese letras a buscar: ";
                cin >> letras;

                if (tipo == 1) {
                    gestorUsuarios.buscarUsuarios(letras);
                } else if (tipo == 2) {
                    gestorUsuarios.buscarBibliotecarios(letras);
                } else {
                    cout << "Opción no válida." << endl;
                }
                break;
            }
            case 0:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida." << endl;
                break;
        }
    } while (opcion != 0);

    return 0;
}