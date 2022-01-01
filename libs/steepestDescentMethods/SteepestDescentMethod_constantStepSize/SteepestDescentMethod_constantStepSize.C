
//////////////// constructor ///////////////////////

SteepestDescentMethod_constantStepSize::SteepestDescentMethod_constantStepSize (const char *path)
{
	X = new double [2];
    gradient = new double [2]; 
    
	readInputData(path);
	printInputData();
}

//////////////////////////////////   destructor  ///////////////////////////////////////////////////

SteepestDescentMethod_constantStepSize::~SteepestDescentMethod_constantStepSize ()
{

   delete[] X;
   delete[] gradient;
}

//////////////////////////////// public functions /////////////////////////////////////

void SteepestDescentMethod_constantStepSize::readInputData(const char *path)
{
	baseSolver::readInputData(path);
	
	ifstream file(path);

	string searchForConstantStepSize = "constant_stepSize";
	
	string lineOfText;

	for(;;)
	{	
		getline(file, lineOfText);
			  
		if (file.eof()) break;
		
		if (lineOfText.find(searchForConstantStepSize, 0) != string::npos)
		  file >> stepSize_;	  	  
    }
    
    file.close();  
	
}

////////////////////////////////////////////////////////////////////////////////////////////////

void SteepestDescentMethod_constantStepSize::printInputData()
{
	baseSolver::printInputData();
	cout << "constant step size: " << stepSize_ << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

double SteepestDescentMethod_constantStepSize::calcStepSize()
{
    return stepSize_;
}
