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
   double cvalue = 0.0;     // accumulator fo matrix rowXcolumn product

   for (int arow = 0; arow < n; arow++)
   {
      for (int bcol = 0; bcol < n; bcol++)
      {
         cvalue = 0.0; // initialize accumulator for another product value
         for (int k = 0; k < n; k++)
         {
            // accumulated matrix product
            // note that the indexes k and bcol are multiplied by n (the matrix size)
            // this is done to navigate the 1D vector properly 
            //cvalue += A[arow+k*n] * B[bcol*n+k];
            C[bcol*n+arow] += A[arow+k*n] * B[bcol*n+k];
         }
         //std::cout << "cvalue = " << cvalue << '\n';   //debug - show mul in action
         //std::cout << "C index is " << bcol*n+arow << '\n'; //debug - show product index - flat memory
         
         //C[bcol*n+arow] += cvalue; // write to product matrix - column major
      }
   }
}
