#include "immintrin.h"
#include <stdio.h>
#include <stdint.h>
#define _GNU_SOURCE
#include <math.h>


/* missing - / + and r^2 / a^2 */

__m256  _ZGVcN8v_sinf(__m256 x);
__m256  _ZGVcN8v_cosf(__m256 x);

typedef struct spiral {
  __m256 viv, vivsq, va, vasq;
  __m256 x, y, r0, r1;
  float b[8];


 } spiral;


void a(){

    spiral sx;

    sx.viv = _mm256_set_ps(2.0f, 4.0f, 8.0f, 16.0f, 32.0f, 64.0f, 128.0f, 256.0 );
    sx.viv = _ZGVcN8v_cosf(sx.viv);
    sx.vivsq = _mm256_sqrt_ps(sx.viv);
    sx.x = _mm256_mul_ps(sx.viv , sx.vivsq);


    printf("%12.8f %12.8f \n", sx.x[2], sx.x[3]);
}

void b(){

    spiral sx;

    sx.va = _mm256_set_ps(2.0f, 4.0f, 8.0f, 16.0f, 32.0f, 64.0f, 128.0f, 256.0f);
    sx.va = _ZGVcN8v_sinf(sx.va);
    sx.vasq = _mm256_sqrt_ps(sx.va);
    sx.y = _mm256_mul_ps(sx.va , sx.vasq);

    printf("%12.8f %12.8f \n", sx.y[2], sx.y[3]);
}

void c() {


    spiral sx;

 

    sx.r0 = _mm256_mul_ps(sx.x, sx.x);
    sx.r1 = _mm256_mul_ps(sx.y, sx.y);

    sx.r0 = _mm256_sqrt_ps(sx.r0);
    sx.r1 = _mm256_sqrt_ps(sx.r1);

    sx.r0 = _mm256_add_ps(sx.r0, sx.r1);
   _mm256_storeu_ps(sx.b, sx.r0);

   printf("%12.8f, %12.8f \n", sx.b[2], sx.b[3]);

}

void main(){

 spiral sx;

 a();
 b();
 c();
}
