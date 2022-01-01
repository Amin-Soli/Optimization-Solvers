
////////////////  derived class /////////////////

class SteepestDescentMethod_constantStepSize : public SteepestDescentMethod {
	
	private:
	
	double stepSize_;

	       
   public:
   
	  SteepestDescentMethod_constantStepSize (const char *path);
	  
	  ~SteepestDescentMethod_constantStepSize();
	  
      void readInputData(const char *path);
      
      void printInputData();
      
      double calcStepSize();

};

#include "SteepestDescentMethod_constantStepSize.C"
