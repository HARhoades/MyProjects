#include <iostream>
#include <cmath>
#include <string.h>
#include "Vec3d.h"

using namespace std;

Vec3d cross(Vec3d a, Vec3d b) {
    Vec3d c = Vec3d();
    c.x = (a.y*b.z) - (a.z*b.y);
    c.y = (a.z*b.x) - (a.x*b.z);
    c.z = (a.x*b.y) - (a.y*b.x);
    cout << "<" << c.x << ", " << c.y << ", " << c.z << ">";
    return c;
}

double dot(Vec3d a, Vec3d b) {
    double sum = (a.x*b.x) + (a.y*b.y) + (a.z*b.z);
    cout << "Dot Product = " << sum;
    return sum;
}

Vec3d unitVec(Vec3d a) {
    Vec3d u = Vec3d();
    double mag = sqrt((a.x*a.x) + (a.y*a.y) + (a.z*a.z));
    u.x = a.x / mag;
    u.y = a.y / mag;
    u.z = a.z / mag;
    cout << "<" << u.x << ", " << u.y << ", " << u.z << ">";
    return u;
}

Vec3d writeVec3d(){
    Vec3d v = Vec3d();
    cout << endl << "x: ";
    double num;
    cin >> num;
    v.x = num;
    cout << "y: ";
    cin >> num;
    v.y = num;
    cout << "z: ";
    cin >> num;
    v.z = num;
    return v;
}



int main()
{
    while(1){
        cout << endl << "Input first Vec3d: ";
        Vec3d a = writeVec3d();
        cout << "Input second Vec3d: ";
        Vec3d b = writeVec3d();

        cout << "Functions Available..." << endl;
        cout << "cross - Cross Product" << endl;
        cout << "dot - Dot Product" << endl;
        cout << "unit - Unit Vector of a" << endl;
        cout << "Input desired function: ";
        string func;

        bool validInput = false;
        while (validInput == false) {
            validInput = true;
            getline(cin, func);
            const char * funcToCharArr = func.c_str();
            if(strcmp(funcToCharArr, "cross") == 0) {
                cross(a, b);
            } else if(strcmp(funcToCharArr, "dot") == 0) {
                dot(a, b);
            } else if(strcmp(funcToCharArr, "unit") == 0) {
                unitVec(a);
            }
            else {
                cout << "Invalid input" << endl;
                validInput = false;
            }
        }
    }
    return 0;
}
