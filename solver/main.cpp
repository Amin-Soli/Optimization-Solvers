#include <iostream>
#include <iomanip>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <string>

using namespace std;

#include "../libs/baseSolver/baseSolver.H"

int main() {

  const char *path="../inputData/inputData.txt";

  double *X;

  baseSolver *myObject;

  myObject = myObject -> baseSolver::New(path);

  X = myObject -> solveAndWriteXinEachIteration();

  cout << "minimum of function: "<< endl;
  cout <<"x1 =" << X[0] << endl;
  cout <<"x2 =" << X[1] << endl << endl;

  cout << "end of the program." << endl;

}
