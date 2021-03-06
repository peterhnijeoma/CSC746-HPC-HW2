/*
 * This routine performs a dgemm operation
 *  C := C + A * B
 * where A, B, and C are n-by-n matrices stored in column-major format.
 * On exit, A and B maintain their input values.
 */


#include <iostream>

const char* dgemm_desc = "Basic implementation, three-loop dgemm.";

void square_dgemm(int n, double* A, double* B, double* C) 
{
   double cvalue = 0.0;     // accumulator fo matrix col product

// all comment out code was used to understand and ensure that the flat memory
// and vector implementation was followed

/*   // display matrices
   std::cout << "matrix A elements - row major" << '\n';
   for (int i = 0; i < n; i++)
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
   std::cout << "matrix A elements - col major" << '\n';
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
   
   std::cout << "matrix B - linear " << '\n';
   for (int i = 0; i < n*n; i++)
   {
      std::cout << B[i] << " ";
   }
   std::cout << '\n';

   std::cout << "matrix B elements - col major" << '\n';
   for (int i = 0; i < n*n; i+=n)
   {
      for (int j = 0; j < n; j++)
      {
         std::cout << B[i+j] << " ";
      }
      std::cout << '\n';
   }
*/
   for (int arow = 0; arow < n; arow++)
   {
      for (int bcol = 0; bcol < n; bcol++)
      {
         cvalue = 0.0; // initialize accumulator for another product col value
         for (int k = 0; k < n; k++)
         {
            //cvalue += A[arow+bcol*n] * B[bcol+arow*n+k];
            
            cvalue += A[arow+k*n] * B[bcol*n+k];   // accumulated matrix product
            
            //std::cout << "A value = " << A[arow+k*n] << " B value = " << B[bcol*n+k] << '\n';
         }
         //std::cout << "cvalue = " << cvalue << '\n';   //debug - show mul in action
         //std::cout << "C index is " << bcol*n+arow << '\n'; //debug - show product index - flat memory
         
         C[bcol*n+arow] += cvalue; // write to product matrix
      }
   }
 /* //debuging code - to display matrix product as is in memory - flat
   std::cout << "product C - linear " << '\n';
   for (int i = 0; i < n*n; i++)
   {
      std::cout << C[i] << " ";
   }
   std::cout << '\n';
   */
}