/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"



/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    for ( int i = 0 ; i < n - 1 ; i++)
    { 
        int first = i ;
        for ( int j = i + 1 ; j < n ; j++)
        {
            if (values[first] > values[j])
            {
                first = j ;
            }
        }
          
        int temp = values[i] ;
        values[i] = values[first] ;
        values[first] = temp ;
    }
    return ;
}
