
//////////////////////////////// public functions /////////////////////////////////////

double* SteepestDescentMethod::solveAndWriteXinEachIteration()
{
	int count=0;
	double error;

    ofstream file;
    file.open("trendOf_X.txt");

    file<< "iteration" << '\t' <<'\t' << "x1" <<'\t'<<'\t' <<'\t'<< "x2" << endl << endl;

    do
    {
		count++;

        gradient_F();

        error=norm();

        gradient_unit();

        step_size = calcStepSize();

        X[0]=X[0] - step_size*gradient[0];
        X[1]=X[1] - step_size*gradient[1];

        file << count  << '\t' << '\t' <<'\t' << std::fixed << std::setprecision(6) << X[0] <<'\t'<<'\t'<< X[1] << endl;

    }while (error > max_Error);

    file.close();

    cout<<endl<<"number of iteration to find X vector = "<< count << endl << endl;

	return X;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

double SteepestDescentMethod::calcStepSize()
{
    return 0.0;
}
