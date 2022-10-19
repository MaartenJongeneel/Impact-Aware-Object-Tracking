#include "BoxSim.hpp"


using namespace std;

typedef vector<double> vec;
typedef vector<vec> matrix;



int main()
{
    BoxSim run;
    run.run();
    return 0;
}

void BoxSim::run(){
    double x[] = {1,2,3,4,5,6};
    std::cout << "Length of array = " << sizeof(x)/sizeof(x[0]) << std::endl;
    // std::cin >> x[3];
    hat(x,sizeof(x)/sizeof(x[0]));
    // double y = proxCN(x);
    // std::cout<<"The max returns: "<< y << "\n";
}


double BoxSim::BoxSimulator(double BV_AB[6]){

//User settings
double g = 9.81;    //Gravitational acceleration              [m/s^2]
double a = 0.01;    //Error tol for fixed-point               [-]
double tol = 1e-7;  //Error tol for fixed-point               [-]


//temp:
return 0;

}




// -------------------------------- Functions Below -----------------------------
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
    std::cout << "Length of array = " << size << std::endl;

    if(size ==3){
        matrix res(3, vec(3));
        res[0][0] = 0;
        res[0][1] = -iets[2];
        res[0][2] = iets[1];
        res[1][0] = iets[2];
        res[1][1] = 0;
        res[1][2] = -iets[0];
        res[2][0] = -iets[1];
        res[2][1] = iets[0];
        res[2][2] = 0;
        print(res);
    }
    else if(size==6){
        matrix res(4, vec(4));
        res[0][0] = 0;
        res[0][1] = -iets[5];
        res[0][2] = iets[4];
        res[1][0] = iets[5];
        res[1][1] = 0;
        res[1][2] = -iets[3];
        res[2][0] = -iets[4];
        res[2][1] = iets[3];
        res[2][2] = 0;
        res[0][3] = iets[0];
        res[1][3] = iets[1];
        res[2][3] = iets[2];
        res[3][0] = 0;
        res[3][1] = 0;
        res[3][2] = 0;
        res[3][3] = 0;
        print(res);
    };
    
}


void BoxSim::print(matrix const& M) {
    size_t n = M.size();
    for(size_t i = 0; i < n; ++i) {
        for(size_t j = 0; j < n; ++j)
            cout << M[i][j] << ' ';
        cout << '\n';
    }
}


// function res = hat(vec)
// % Take the 3- or 6-vector representing an isomorphism of so(3) or se(3) and writes this as element of so(3) or se(3). 
// if length(vec) == 3
//     res = [0, -vec(3), vec(2); vec(3), 0, -vec(1); -vec(2), vec(1), 0];
// elseif length(vec) == 6
//     skew = [0, -vec(6), vec(5); vec(6), 0, -vec(4); -vec(5), vec(4), 0];
//     v = [vec(1);vec(2);vec(3)];
//     res = [skew, v; zeros(1,4)];
// end
// end