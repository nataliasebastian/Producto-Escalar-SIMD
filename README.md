
# PRODUCTO ESCALAR

## Sobre el proyecto

Este proyecto contiene dos progamas C para el cálculo del producto escalar entre dos vectores.  Uno de ellos utiliza una versión tradicional de suma vectorial, mientras que el otro hace uso de intrínsecos SIMD AVX2  (de Intel). El objetivo de este proyecto es comparar los tiempos de ejecución de ambas versiones.



## Diseñado con 
* [C++](https://www.cplusplus.com/)
* [Intrínsecos AVX2](https://www.intel.es/content/www/es/es/architecture-and-technology/avx-512-overview.html)


## Prerequisitos

* gcc

	Linux:
  ```sh
  sudo apt-get install gcc
  ```
	Mac:
  ```sh
  /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
  ```
	Windows:

	Descargar e instalar [MinGW](https://sourceforge.net/projects/mingw/)


## Descripción de archivos

* productoEscalar.c - programa que contiene dos métodos (uno tradicional, otro con intrínsecos SIMD) para el cálculo del producto escalar de 2 vectores en C. 
* output.txt - contiene los resultados y tiempos de ejecución de productoEscalar.c
* productoEscalar.sh - contiene las instrucciones descritas en el apartado Uso
* resultados.xlsx - hoja de cálculo con algunos resultados significativos de las ejecuciones y una representación gráfica

## Uso
* Primera opción:
1. Compilar los proyectos usando GNU Compiler Collection
	 ```sh
  	gcc productoEscalar.c -lm -mavx2 -o ejecutable
 	 ```
	
2. Ejecución
   ```sh
   ./ejecutable > output.txt
   ```
* Segunda opción: ejecutar [productoEscalar.sh](productoEscalar.sh) directamente
 	```sh
  	./productoEscalar.sh
 	 ```
 
## Resultados



## Autores

Ane Romero  - aromero066@ikasle.ehu.eus

Diego Sanz - dsanz016@ikasle.ehu.eus

Natalia Sebastián  - nsebastian004@ikasle.ehu.eus




