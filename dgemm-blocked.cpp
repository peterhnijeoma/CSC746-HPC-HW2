#include <iostream>

const char* dgemm_desc = "Blocked dgemm.";

/* This routine performs a dgemm operation
 *  C := C + A * B
 * where A, B, and C are n-by-n matrices stored in column-major format.
 * On exit, A and B maintain their input values. */

void square_dgemm_blocked(int n, int block_size, double* A, double* B, double* C) 
{
  int ii, kk, jj;     // block row and col indexes
  //const int array_size = 1024;
  //double cvalue;      // accumulator
  //int num_blocks = (n/block_size); /* number of blocks; n is matrix size nXn*/

  // declare and dynamically allocate 2D arrays
  double **AA, **BB, **CC;
  AA = new double *[n];
  BB = new double *[n];
  CC = new double *[n];
  for (int i = 0; i < n; i++)
  {
     AA[i];
     BB[i];
     CC[i];
  }

  // display matrices
  std::cout << "A matrix - linear" << '\n';
  for (int i = 0; i < n*n; i++)
  {
    std::cout << A[i] << " ";
  }
  std::cout << "\n\n";

  //array_size = n;

  // copy column major vector A into 2D array 
  for (int i = 0; i < n*n; i+=n)
  {
     for (int j = 0; j < n; j++)
     {
        AA[j][i] = A[i+j];
     }
  }
  
  std::cout << "B matrix - linear" << '\n';
  for (int i = 0; i < n*n; i++)
  {
    std::cout << B[i] << " ";
  }
  std::cout << "\n\n";

  // copy column major vector B into 2D array
  for (int i = 0; i < n*n; i+=n)
  {
     for (int j = 0; j < n; j++)
     {
        BB[j][i] = B[i+j];
     }
  }
  
  // copy column major vector C into 2D array
  for (int i = 0; i < n*n; i+=n)
  {
     for (int j = 0; j < n; j++)
     {
        CC[j][i] = C[i+j];
     }
  }
  
  // block matrix multiplication logic
  for (ii = 0; ii < n; ii += block_size)  // partition rows by block size; iterate for n/block_size blocks
  {
    for (jj = 0; jj < n; jj += block_size) // partition columns by block size; iterate for n/block_size blocks
    {
      for (kk = 0; kk < n; kk += block_size)  // for each row and column of blocks
      {
        // basic matrix multiple applied to multiple blocks
        for (int arow = ii; arow < ii + block_size; arow++)
        {
          for (int bcol = jj; bcol < jj + block_size; bcol++)
          {
             //cvalue = 0.0; //C[i][j];
             for (int k = kk; k < kk + block_size; k++)
             {
                CC[arow][bcol] += AA[arow][k] * BB[k][bcol];
             }
             //C[bcol+arow] C[bcol*n+arow]
             //std::cout << "C[arow+bcol]- C[" << arow << "][" << bcol << "] = " << cvalue << '\n';
             //C[arow+bcol*n] = cvalue;
          }
        }
      }
    }
  }
  
  // copy 2d array CC to column major vector C
  for (int i = 0; i < n; i++)
  {
     for (int j = 0; j < n; j++)
     {
        C[i*n+j] = CC[j][i];
     }
  }

  // release allocated memory
  for (int i = 0; i < n; i++)
  {
     delete [] AA[i];
     delete [] BB[i];
     delete [] CC[i];
  }
  delete [] AA;
  delete [] BB;
  delete [] CC;

  std::cout << "\nC linear \n";
  for (int i = 0; i < n*n; i++)
  {
     std::cout << C[i] << " ";
  }
  std::cout << "\n\n";
}
