#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

const double PI = 3.141592653589793;

int main() {
    ifstream fin;
    fin.open("input.txt");

    double Xa, Ya, Xb, Yb, Xo, Yo, b;
    fin >> Xa >> Ya >> Xb >> Yb >> Xo >> Yo >> b;

    double rad = b * PI / 180.0;

    double Xa_new = (Xa - Xo) * cos(rad) - (Ya - Yo) * sin(rad) + Xo;
    double Ya_new = (Xa - Xo) * sin(rad) + (Ya - Yo) * cos(rad) + Yo;
    double Xb_new = (Xb - Xo) * cos(rad) - (Yb - Yo) * sin(rad) + Xo;
    double Yb_new = (Xb - Xo) * sin(rad) + (Yb - Yo) * cos(rad) + Yo;
    
    ofstream fout;
    fout.open("output.txt");

    fout << std::fixed << std::setprecision(3) << Xa_new << " " << Ya_new << " " << Xb_new << " " << Yb_new;

    return 0;
}
