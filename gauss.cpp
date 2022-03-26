#include<iostream>
#define   m   10
using namespace std;

int main()
{
	 float a[m][m], x[m], ratio;
	 int i,j,k,n;

	 
	 // 1. Input number of unknowns 
	 cout<<"Enter number of unknowns: ";
	 cin>>n;

	 // 2. input Augmented Matrix 
	 cout<<"Enter Coefficients of Augmented Matrix: "<< endl;
	 for(i=1;i<=n;i++)
	 {
		  for(j=1;j<=n+1;j++)
		  {
			   cout<<"a["<< i<<"]["<< j<<"]= ";
			   cin>>a[i][j];
		  }
	 }
	// Applying Gauss Elimination 
	 for(i=1;i<=n-1;i++)
	 {
		  if(a[i][i] == 0.0)
		  {
			   for (int k=0; k<=n; k++)
				{
					double temp = a[i][k];
					a[i][k] = a[j][k];
					a[j][k] = temp;
				}
		  }
		  for(j=i+1;j<=n;j++)
		  {
			   ratio = a[j][i]/a[i][i];

			   for(k=1;k<=n+1;k++)
			   {
			  		a[j][k] = a[j][k] - ratio*a[i][k];
			   }
		  }
	 }
	 // Back Substitution Method 
	 x[n] = a[n][n+1]/a[n][n];

	 for(i=n-1;i>=1;i--)
	 {
		  x[i] = a[i][n+1];
		  for(j=i+1;j<=n;j++)
		  {
		  		x[i] = x[i] - a[i][j]*x[j];
		  }
		  x[i] = x[i]/a[i][i];
	 }

	 // Displaying Solution 
	 cout<< endl<<"Solution: "<< endl;
	 for(i=1;i<=n;i++)
	 {
	  	cout<<"x["<< i<<"] = "<< x[i]<< endl;
	 }

	 return(0);
}
