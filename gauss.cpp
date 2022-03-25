#include<iostream>
#include<stdlib.h>


using namespace std;

int main()
{
	 float a[10][10], x[10], ratio;
	 int i,j,y,n;

	 // 1. Reading number of unknowns 
	 cout<<"Enter number of unknowns: ";
	 cin>>n;

	 // 2. Entering matrix 
	 cout<<"Enter Coefficients of Augmented Matrix: "<< endl;
	 for(i=0;i<n;i++)
	 {
		  for(j=0;j<n+1;j++)
		  {
			   cout<<"a["<< i<<"]["<< j<<"]= "<<endl;
			   cin>>a[i][j];
		  }
	 }
	// Applying Gauss Elimination 
	 for(i=0;i<n-1;i++)
	 {
		  if(a[i][i] == 0.0)
		  {
			   cout<<" THERE IS A PIVOT EQUALS ZERO!";
			   exit(0);
		  }
		  for(j=i+1;j<=n;j++)
		  {
			   ratio = a[j][i]/a[i][i];

			   for(y=0;y<n+1;y++)
			   {
			  		a[j][y] = a[j][y] - ratio*a[i][y];
			   }
		  }
	 }
	 //Back Substitution
     //n is number of unknowns
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
	 cout<<"Solution: "<< endl;
	 for(i=0;i<n;i++)
	 {
	  	cout<<"x["<< i<<"] = "<< x[i]<< endl;
	 }

	 return(0);
}
