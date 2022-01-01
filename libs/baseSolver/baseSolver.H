
////////////////  abstract class /////////////////

class baseSolver {
	
	protected:
	
	///////////// protected members //////////////////////
	
	double a, b, max_Error;
	
	double *X, *gradient;
    
    string solverType; 
    
	       
   public:
	  
      virtual double* solveAndWriteXinEachIteration() = 0; 
      
      virtual void readInputData(const char *path);
      
      virtual void printInputData();
	  
      static baseSolver* New(const char *path);
      
      void gradient_F();

	  double norm();
	  
	  void gradient_unit();
      
};

#include "../steepestDescentMethods/SteepestDescentMethod/SteepestDescentMethod.H"
#include "../NewtonRaphsonMethod/NewtonRaphsonMethod.H"
#include "baseSolver.C"
