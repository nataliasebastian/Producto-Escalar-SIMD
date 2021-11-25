#!/bin/bash
gcc productoEscalar.c -lm -mavx2 -o ejecutable 
./ejecutable > output.txt
