#include "MathLibrary.h"
#include <QVector>

/**
 * @brief MathLibrary::MathLibrary
 * @param cVals x values as input from main function
 * @param uVals y values as input from main function
 */
MathLibrary::MathLibrary(QVector<double> cVals, QVector<double> uVals){
    C=cVals;
    U=uVals;
}

/**
 * @brief MathLibrary::SolveEquations
 */
void MathLibrary::SolveEquations(){
    solveLinearMeanVals();
    solveNonLinearVals();
}

/**
 * @brief MathLibrary::solveLinearMeanVals
 */
void MathLibrary::solveLinearMeanVals(){
    cSize = C.size();
    count=0;sumA=0; sumB=0; sumC=0; sumU=0;
    for(int i=0; i<cSize;i++){
        sumC+=C[i];
        sumU+=U[i];
        for(int j=i+1;j<cSize ;j++){
            double a = abs(U[j]-U[i])/abs(C[j]-C[i]);
            aSet.push_back(a);
            double b = abs(U[j]-a*C[j]);
            bSet.push_back(b);
            sumA += a;
            sumB += b;
            count+=1;
        }
    }
    //b = u - (a * c)
    bLinMean = (sumU/cSize)-(sumA/count)*(sumC/cSize);
    aLinMean = sumA/count;
}

/**
 * @brief MathLibrary::solveNonLinearVals
 */
void MathLibrary::solveNonLinearVals(){
    cSize = C.size();
    count=0;sumA=0; sumB=0; sumC=0; sumU=0; sumConst=0;
        for(int i=0; i<cSize; i++){
            sumC+=C[i];
            sumU+=U[i];
            double ciSqr = C[i]*C[i];

            for(int j=i+1;j<cSize;j++){
                double cjSqr =C[j]*C[j];

                for(int k=j+1;k<cSize;k++){
                    double ckSqr = C[k]*C[k];

                    QVector<double> r1;
                    r1.push_back(ciSqr);
                    r1.push_back(C[i]);
                    r1.push_back(1);
                    r1.push_back(U[i]);

                    QVector<double> r2;
                    r2.push_back(cjSqr);
                    r2.push_back(C[j]);
                    r2.push_back(1);
                    r2.push_back(U[j]);

                    QVector<double> r3;
                    r3.push_back(ckSqr);
                    r3.push_back(C[k]);
                    r3.push_back(1);
                    r3.push_back(U[k]);

                    QVector<QVector<double>> equationMatrix;
                    equationMatrix.push_back(r1);
                    equationMatrix.push_back(r2);
                    equationMatrix.push_back(r3);

                    QVector<QVector<double>> solvedMatrix = solveMatrix(equationMatrix);

                    double cNONVal = solvedMatrix[2][3]/solvedMatrix[2][2];
                    double bNONVal = (solvedMatrix[1][3] - (cNONVal * solvedMatrix[1][2])) / solvedMatrix[1][1];
                    double aNONVal = (solvedMatrix[0][3] - (cNONVal * solvedMatrix[0][2]) - (bNONVal * solvedMatrix[0][1])) / solvedMatrix[0][0];
                    sumA += aNONVal;
                    sumB += bNONVal;
                    sumConst += cNONVal;
                    aNonSet.push_back(aNONVal);
                    bNonSet.push_back(bNONVal);
                    constSet.push_back(cNONVal);
                    count +=1;
                }
            }
        }
        aNonMean = sumA/count;
        bNonMean = sumB/count;
        constNonMean = sumConst/count;
}

/**
 * @brief MathLibrary::solveMatrix
 * @param mat
 * @return
 */
QVector<QVector<double>> MathLibrary::solveMatrix(QVector<QVector<double> > mat){

    QVector<double> r11;
    r11.push_back(mat[0][0]);
    r11.push_back(mat[0][1]);
    r11.push_back(mat[0][2]);
    r11.push_back(mat[0][3]);

    QVector<double> r22;
    r22.push_back(0);
    r22.push_back((mat[1][1]/mat[1][0])-(mat[0][1]/mat[0][0]));
    r22.push_back((mat[1][2]/mat[1][0])-(mat[0][2]/mat[0][0]));
    r22.push_back((mat[1][3]/mat[1][0])-(mat[0][3]/mat[0][0]));

    QVector<double> r33;
    r33.push_back(0);
    r33.push_back(0);
    r33.push_back((mat[2][2]/mat[2][0])-(mat[0][2]/mat[0][0]));
    r33.push_back((mat[2][3]/mat[2][0])-(mat[0][3]/mat[0][0]));

    QVector<QVector<double> > returnMatrix;
    returnMatrix.push_back(r11);
    returnMatrix.push_back(r22);
    returnMatrix.push_back(r33);

    return returnMatrix;
}

/**
 * @brief MathLibrary::getALinMean
 * @return
 */
double MathLibrary::getALinMean(){
    return aLinMean;
}

/**
 * @brief MathLibrary::getBLinMean
 * @return
 */
double MathLibrary::getBLinMean(){
    return bLinMean;
}

/**
 * @brief MathLibrary::getANonLinMean
 * @return
 */
double MathLibrary::getANonLinMean(){
    return aNonMean;
}

/**
 * @brief MathLibrary::getBNonLinMean
 * @return
 */
double MathLibrary::getBNonLinMean(){
    return bNonMean;
}

/**
 * @brief MathLibrary::getConstNonLinMean
 * @return
 */
double MathLibrary::getConstNonLinMean(){
    return constNonMean;
}

/**
 * @brief MathLibrary::getLinearVariables
 * @return
 */
QVector<double> MathLibrary::getLinearVariables(){
    QVector<double> returnVector;
         returnVector.append(this->getALinMean());
         returnVector.append(this->getBLinMean());

         return(returnVector);
}

/**
 * @brief MathLibrary::getNonLinearVariables
 * @return
 */
QVector<double> MathLibrary::getNonLinearVariables(){
    QVector<double> returnVector;
    returnVector.append(this->getANonLinMean());
    returnVector.append(this->getBNonLinMean());
    returnVector.append(this->getConstNonLinMean());

    return(returnVector);
}
