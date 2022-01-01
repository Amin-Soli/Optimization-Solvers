
////////////////  derived class /////////////////

class SteepestDescentMethod_quadraticFi : public SteepestDescentMethod {
	
	private:
	
	double best_step_size ;
	double *stepSize_, *X_, *f;

	       
   public:
   
	  SteepestDescentMethod_quadraticFi (const char *path);
	  
	  ~SteepestDescentMethod_quadraticFi ();
	  
	  double main_function();
      
      double calcStepSize();
      
      double calulate_minimum_of_guadratic_function();
      
      void linearEquations_solver(double *x, double **A, double *B);

};

#include "SteepestDescentMethod_quadraticFi.C"
