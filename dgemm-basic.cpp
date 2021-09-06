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
   std::cout << "matrix A elements - row major" << '\n';
   for (int i = 0; i <= n; i++)
   {
      for (int j = i; j < n*n; j+=n)
      {
         std::cout << A[j] << " ";
      }
      std::cout << '\n';
   }
   std::cout << "matrix A - linear " << '\n';
   for (int i = 0; i < n*n; i++)
   {
      std::cout << A[i] << " ";
   }
   std::cout << '\n';
   /*std::cout << "matrix A elements - col major" << '\n';
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         std::cout << A[j] << " ";
      }
      std::cout << '\n';
   }
   */

      // display matrices
   /* std::cout << "matrix B elements - row major" << '\n';
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         std::cout << B[i] << " ";
      }
      std::cout << '\n';
   }
   */
   std::cout << "matrix B - linear " << '\n';
   for (int i = 0; i < n*n; i++)
   {
      std::cout << B[i] << " ";
   }
   std::cout << '\n';

   std::cout << "matrix B elements - col major" << '\n';
   for (int i = 0; i < n; i++)
   {
      for (int j = i; j < n; j++)
      {
         std::cout << B[j] << " ";
      }
      std::cout << '\n';
   }
   
   for (int arow = 0; arow < n; arow++)
   {
      for (int bcol = 0; bcol < n; bcol++)
      {
         C[arow] = 0.0;
         for (int i = 0; i < n; i++)
         {
            C[arow] += A[arow] * B[bcol];
         }
      }      
   }
   
   std::cout << "product C - linear " << '\n';
   for (int i = 0; i < n*n; i++)
   {
      std::cout << C[i] << " ";
   }
   std::cout << '\n';
   
}
