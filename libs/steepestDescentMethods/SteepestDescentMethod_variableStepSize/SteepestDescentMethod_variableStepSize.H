
////////////////  derived class /////////////////

class SteepestDescentMethod_variableStepSize : public SteepestDescentMethod {
	
	private:
	
	int numberOfVariable_stepSize;
	double best_step_size ;
	double *stepSize_, *X_;

	       
   public:
   
	  SteepestDescentMethod_variableStepSize (const char *path);
	  
	  ~SteepestDescentMethod_variableStepSize ();
	  
	  double main_function();
	  
      void readInputData(const char *path);
      
      void printInputData();
      
      double calcStepSize();

};

#include "SteepestDescentMethod_variableStepSize.C"
