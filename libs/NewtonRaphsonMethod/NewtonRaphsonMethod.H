
////////////////  derived class /////////////////

class NewtonRaphsonMethod : public baseSolver {
	
	private:
	
	/////////// member ////////////////
	
	double **Hessian;
	
	/////////// functions ////////////////
	
	void Hessian_F();

    void invers_Hessian();

	       
   public:
   
	  NewtonRaphsonMethod (const char *path);
	  
	  ~NewtonRaphsonMethod ();
	  
      double* solveAndWriteXinEachIteration() ;

};

#include "NewtonRaphsonMethod.C"

