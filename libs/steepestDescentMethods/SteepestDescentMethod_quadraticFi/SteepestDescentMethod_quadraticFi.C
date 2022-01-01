
//////////////// constructor ///////////////////////

SteepestDescentMethod_quadraticFi::SteepestDescentMethod_quadraticFi (const char *path)
{
	X = new double [2];
    gradient = new double [2]; 
    
	readInputData(path);
	printInputData();
	
	X_ = new double [2];
	f = new double [3];
	stepSize_ = new double [3];
	for(int i=0;i<3;i++)
		stepSize_[i] = 0.1/pow(10,i+3);
}

//////////////////////////////////   destructor  ///////////////////////////////////////////////////

SteepestDescentMethod_quadraticFi::~SteepestDescentMethod_quadraticFi ()
{
   delete[] X;
   delete[] gradient;
   
   delete[] X_;
   delete[] stepSize_;
   delete[] f;
}

//////////////////////////////// public functions /////////////////////////////////////

double SteepestDescentMethod_quadraticFi::calcStepSize()
{
	for (int i=0;i<3;i++)
        {
			X_[0]= X[0] - stepSize_[i]*gradient[0];
			X_[1]= X[1] - stepSize_[i]*gradient[1];
			
			f[i] = main_function();       
		}
		
	best_step_size = calulate_minimum_of_guadratic_function();
			
    return best_step_size;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

double SteepestDescentMethod_quadraticFi::main_function()
{
    return  pow((a - X_[0]),2) + b*pow((X_[1] - X_[0]*X_[0]),2);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

double SteepestDescentMethod_quadraticFi::calulate_minimum_of_guadratic_function()
{
	int i;
	double **A_linearEq, *B_linearEq, *X_linearEq;
	
	B_linearEq = new double [3];
	X_linearEq = new double [3];
    A_linearEq = new double *[3];
    for(i = 0; i <3; i++)
		A_linearEq[i] = new double[3];
   
	for(i=0;i<3;i++)
		A_linearEq[i][0] = stepSize_[i]*stepSize_[i];
	for(i=0;i<3;i++)
		A_linearEq[i][1] = stepSize_[i];
	for(i=0;i<3;i++)
		A_linearEq[i][2] = 1.0;
		
	for(i=0;i<3;i++)
		B_linearEq[i] = f[i];
		
	linearEquations_solver(X_linearEq,A_linearEq,B_linearEq); 
	
    best_step_size = -X_linearEq[1]/(2.0*X_linearEq[0]);
    
    for(i = 0; i < 3; ++i) 
         delete[] A_linearEq[i];   
     
    delete[] A_linearEq;
    delete[] B_linearEq;
    delete[] X_linearEq;

	return best_step_size;
	
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void SteepestDescentMethod_quadraticFi::linearEquations_solver(double *x, double **A, double *B)
{
	int i,j,k,n=3;
    double a[n][n+1];        //declare an array to store the elements of augmented-matrix    

	for (i=0;i<n;i++)
		for(j=0;j<n;j++)
			a[i][j] = A[i][j];
	for (i=0;i<n;i++)
		a[i][n] = B[i];

    for (i=0;i<n;i++)                    //Pivotisation
        for (k=i+1;k<n;k++)
            if (fabs(a[i][i])< fabs(a[k][i]))
                for (j=0;j<=n;j++)
                {
                    double temp=a[i][j];
                    a[i][j]=a[k][j];
                    a[k][j]=temp;
                }
 
    for (i=0;i<n-1;i++)            //loop to perform the gauss elimination
        for (k=i+1;k<n;k++)
            {
                double t=a[k][i]/a[i][i];
                for (j=0;j<=n;j++)
                    a[k][j]=a[k][j]-t*a[i][j];    
            }
     

    for (i=n-1;i>=0;i--)                //back-substitution
    {                        
        x[i]=a[i][n];                 
        for (j=i+1;j<n;j++)
            if (j!=i)                                              
                x[i]=x[i]-a[i][j]*x[j];
        x[i]=x[i]/a[i][i];            
    }

}
