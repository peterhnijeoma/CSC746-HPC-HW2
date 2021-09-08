#include <iostream>

const char* dgemm_desc = "Blocked dgemm.";

/* This routine performs a dgemm operation
 *  C := C + A * B
 * where A, B, and C are n-by-n matrices stored in column-major format.
 * On exit, A and B maintain their input values. */

void square_dgemm_blocked(int n, int block_size, double* A, double* B, double* C) 
{
  int kk, jj;     // block row and col indexes
  double cvalue;
  int en = (n/block_size); /* number of blocks */
   
  for (kk = 0; kk < en; kk += block_size)
  {
    for (jj = 0; jj < en; jj += block_size)
    {
      for (int arow = 0; arow < n; arow++)
      {
        for (int bcol = jj; bcol < jj + block_size; bcol++)
        {
           cvalue = 0.0; //C[i][j];
           for (int k = kk; k < kk + block_size; k++)
           {
              cvalue += A[arow+k] * B[bcol+k]; // A[arow+k*n] * B[bcol*n+k]; A[i][k] *B [k][j];
           }
           //C[bcol+arow] C[bcol*n+arow]
           std::cout << "C[i][j]" << cvalue;
           C[bcol+arow] = cvalue;
        }
      }
    }
  }

  for (int i = 0; i < n*n; i++)
  {
     std::cout << "C linear \n";
     std::cout << C[i] << '\n';
  }
  
}
