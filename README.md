# Interprete en C

## ¿Qué es un interprete?

## ¿Qué es un automata?

## ¿Qué es una gramatica libre de contexto?

---

# Lenguaje de ejemplo

## Alfabeto del lenguaje

## Automata y gramatica del lenguaje

## Codigó de ejemplo

---

# Configuración VSCode - MinGW

Para configurar VSCode de manera correcta para compilar nuestro proyecto, se necesita seguir las siguientes instrucciones:

- Abrir VSCode
- En la pestaña de extensiones, buscar C/C++
- Instalar C/C++ Extension Pack
- Descargar la ultima versión de [Mingw-64](https://www.msys2.org/)
- Abrir el instalador descargado y seguir las instrucciones
- Al finalizar la instalación, ejecutar el programa
- Para la instalación del compilar, escribir el siguiente comando
```
pacman -S --needed base-devel mingw-w64-x86_64-toolchain
```
- Verificar la versión instalada
```
gcc --version
```
- Abrir el menu Inicio y buscar "editar las variables de entorno del sistema"
- Dar clic en variables de entorno
- Dirigirse a la seccion variables del sistema; local --> path --> editar
- Colocar la variable de entorno C:\msys64\mingw64\bin
- Por ultimo abrir el simbolo de sistema, para volver a verificar la versión del compilador
```
gcc --version
```

> Nota: para actualizar los paquetes introducir el comando `pacman -Suy`