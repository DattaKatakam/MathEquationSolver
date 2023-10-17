#include "MathLib.h"
#include <QVector>

/**
 * @brief MathLib::MathLib
 * @param cVals x values as input from main function
 * @param uVals y values as input from main function
 */
MathLib::MathLib(QVector<double> cVals, QVector<double> uVals){
    C=cVals;
    U=uVals;
}

/**
 * @brief MathLib::SolveEquations
 */
void MathLib::SolveEquations(){
    solveLinearMeanVals();
    solveNonLinearVals();
}

/**
 * @brief MathLib::solveLinearMeanVals
 */
void MathLib::solveLinearMeanVals(){
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
 * @brief MathLib::solveNonLinearVals
 */
void MathLib::solveNonLinearVals(){
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

                double denoDet = getDeterminant(equationMatrix,-1);
                detSet.push_back(denoDet);
                double aNumDet = getDeterminant(equationMatrix,0);
                detSetA.push_back(aNumDet);
                double bNumDet = getDeterminant(equationMatrix,1);
                detSetB.push_back(bNumDet);
                double constNumDet = getDeterminant(equationMatrix,2);
                detSetConst.push_back(constNumDet);
                sumA += aNumDet/denoDet;
                sumB += bNumDet/denoDet;
                sumConst += constNumDet/denoDet;
                aNonSet.push_back(aNumDet/denoDet);
                bNonSet.push_back(bNumDet/denoDet);
                constSet.push_back(constNumDet/denoDet);

                count+=1;
            }
        }
    }
    aNonMean = sumA/count;
    bNonMean = sumB/count;
    constNonMean = sumConst/count;
}

/**
 * @brief MathLib::getDetSet
 * @return
 */
QVector<double> MathLib::getDetSet(){
    return detSet;
}

/**
 * @brief MathLib::getDetSetA
 * @return
 */
QVector<double> MathLib::getDetSetA(){
    return detSetA;
}

/**
 * @brief MathLib::getDetSetB
 * @return
 */
QVector<double> MathLib::getDetSetB(){
    return detSetB;
}

/**
 * @brief MathLib::getDetSetConst
 * @return
 */
QVector<double> MathLib::getDetSetConst(){
    return detSetConst;
}
double MathLib::getDeterminant(QVector<QVector<double>> eMatrix){
    double det=0;

    det = (eMatrix[0][0] * ((eMatrix[1][1]*eMatrix[2][2]) - (eMatrix[1][2]*eMatrix[2][1])) )
            - (eMatrix[0][1] * ((eMatrix[1][0]*eMatrix[2][2])-(eMatrix[2][0]*eMatrix[1][2])) )
            + (eMatrix[0][2] * ((eMatrix[1][0]*eMatrix[1][2]) - (eMatrix[2][0]*eMatrix[1][1])) );

    return det;
}

/**
 * @brief MathLib::getDeterminant
 * @param equationMat
 * @param i
 * @return
 */
double MathLib::getDeterminant(QVector<QVector<double>> equationMat, int i){

    double det;

    QVector<double> r1;
    r1.push_back(equationMat[0][0]);
    r1.push_back(equationMat[0][1]);
    r1.push_back(equationMat[0][2]);

    QVector<double> r2;
    r2.push_back(equationMat[1][0]);
    r2.push_back(equationMat[1][1]);
    r2.push_back(equationMat[1][2]);

    QVector<double> r3;
    r3.push_back(equationMat[2][0]);
    r3.push_back(equationMat[2][1]);
    r3.push_back(equationMat[2][2]);

    QVector<QVector<double>> eMat;
    eMat.push_back(r1);
    eMat.push_back(r2);
    eMat.push_back(r3);

    if(i>=0 && i<=2){
        for(int j=0;j<3;j++){
            eMat[j][i]=equationMat[j][3];
        }
        det = getDeterminant(eMat);
        return det;
    }

    else{

        det = getDeterminant(eMat);
        return det;
    }


}

double MathLib::getALinMean(){
    return aLinMean;
}

double MathLib::getBLinMean(){
    return bLinMean;
}

double MathLib::getANonLinMean(){
    return aNonMean;
}

double MathLib::getBNonLinMean(){
    return bNonMean;
}

double MathLib::getConstNonLinMean(){
    return constNonMean;
}

QVector<double> MathLib::getLinearVariables(){
    QVector<double> returnVector;
         returnVector.append(this->getALinMean());
         returnVector.append(this->getBLinMean());

         return(returnVector);
}

QVector<double> MathLib::getNonLinearVariables(){
    QVector<double> returnVector;
    returnVector.append(this->getANonLinMean());
    returnVector.append(this->getBNonLinMean());
    returnVector.append(this->getConstNonLinMean());

    return(returnVector);
}
