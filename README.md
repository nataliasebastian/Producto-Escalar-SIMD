
# PRODUCTO ESCALAR

## Sobre el proyecto

Este proyecto contiene dos progamas C para el cálculo del producto escalar entre dos vectores.  Uno de ellos utiliza una versión tradicional de suma vectorial, mientras que el otro hace uso de intrínsecos SIMD AVX2  (de Intel). El objetivo de este proyecto es comparar los tiempos de ejecución de ambas versiones.



## Diseñado con 
* [C](https://www.cprogramming.com/)
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

* [productoEscalar.c](productoEscalar.c)- programa que contiene dos métodos (uno tradicional, otro con intrínsecos SIMD) para el cálculo del producto escalar de 2 vectores en C. 
* [output.txt](output.txt) - contiene los resultados y tiempos de ejecución de productoEscalar.c
* [productoEscalar.sh](productoEscalar.sh) - contiene las instrucciones descritas en el apartado Uso
* [resultados.xlsx](resultados.xlsx) - hoja de cálculo con algunos resultados significativos de las ejecuciones y una representación gráfica

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
* Segunda opción: ejecutar [productoEscalar.sh](productoEscalar.sh) directamente (solo disponible para Linux y MacOS)
 	```sh
  	./productoEscalar.sh
 	 ```
 
## Resultados
Los tiempos de ejecución para distintos tamaños de vectorees se guardarán en output.txt para la versión tradicional y la versión SIMD.

El diagrama de dispersión para una muestra de 100 vectores es el siguiente:

<img width="563" alt="68747470733a2f2f692e706f7374696d672e63632f70724839543574772f4772612d666963612d636f6d70617261746976612e706e67" src="https://user-images.githubusercontent.com/81468329/144596031-61ce7dd9-01b5-452f-8f3f-73b6c727cf2c.png">


Como podemos observar, la versión SIMD es más rápida que la tradicional.


## Autores

Ane Romero  - aromero066@ikasle.ehu.eus

Diego Sanz - dsanz016@ikasle.ehu.eus

Natalia Sebastián  - nsebastian004@ikasle.ehu.eus




