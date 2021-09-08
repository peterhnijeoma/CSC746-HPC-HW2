#include <iostream>

const char* dgemm_desc = "Blocked dgemm.";

/* This routine performs a dgemm operation
 *  C := C + A * B
 * where A, B, and C are n-by-n matrices stored in column-major format.
 * On exit, A and B maintain their input values. */

void square_dgemm_blocked(int n, int block_size, double* A, double* B, double* C) 
{
  int ii, kk, jj;     // block row and col indexes
  double cvalue;
  int en = (n/block_size); /* number of blocks */

  // display matrices
  std::cout << "A matrix - linear" << '\n';
  for (int i = 0; i < n*n; i++)
  {
    std::cout << A[i] << " ";
  }
  std::cout << "\n\n";

  std::cout << "B matrix - linear" << '\n';
  for (int i = 0; i < n*n; i++)
  {
    std::cout << B[i] << " ";
  }
  std::cout << "\n\n";
   
  for (ii = 0; ii < en; kk++)
  {
    for (jj = 0; jj < en; jj++)
    {
      for (kk = 0; kk < en; kk++)
      {
        for (int arow = ii; arow < ii + block_size; arow += block_size)
        {
          for (int bcol = jj; bcol < jj + block_size; bcol++)
          {
             cvalue = 0.0; //C[i][j];
             for (int k = kk; k < kk + block_size; k++)
             {
                cvalue += A[arow+k] * B[bcol+k]; // A[arow+k*n] * B[bcol*n+k]; A[i][k] *B [k][j];
             }
             //C[bcol+arow] C[bcol*n+arow]
             std::cout << "C[arow+bcol]- C[" << arow << "][" << bcol << "] = " << cvalue << '\n';
             C[arow+bcol*n] = cvalue;
          }
        }
      }
    }
  }
  
  std::cout << "\nC linear \n";
  for (int i = 0; i < n*n; i++)
  {
     std::cout << C[i] << " ";
  }
  std::cout << "\n\n";
}
