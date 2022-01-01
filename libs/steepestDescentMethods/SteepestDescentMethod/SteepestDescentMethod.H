
////////////////  derived class /////////////////

class SteepestDescentMethod : public baseSolver {
	
	private:
	
	double step_size;

	       
   public:
	  
      double* solveAndWriteXinEachIteration() ;
      
      virtual double calcStepSize();

};

#include "SteepestDescentMethod.C"
#include "../SteepestDescentMethod_constantStepSize/SteepestDescentMethod_constantStepSize.H"
#include "../SteepestDescentMethod_variableStepSize/SteepestDescentMethod_variableStepSize.H"
#include "../SteepestDescentMethod_quadraticFi/SteepestDescentMethod_quadraticFi.H"

