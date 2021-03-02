#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPS 1e-6
#define TRUE (1<2)
#define FALSE (!TRUE)
//ternary search to find the optimal n value.
double tsearch(double lo, double hi, double k, double H);
//calculating function that uses the equation given to find the total number of years to wait.
double timecalc(double H, double k, double bound);
//function that calculates if the low and high bound are equal within 10^-6 decimal places.
int eq (double a, double b);

int main()
{
    //initiate variables
    int i, numcases;
    double  Hvalue, Kvalue;
    double * printarr;
    //scan in the number of cases
    scanf("%d", &numcases);
    //loop that does the ternary search for each case
    for(i=0; i<numcases; i++)
    {
    	//scan in the k and H values.
    	scanf("%lf", &Kvalue);
    	scanf("%lf", &Hvalue);
    	//allocates space for the print array.
    	if(i==0)
    	{
    	printarr = calloc(numcases, sizeof(double));
		}
		//low bound is set to 1 and high bound is set to k.
    	double lo = 1;
    	double hi = Kvalue;
    	//calls ternary search and allocates result to the print array.
    	double ans = tsearch(lo, hi, Kvalue, Hvalue);
    	printarr[i] = ans;			
	}
	//print array that prints the output.
	for(i=0;i<numcases;i++)
	{
		printf("%lf\n", printarr[i]);
	}
	//frees space allocated by print array.
     free(printarr);
    return 0;
}



double tsearch(double lo, double hi, double k, double H)
{
   
    if (eq(lo, hi))
        return timecalc(H, k, lo); 
    
    //computes midpoints.
    double m1 = (2 * lo + hi) / 3;
    double m2 = (lo + 2 * hi) / 3;
    
    //calculates number of years waited for each midpoint.
    double Years1 = timecalc(H, k, m1);
    double Years2 = timecalc(H, k, m2);
    
    //if midpoint 1 has a lower value, then calls search function again with updated bounds.
    if (Years1 < Years2) {
        
        return tsearch(lo, m2, k, H);
    }
    
    //if midpoint 2 has lower value, calls the search function again with updated bounds.
    return tsearch(m1, hi, k, H);
}

int eq (double a, double b)
{
    //checks is low bound - high bound is negative then gives absolute value.
    double diff = a - b;
    if (diff < 0)
        diff = -diff;
	//calculates if difference is less than 10^-6
    if (diff < EPS)
        return TRUE; 
    //returns false if values are not equal.
    return FALSE;
}



double timecalc(double H, double k, double bound)
{
    //calculates the total numbers of years needed to wait.
    return bound + ( k/(pow (H, sqrt(bound)))); 
}
