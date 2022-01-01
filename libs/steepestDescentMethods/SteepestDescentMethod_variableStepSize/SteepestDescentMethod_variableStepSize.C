
//////////////// constructor ///////////////////////

SteepestDescentMethod_variableStepSize::SteepestDescentMethod_variableStepSize (const char *path)
{
	X = new double [2];
    gradient = new double [2]; 	
    
	readInputData(path);
	printInputData();
	
	X_ = new double [2];
	
	stepSize_ = new double [numberOfVariable_stepSize];
	for(int i=0;i<numberOfVariable_stepSize;i++)
		stepSize_[i] = 0.1/pow(10,i);
}

//////////////////////////////////   destructor  ///////////////////////////////////////////////////

SteepestDescentMethod_variableStepSize::~SteepestDescentMethod_variableStepSize ()
{
   delete[] X;
   delete[] gradient;
   
   delete[] X_;
   delete[] stepSize_;
}

//////////////////////////////// public functions /////////////////////////////////////

void SteepestDescentMethod_variableStepSize::readInputData(const char *path)
{
	baseSolver::readInputData(path);
	
	ifstream file(path);

	string searchForNumberOfVariableStepSize = "numberOfVariable_stepSize";
	
	string lineOfText;

	for(;;)
	{	
		getline(file, lineOfText);
			  
		if (file.eof()) break;
		
		if (lineOfText.find(searchForNumberOfVariableStepSize, 0) != string::npos)
		  file >> numberOfVariable_stepSize;	  	  
    }
    
    file.close();  
	
}

////////////////////////////////////////////////////////////////////////////////////////////////

void SteepestDescentMethod_variableStepSize::printInputData()
{
	baseSolver::printInputData();
	cout << "number of variable step size: " << numberOfVariable_stepSize << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

double SteepestDescentMethod_variableStepSize::calcStepSize()
{
	int i;
	double *f, minimum_;
	f = new double [numberOfVariable_stepSize];
	
	for (i=0;i<numberOfVariable_stepSize;i++)
        {
			X_[0]= X[0] - stepSize_[i]*gradient[0];
			X_[1]= X[1] - stepSize_[i]*gradient[1];
			
			f[i] = main_function();       
		}
		
		minimum_ = f[0];
		best_step_size = stepSize_[0];
		for (i=1;i<numberOfVariable_stepSize;i++)
			if(f[i]<minimum_)
			{
				minimum_ = f[i];
				best_step_size = stepSize_[i];			
			}
			
	delete[] f;
			
    return best_step_size;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

double SteepestDescentMethod_variableStepSize::main_function()
{
    return  pow((a - X_[0]),2) + b*pow((X_[1] - X_[0]*X_[0]),2);
}
