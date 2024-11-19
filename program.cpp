#include <iostream>
#include <string>

using namespace std;

struct nodo {
    int codigo;
    string nombreProducto;
    int cantidad;
    float precio;
    nodo *izq = NULL;
    nodo *der = NULL;
};

void registrar(nodo *&nuevo);
void inserta(nodo *&arbol, nodo *&nuevo);
void insertarProducto(nodo *&arbol);
void imprime(nodo *arbol, int c);
void preorden(nodo *arbol);
void enorden(nodo *arbol);
void posorden(nodo *arbol);
void buscarProducto(nodo *arbol);
void eliminarProducto(nodo *&arbol);
void eliminarNodo(nodo *&arbol, int codigo);
void encontrarMinimo(nodo *arbol);
void actualizarProducto(nodo *arbol);
void mostrarMenu();
void cargarProductosPrueba(nodo *&arbol);

int main() {
    nodo *arbol = NULL;
    int *opcion = new int;

    cargarProductosPrueba(arbol);
    do {
        mostrarMenu();
        cin >> *opcion;

        switch (*opcion) {
            case 1:
                cout << "\nInsertando Producto:" << endl;
                insertarProducto(arbol);
                break;
            case 2:
                cout << "\nBuscando Producto por codigo:" << endl;
                buscarProducto(arbol);
                break;
            case 3:
                cout << "\nEliminando producto:" << endl;
                eliminarProducto(arbol);
                cout << endl;
                break;
            case 4:
                cout << "\nActualizando Producto:" << endl;
                actualizarProducto(arbol);
                cout << endl;
                break;
            case 5:
                cout << "\nArbol impreso de forma jerarquica:" << endl;
                imprime(arbol, 1);
                break;
            case 6:
                cout << "\nRecorrido en Preorden:" << endl;
                preorden(arbol);
                cout << endl;
                break;
            case 7:
                cout << "\nRecorrido en Enorden:" << endl;
                enorden(arbol);
                cout << endl;
                break;
            case 8:
                cout << "\nRecorrido en Posorden:" << endl;
                posorden(arbol);
                cout << endl;
                break;
            case 9:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } while (*opcion != 9);

    delete opcion;
    return 0;
}

void registrar(nodo *&nuevo) {
    cout << "Ingrese codigo: ";
    cin >> nuevo->codigo;
    cout << "Ingrese nombre del producto: ";
    cin.ignore();
    getline(cin, nuevo->nombreProducto);
    cout << "Ingrese cantidad: ";
    cin >> nuevo->cantidad;
    cout << "Ingrese precio: ";
    cin >> nuevo->precio;
}

void inserta(nodo *&arbol, nodo *&nuevo) {
    if (arbol == NULL) {
        arbol = nuevo;
        cout << "Hoja Insertada [" << nuevo->codigo << "]" << endl;
    } else {
        if (nuevo->codigo < arbol->codigo)
            inserta(arbol->izq, nuevo);
        else
            inserta(arbol->der, nuevo);
    }
}

void insertarProducto(nodo *&arbol) {
    nodo *nuevo = new nodo;
    registrar(nuevo);
    inserta(arbol, nuevo);
}

void imprime(nodo *arbol, int c) {
    if (arbol == NULL)
        return;
    imprime(arbol->der, c + 1);
    for (int i = 0; i < c; i++)
        cout << " ";
    cout << arbol->codigo << endl;
    imprime(arbol->izq, c + 1);
}

void preorden(nodo *arbol) {
    if (arbol == NULL)
        return;
    cout << arbol->codigo << " ";
    preorden(arbol->izq);
    preorden(arbol->der);
}

void enorden(nodo *arbol) {
    if (arbol == NULL)
        return;
    enorden(arbol->izq);
    cout << arbol->codigo << " ";
    enorden(arbol->der);
}

void posorden(nodo *arbol) {
    if (arbol == NULL)
        return;
    posorden(arbol->izq);
    posorden(arbol->der);
    cout << arbol->codigo << " ";
}

void buscarProducto(nodo *arbol) {
    if (arbol == NULL) {
        cout << "Arbol vacío. No hay productos para buscar." << endl;
        return;
    }

    int codigo;
    cout << "Ingrese el codigo del producto que desea buscar: ";
    cin >> codigo;

    while (arbol != NULL) {
        if (codigo == arbol->codigo) {
            cout << "Producto encontrado: " << endl;
            cout << "Codigo: " << arbol->codigo << endl;
            cout << "Nombre: " << arbol->nombreProducto << endl;
            cout << "Cantidad: " << arbol->cantidad << endl;
            cout << "Precio: " << arbol->precio << endl;
            return;
        } else if (codigo < arbol->codigo) {
            arbol = arbol->izq;
        } else {
            arbol = arbol->der;
        }
    }

    cout << "Producto no encontrado." << endl;
}

void encontrarMinimo(nodo*& arbol, nodo*& minimo) {
    if (!arbol) return;
    if (!arbol->izq) {
        minimo = arbol;
    } else {
        encontrarMinimo(arbol->izq, minimo);
    }
}

void eliminarNodo(nodo*& arbol, int codigo) {
    if (!arbol) {
        cout << "No se encontró el producto con el código " << codigo << ".\n";
        return;
    }

    if (codigo < arbol->codigo) {
        eliminarNodo(arbol->izq, codigo);
    } else if (codigo > arbol->codigo) {
        eliminarNodo(arbol->der, codigo);
    } else {
        // Nodo encontrado
        nodo* temp = nullptr;
        if (!arbol->izq && !arbol->der) {
            // Caso 1: Nodo hoja
            delete arbol;
            arbol = nullptr;
        } else if (!arbol->izq) {
            // Caso 2: Nodo con un hijo derecho
            temp = arbol;
            arbol = arbol->der;
            delete temp;
        } else if (!arbol->der) {
            // Caso 2: Nodo con un hijo izquierdo
            temp = arbol;
            arbol = arbol->izq;
            delete temp;
        } else {
            // Caso 3: Nodo con dos hijos
            nodo* minimo = nullptr;
            encontrarMinimo(arbol->der, minimo); // Encontrar mínimo del subárbol derecho
            arbol->codigo = minimo->codigo;
            arbol->nombreProducto = minimo->nombreProducto;
            arbol->cantidad = minimo->cantidad;
            arbol->precio = minimo->precio;
            eliminarNodo(arbol->der, minimo->codigo); // Eliminar el nodo duplicado
        }
    }
}

void eliminarProducto(nodo *&arbol) {
    if (arbol == NULL) {
        cout << "Arbol vacío. No hay productos para eliminar." << endl;
        return;
    }

    int codigo;
    cout << "Ingrese el codigo del producto que desea eliminar: ";
    cin >> codigo;

    eliminarNodo(arbol, codigo);
    cout << "Producto eliminado (si existia)." << endl;
}

void actualizarProducto(nodo *arbol) {
    if (arbol == NULL) {
        cout << "Arbol vacío. No hay productos para actualizar." << endl;
        return;
    }

    int codigo;
    cout << "Ingrese el codigo del producto que desea actualizar: ";
    cin >> codigo;

    while (arbol != NULL) {
        if (codigo == arbol->codigo) {
            cout << "Producto encontrado. Ingrese los nuevos datos:" << endl;
            cout << "Nuevo nombre: ";
            cin.ignore();
            getline(cin, arbol->nombreProducto);
            cout << "Nueva cantidad: ";
            cin >> arbol->cantidad;
            cout << "Nuevo precio: ";
            cin >> arbol->precio;
            cout << "Producto actualizado con exito." << endl;
            return;
        } else if (codigo < arbol->codigo) {
            arbol = arbol->izq;
        } else {
            arbol = arbol->der;
        }
    }

    cout << "Producto no encontrado." << endl;
}

void mostrarMenu() {
    cout << "\n------------------------------------------------";
    cout << "\n|               Tienda de Todo                 |";
    cout << "\n------------------------------------------------" << endl;
    cout << "| [1] Insertar un Producto                     |" << endl;
    cout << "| [2] Buscar un Producto                       |" << endl;
    cout << "| [3] Eliminar un Producto                     |" << endl;
    cout << "| [4] Actualizar un Producto                   |" << endl;
    cout << "| [5] Imprimir arbol (forma jerarquica)        |" << endl;
    cout << "| [6] Recorrido en Preorden                    |" << endl;
    cout << "| [7] Recorrido en Enorden                     |" << endl;
    cout << "| [8] Recorrido en Posorden                    |" << endl;
    cout << "| [9] Salir                                    |";
    cout << "\n------------------------------------------------" << endl;
    cout << "\tSeleccione una opcion (1-9): ";
}

void cargarProductosPrueba(nodo *&arbol) {
    int codigos[20] = {505, 303, 707, 202, 404, 606, 808, 101, 250, 350, 
                       550, 650, 750, 850, 950, 150, 225, 325, 450, 675};
    
    string nombres[20] = {
        "Laptop HP", "Teclado Mecanico", "Mouse Gamer", "Monitor 24''", "Audífonos Bluetooth",
        "Silla Gamer", "Escritorio Oficina", "Impresora Multifunción", "Router WiFi", "Cámara Web",
        "Smartphone Samsung", "Tablet Lenovo", "Cargador Universal", "Disco Duro Externo", "Memoria USB",
        "Bicicleta Montania", "Casco Deportivo", "Batería Recargable", "Linterna LED", "Reloj Inteligente"
    };

    int cantidades[20] = {5, 10, 15, 8, 20, 
                          4, 7, 6, 12, 10, 
                          25, 18, 30, 14, 50, 
                          3, 9, 22, 11, 16};

    float precios[20] = {1200.5, 150.75, 80.99, 200.4, 60.5, 
                         300.99, 250.0, 180.6, 100.8, 70.9, 
                         850.3, 600.0, 25.5, 90.2, 15.0, 
                         500.5, 45.0, 30.99, 20.5, 150.75};

    for (int i = 0; i < 20; i++) {
        nodo *nuevo = new nodo;
        nuevo->codigo = codigos[i];
        nuevo->nombreProducto = nombres[i];
        nuevo->cantidad = cantidades[i];
        nuevo->precio = precios[i];
        inserta(arbol, nuevo);
    }
}

