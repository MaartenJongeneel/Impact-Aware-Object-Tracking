#include "BoxSim.hpp"


typedef std::vector<double> vec;
typedef std::vector<vec> matrix;



int main()
{
    BoxSim run;
    run.run();
    return 0;
}

void BoxSim::run(){
    double x[] = {1,2,3,4,5,6};
    int size = sizeof(x)/sizeof(x[0]);
    std::cout << "Length of array = " << size << std::endl;
    // std::cin >> x[3];
    hat(x,size);
    BoxSimulator(x,5);
}






// -------------------------------- Functions Below ----------------------------- //
double BoxSim::BoxSimulator(double BV_AB[6], int endframe){

//User settings
double g = 9.81;                     //Gravitational acceleration     [m/s^2]
double a = 0.01;                     //Error tol for fixed-point      [-]
double tol = 1e-7;                   //Error tol for fixed-point      [-]
std::vector<double> PNfull(8, 0.0);  //Initial guess for momenta PN   [N*s]
std::vector<double> PTfull(16, 0.0); //Initial guess for momenta PN   [N*s]
bool run = true;                     //Boolean to run and stop sim    [-] 



int ii;
if(ii==endframe){
    run = false;
}

//temp:
return 0;

}



//Proximal Point Normal Direction
double BoxSim::proxCN(double x){
    double y;
    if(x>0){
        y = x;
    }
    else if(x<=0){
        y = 0;
    }
    return y;
}


//Hat operator
void BoxSim::hat(double iets[], int size){
    if(size ==3){
        matrix res(3, vec(3));
        res[0][0] = 0;        res[0][1] = -iets[2];  res[0][2] = iets[1];  
        res[1][0] = iets[2];  res[1][1] = 0;         res[1][2] = -iets[0];  
        res[2][0] = -iets[1]; res[2][1] = iets[0];   res[2][2] = 0;
        print(res);
    }
    else if(size==6){
        matrix res(4, vec(4));
        res[0][0] = 0;         res[0][1] = -iets[5];  res[0][2] = iets[4];   res[0][3] = iets[0];
        res[1][0] = iets[5];   res[1][1] = 0;         res[1][2] = -iets[3];  res[1][3] = iets[1];
        res[2][0] = -iets[4];  res[2][1] = iets[3];   res[2][2] = 0;         res[2][3] = iets[2];
        res[3][0] = 0;         res[3][1] = 0;         res[3][2] = 0;         res[3][3] = 0;
        print(res);
    };
    
}

// Print matrix to the screen
void BoxSim::print(matrix const& M) {
    size_t n = M.size();
    for(size_t i = 0; i < n; ++i) {
        for(size_t j = 0; j < n; ++j)
            std::cout << M[i][j] << ' ';
        std::cout << '\n';
    }
}

// Print vector to the screen
void BoxSim::printv(vec const& v) {
    size_t n = v.size();
    for(size_t i = 0; i < n; ++i) {
            std::cout << v[i] << ' ';
        std::cout << '\n';
    }
}