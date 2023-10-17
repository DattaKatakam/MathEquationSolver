#include "MathLibSub.h"
#include <QVector>

/**
 * @brief MathLibSub::MathLibSub
 * @param cVals x values as input from main function
 * @param uVals y values as input from main function
 */
MathLibSub::MathLibSub(QVector<double> cVals, QVector<double> uVals){
    mC=cVals;
    mU=uVals;
}

/**
 * @brief MathLibSub::solveEquations
 */
void MathLibSub::solveEquations(){
    solveLinearMeanVals();
    solveNonLinearVals();
}

/**
 * @brief MathLibSub::solveLinearMeanVals
 */
void MathLibSub::solveLinearMeanVals(){
    mCSize = mC.size();
    mCount=0;mSumA=0; mSumB=0; mSumC=0; mSumU=0;
    for(int i=0; i<mCSize;i++){
        mSumC+=mC[i];
        mSumU+=mU[i];
        for(int j=i+1;j<mCSize ;j++){
            double a = abs(mU[j]-mU[i])/abs(mC[j]-mC[i]);
            mASet.push_back(a);
            double b = abs(mU[j]-a*mC[j]);
            mBSet.push_back(b);
            mSumA += a;
            mSumB += b;
            mCount+=1;
        }
    }
    //b = u - (a * c)
    mBLinMean = (mSumU/mCSize)-(mSumA/mCount)*(mSumC/mCSize);
    mALinMean = mSumA/mCount;
}

/**
 * @brief MathLibSub::solveNonLinearVals
 */
void MathLibSub::solveNonLinearVals(){
    mCSize = mC.size();
    mCount=0;mSumA=0; mSumB=0; mSumC=0; mSumU=0; mSumConst=0;
    for(int i=0; i<mCSize; i++){
        mSumC+=mC[i];
        mSumU+=mU[i];
        for(int j=i+1;j<mCSize;j++){

            double xDiff12 = mC[i]-mC[j] ;
            double xSum12 = mC[i]+mC[j];
            double yDiff12 = mU[i]-mU[j];

            for(int k=j+1;k<mCSize;k++){
                double xDiff23 = mC[j]-mC[k];
                double yDiff23 = mU[j]-mU[k];
                double xDiff13 = mC[i]-mC[k];
                double x3=mC[k];
                double y3=mU[k];
                double instA = ((yDiff12/xDiff12)-(yDiff23/xDiff23))/(xDiff13);
                double instB = (yDiff12/xDiff12)-(instA*xSum12);
                double instConst = y3-(instA*x3*x3)-(instB*x3);
                mSumA += instA;
                mSumB += instB;
                mSumConst += instConst;
                mANonSet.push_back(instA);
                mBNonSet.push_back(instB);
                mConstSet.push_back(instConst);

                mCount+=1;
            }
        }
    }
    mANonMean = mSumA/mCount;
    mBNonMean = mSumB/mCount;
    mConstNonMean = mSumConst/mCount;
}

/**
 * @brief MathLibSub::getALinMean
 * @return
 */
double MathLibSub::getALinMean(){
    return mALinMean;
}

/**
 * @brief MathLibSub::getBLinMean
 * @return
 */
double MathLibSub::getBLinMean(){
    return mBLinMean;
}

/**
 * @brief MathLibSub::getANonLinMean
 * @return
 */
double MathLibSub::getANonLinMean(){
    return mANonMean;
}

/**
 * @brief MathLibSub::getBNonLinMean
 * @return
 */
double MathLibSub::getBNonLinMean(){
    return mBNonMean;
}

/**
 * @brief MathLibSub::getConstNonLinMean
 * @return
 */
double MathLibSub::getConstNonLinMean(){
    return mConstNonMean;
}

/**
 * @brief MathLibSub::getLinearVariables
 * @return
 */
QVector<double> MathLibSub::getLinearVariables(){
    QVector<double> returnVector;
         returnVector.append(this->getALinMean());
         returnVector.append(this->getBLinMean());

         return(returnVector);
}

/**
 * @brief MathLibSub::getNonLinearVariables
 * @return
 */
QVector<double> MathLibSub::getNonLinearVariables(){
    QVector<double> returnVector;
    returnVector.append(this->getANonLinMean());
    returnVector.append(this->getBNonLinMean());
    returnVector.append(this->getConstNonLinMean());

    return(returnVector);
}
