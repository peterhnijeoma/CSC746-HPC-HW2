#include <iostream>

const char* dgemm_desc = "Basic implementation, three-loop dgemm.";

/*
 * This routine performs a dgemm operation
 *  C := C + A * B
 * where A, B, and C are n-by-n matrices stored in column-major format.
 * On exit, A and B maintain their input values.
 */
void square_dgemm(int n, double* A, double* B, double* C) 
{
   // display matrices
   std::cout << "matrix A elements" << '\n';
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         std::cout << A[i][j];
      }
      std::cout << '\n';
   }
   
 /*  
   for (int arow = 0; arow < n; arow++)
   {
      for (int bcol = 0; bcol < n; bcol++)
      {
         C[arow, bcol] = 0.0;
         for (int i = 0; i < n; i++)
         {
            C[arow, bcol] += A[arow, i] * B[i, bcol];
         }
      }
      
   }
   */
}
