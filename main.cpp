#include <QCoreApplication>
#include "MathLib.h"
#include "MathLibrary.h"
#include "MathLibSub.h"
#include "errorCheck.h"
#include <QVector>
#include <iostream>
#include <QString>
#include <cstdlib>
using namespace std;
/**
 * @brief main
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //QVector<double> C {52.6, 102.5, 153, 201, 254, 307, 358, 409};
    QVector<double> C {161.6,163.6,165.4,167.2,169,170.7,172.3,173.9,175.5,177,178.5,180};
    QVector<double> U {0,5,10,15,20,25,30,35,40,45,50,55};
    //QVector<double> U {247.5, 425, 606.3, 780, 981.3, 1125, 1356.3, 1541.3};
    QVector<double> absVals {0.024,-5.518,240.7};
    /*
    a=0.024
    b=-5.518
    c=240.7
    */
    // substitution method
    MathLibSub objFn(C,U);
    objFn.solveNonLinearVals();
    QVector<double> resultNonLinearVector = objFn.getNonLinearVariables();
    cout << "values of Non Linear equations";
    for(auto val : resultNonLinearVector){
        cout << val <<"\n";
    }
    // gauss elimination method
    MathLibrary objFn1(C,U);
    objFn1.solveNonLinearVals();
    QVector<double> nonLinearVectorResults = objFn1.getNonLinearVariables();
    cout << "values of Non Linear equations with MathLibrary.h";
    for(auto val: nonLinearVectorResults){
        cout << val<<"\n";
    }
    // cramer's rule
    MathLib objFn2(C,U);
    objFn2.solveNonLinearVals();
    QVector<double> resultsNonLinearVector = objFn2.getNonLinearVariables();
    cout << "values of NON linear equations with MathLib.h";
    for(auto val:resultsNonLinearVector){
        cout<<val<<"\n";
    }

    // substitution method
    errorCheck errorFn(absVals, resultNonLinearVector);
    errorFn.solveRelativeError();
    QVector<double> resultErrorRelative = errorFn.getRelativeErrorVals();
    for(auto val : resultErrorRelative){
        cout << val <<"\n";
    }
    // gauss elimination method
    errorCheck errorFn1(absVals, nonLinearVectorResults);
    errorFn1.solveRelativeError();
    QVector<double> resultErrorRelative1 = errorFn1.getRelativeErrorVals();
    for(auto val : resultErrorRelative1){
        cout << val <<"\n";
    }
    // cramer's rule
    errorCheck errorFn2(absVals, resultsNonLinearVector);
    errorFn2.solveRelativeError();
    QVector<double> resultErrorRelative2 = errorFn2.getRelativeErrorVals();
    for(auto val : resultErrorRelative2){
        cout << val <<"\n";
    }


    return a.exec();
}
