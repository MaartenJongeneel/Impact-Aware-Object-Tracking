#include <iostream> //cout, anyway useful
#include <vector> //vectors

typedef std::vector<double> vec;
typedef std::vector<vec> matrix;


class BoxSim{
public:

    void run(); //runs a log
    double proxCN(double x);
    double BoxSimulator(double relLinVel[6]); 
    void hat(double iets[], int size);
    void print(matrix const& M);
};