
/////////////////////////////////// New function ///////////////////////////

baseSolver* baseSolver::New(const char *path)
{
	string solverType;
	
	ifstream file(path);

	string searchForSolverType = "solverType";
	
	string lineOfText;

	for(;;)
	{	
		getline(file, lineOfText);
			  
		if (file.eof()) break;
		
		if (lineOfText.find(searchForSolverType, 0) != string::npos)
		  file >> solverType;		  	  
    }
    
    file.close();
    
    baseSolver* myObject = 0;
    
    if (solverType=="SteepestDescentMethod_constantStepSize")
    {
	    myObject = new SteepestDescentMethod_constantStepSize(path);
	    return myObject;
    }
    
	  
    else if (solverType=="SteepestDescentMethod_variableStepSize")
    {
	    myObject = new SteepestDescentMethod_variableStepSize(path);
	    return myObject;
    }   
    
    else if (solverType=="SteepestDescentMethod_quadraticFi")
    {
	    myObject = new SteepestDescentMethod_quadraticFi(path);
	    return myObject;
    }
    
    else if (solverType=="NewtonRaphsonMethod")
    {
	    myObject = new NewtonRaphsonMethod(path);
	    return myObject;
    }
}

//////////////////////////////// public functions /////////////////////////////////////

void baseSolver::readInputData(const char *path)
{
	ifstream file(path);

	string searchFor_a = "coefficient_a";
	string searchFor_b = "coefficient_b";
	string searchFor_x1 = "initialGuess_x1";
	string searchFor_x2 = "initialGuess_x2";
	string searchForSolverType = "solverType";
	string searchForMaxError = "maximumErrorForSolving";
		

	string lineOfText;

	for(;;)
	{	
		getline(file, lineOfText);
			  
		if (file.eof()) break;
		
		if (lineOfText.find(searchFor_a, 0) != string::npos)
		  file >> a;
		
		if (lineOfText.find(searchFor_b, 0) != string::npos)
		  file >> b;
		  	  
		if (lineOfText.find(searchFor_x1, 0) != string::npos)
		  file >> X[0];      	  	  
		
		if (lineOfText.find(searchFor_x2, 0) != string::npos)
		  file >> X[1]; 		  	  	  
		
		if (lineOfText.find(searchForSolverType, 0) != string::npos)
		  file >> solverType;
		  
		if (lineOfText.find(searchForMaxError, 0) != string::npos)
		  file >> max_Error;
    }
    
    file.close();
     	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

void baseSolver::printInputData()
{
	cout << "input data for the simulation: " << endl << endl;
	cout << "solver type is: " << solverType << endl;
	cout << "coefficient_a in Rosenbrock Function is: " << a << endl;
	cout << "coefficient_b in Rosenbrock Function is: " << b << endl;
	cout << "initial guess for x1 is: " << X[0] << endl;
	cout << "initial guess for x2 is: " << X[1] << endl;
	cout << "maximum error for solving: " << max_Error << endl;
		
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void baseSolver::gradient_F()
{
	gradient[0] = -2.0*b*2.0*X[0]*(X[1] - X[0]*X[0]) - 2.0*(a - X[0]) ;
    gradient[1] = 2.0*b*(X[1] - X[0]*X[0]);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

double baseSolver::norm()
{
	double sum=0;
    for (int i=0;i<2;i++)
        sum=gradient[i]*gradient[i];

    return sqrt(sum);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void baseSolver::gradient_unit()
{
	gradient[0]=gradient[0]/norm();
    gradient[1]=gradient[1]/norm();
}
