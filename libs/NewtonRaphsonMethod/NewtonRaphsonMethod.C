
//////////////// constructor ///////////////////////

NewtonRaphsonMethod::NewtonRaphsonMethod (const char *path)
{
	X = new double [2];
    gradient = new double [2];

	readInputData(path);
	printInputData();

	Hessian = new double *[2];
    for(int i = 0; i <2; i++)
		Hessian[i] = new double[2];
}

//////////////////////////////////   destructor  ///////////////////////////////////////////////////

NewtonRaphsonMethod::~NewtonRaphsonMethod ()
{
   delete[] X;
   delete[] gradient;

   for(int i = 0; i < 2; ++i)
         delete[] Hessian[i];

   delete[] Hessian;
}

//////////////////////////////// public function /////////////////////////////////////

double* NewtonRaphsonMethod::solveAndWriteXinEachIteration()
{
	int count=0;
	double error;

    ofstream file;
    file.open("trendOf_X.txt");

    file<< "iteration" << '\t' <<'\t' << "x1" <<'\t'<<'\t'<<'\t'<< "x2" << endl << endl;

    do
    {
		count++;

		gradient_F();

        error=norm();

        Hessian_F();

        invers_Hessian();

        if( (Hessian[0][0] <= 0) || (Hessian[1][1] <= 0) )
		{
			cout << endl << "your initial guess ineligible, because the inverse of Hessian matrix"
				 <<	" is not positive definite. Please enter another initial guess in inputData.txt: " << endl << endl;
		    exit(EXIT_FAILURE);
		}

        X[0] = X[0] - ( Hessian[0][0]*gradient[0] + Hessian[0][1]*gradient[1] );
        X[1] = X[1] - ( Hessian[1][0]*gradient[0] + Hessian[1][1]*gradient[1] );

        file << count  << '\t' << '\t' <<'\t' << std::fixed << std::setprecision(6) << X[0] <<'\t'<<'\t'<< X[1] << endl;

    }while (error > max_Error);

    file.close();

    cout<<endl<<"number of iteration to find X vector = "<< count << endl << endl;

    return X;

}

//////////////////////////////// private functions /////////////////////////////////////

void NewtonRaphsonMethod::Hessian_F()
{
	Hessian[0][0] = 2.0 + 12.0*b*X[0]*X[0] - 4.0*b*X[1];
	Hessian[0][1] = -4.0*b*X[0];
	Hessian[1][0] = -4.0*b*X[0];
	Hessian[1][1] = 2.0*b;
}

/////////////////////////////////////////////////////////////////////////////

void NewtonRaphsonMethod::invers_Hessian()
{
	double determinant, temp;

	determinant = Hessian[0][0]*Hessian[1][1] - Hessian[0][1]*Hessian[1][0];

	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			Hessian[i][j] = 1.0*Hessian[i][j]/determinant;

	temp = Hessian[0][0];
	Hessian[0][0] = Hessian[1][1];
	Hessian[1][1] = temp;
	Hessian[0][1] = -1.0*Hessian[0][1];
	Hessian[1][0] = -1.0*Hessian[1][0];
}

