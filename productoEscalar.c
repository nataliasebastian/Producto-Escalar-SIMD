#include <stdio.h>
#include <immintrin.h>
#include <math.h>
#include <time.h>
double productoEscalarSIMD(const double *a, const double *b, int N) {
	double answer = 0.0;
 	for(int i = 0; i < N; ++i)
		answer += a[i]*b[i];
 	return answer;
}

/* Reducción de los vectores */
double reducirVector(__m256d input) {
       __m256d temp = _mm256_hadd_pd(input, input);
       __m128d sum_high = _mm256_extractf128_pd(temp, 1);
       __m128d result = _mm_add_pd(sum_high, _mm256_castpd256_pd128(temp));
       return ((double*)&result)[0];
}

double productoEscalarConSIMD(const double *a, const double *b, int N) {
 __m256d sum_vec = _mm256_set_pd(0.0, 0.0, 0.0, 0.0);
 
 /* Sumar productos escalares parciales en bloques de 256 bits */
 for(int i = 0; i < N/4; ++i) {
   __m256d x = _mm256_load_pd(a+4*i);
   __m256d y = _mm256_load_pd(b+4*i);
   __m256d z = _mm256_mul_pd(x,y);
   sum_vec = _mm256_add_pd(sum_vec, z);
 }
 
 /* Se calculará el producto escalar para los elementos restantes */
 double final = 0.0;
 for(int i = N-N%4; i < N; ++i)
   final += a[i] * b[i];
 
 return reducirVector(sum_vec) + final;
}
 


int main() {
  unsigned t0, t1, t2, t3;

  for (int j=1; j<=100000; ++j){
	  const int N=j;	
	   __attribute__ ((aligned (32))) double a[N], b[N];
	   for(int i = 0; i < N; ++i){	 
    	   	a[i] = b[i] = i/sqrt(N);   	  
	   }

  
  t0=clock();
  printf("Resultado con SIMD para N= %d: %f\n", N, productoEscalarConSIMD(a, b, N));
  t1=clock(); 
  long double time = (long double)(t1-t0)/CLOCKS_PER_SEC;
  printf("Tiempo con SIMD: %Lf s\n",  time);

  t2=clock();
  printf("Resultado sin SIMD para N= %d: %f\n", N, productoEscalarSIMD(a,b, N));
  t3=clock();
  long double time2 = (long double)(t3-t2)/CLOCKS_PER_SEC;

  printf("Tiempo sin SIMD: %Lf s\n",  time2);



  }

 
}
