/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"


bool search(int value, int values[], int n)
{
    int start = 0 ;
    int end = n - 1 ;
    while (end >= start)
    {
        
        int middle = ((start + end) / 2) ;
        if (values[middle] == value)
        { 
            return true ;
              
        }
      
        if ( start == end )
        { 
            return false ;
        }
      
        if (values[middle] < value)
        { 
            start = middle + 1 ;
        }
       
         else
        {
            end = middle - 1 ;
        }
       
          
      
    }
    return false;
}


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
