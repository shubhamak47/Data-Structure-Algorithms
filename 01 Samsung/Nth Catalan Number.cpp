/* Catalan Number : 
Catalan numbers are a sequence of natural numbers that occurs in many interesting counting problems like following.
1) Count the number of expressions containing n pairs of parentheses which are correctly matched. For n = 3, 
possible expressions are ((())), ()(()), ()()(), (())(), (()()).

2) Count the number of possible Binary Search Trees with n keys (See this)

3) Count the number of full binary trees (A rooted binary tree is full if every vertex has either two children or no children) 
with n+1 leaves.

The first few Catalan numbers for n = 0, 1, 2, 3, … are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …
*/

Recursive function
/*********************** Time Comp : Exponential *******************************************/
 
unsigned long int catalan(unsigned int n) 
{ 
    if (n <= 1) return 1;                                  // Base case 
   
    unsigned long int res = 0;                             // catalan(n) is sum of catalan(i)*catalan(n-i-1)  
    for (int i=0; i<n; i++) 
        res += catalan(i)*catalan(n-i-1); 
  
    return res; 
} 


Using Binomial Coefficient:
/************************** Time Comp  : O(n) *****************************/
 
unsigned long int binomialCoeff(unsigned int n, unsigned int k) 
{ 
	unsigned long int res = 1; 
 
	if (k > n - k)                                     // Since C(n, k) = C(n, n-k) 
		k = n - k; 
 
	for (int i = 0; i < k; ++i)                       // Calculate value of [n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1]  
	{ 
		res *= (n - i); 
		res /= (i + 1); 
	} 
	return res; 
}

unsigned long int catalan(unsigned int n) 
{  
	unsigned long int c = binomialCoeff(2*n, n);              // Calculate value of 2nCn
	return c/(n+1);                                           // return 2nCn/(n+1) 
} 
