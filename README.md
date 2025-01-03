# Pseudocódigo del Sistema de Gestión de Productos

## Estructura del Nodo
Cada nodo contiene:
- `codigo`: código único del producto
- `nombreProducto`: nombre del producto
- `cantidad`: cantidad en inventario
- `precio`: precio del producto
- `izq`: puntero al nodo izquierdo
- `der`: puntero al nodo derecho

## Funciones

### 1. registrar
Solicita al usuario ingresar los datos del producto (código, nombre, cantidad, precio).

### 2. inserta
Inserta un nuevo nodo en el árbol binario en la posición correcta según el código del producto.

### 3. insertarProducto
Crea un nuevo nodo y lo inserta en el árbol llamando a la función `inserta`.

### 4. imprime
Imprime el árbol de productos en forma jerárquica.

### 5. preorden
Recorre el árbol en preorden (raíz, izquierda, derecha) y muestra los códigos de los productos.

### 6. enorden
Recorre el árbol en enorden (izquierda, raíz, derecha) y muestra los códigos de los productos.

### 7. posorden
Recorre el árbol en posorden (izquierda, derecha, raíz) y muestra los códigos de los productos.

### 8. buscarProducto
Busca un producto por código y muestra sus detalles si lo encuentra.

### 9. eliminarNodo
Elimina un nodo del árbol según el código del producto, manejando tres casos:
- Nodo hoja
- Nodo con un hijo
- Nodo con dos hijos (reemplaza el nodo con el mínimo del subárbol derecho).

### 10. eliminarProducto
Solicita el código del producto a eliminar y llama a `eliminarNodo` para eliminarlo del árbol.

### 11. actualizarProducto
Busca un producto por código y permite actualizar su nombre, cantidad y precio.

### 12. mostrarMenu
Muestra las opciones del menú de la tienda.

### 13. cargarProductosPrueba
Carga una lista de productos de prueba en el árbol binario de búsqueda.

## Flujo Principal

1. **Carga de productos de prueba**
   - Se cargan productos predeterminados en el árbol.

2. **Menú principal**
   - El usuario puede elegir entre las siguientes opciones:
     - Insertar un producto
     - Buscar un producto
     - Eliminar un producto
     - Actualizar un producto
     - Imprimir el árbol en forma jerárquica
     - Recorrer el árbol en preorden, enorden o posorden
     - Salir del programa
