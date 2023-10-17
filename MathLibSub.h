#include <QVector>
#ifndef MATHLIBSUB_H
#define MATHLIBSUB_H
/**
 * @brief The MathLibSub class for deducing values of linear and non linear values using substitution method
 */
class MathLibSub{
    /**
     * @brief mC contains x values
     */
    QVector<double> mC;
    /**
     * @brief mU contains y values
     */
    QVector<double> mU;
    /**
     * @brief mASet, mBSet, mConstSet,mANonSet,mBNonSet, mDetSet,mDetSetA,mDetSetB,mDetSetConst varaibles to perform operations
     */
    QVector<double> mASet, mBSet,mConstSet,mANonSet,mBNonSet, mDetSet,mDetSetA,mDetSetB,mDetSetConst;
    /**
     * @brief mCount to check the iterations
     */
    int mCount=0;
    /**
     * @brief mSumA, mSumB, mSumC,mSumU,mSumConst to store values during operations
     */
    double mSumA=0, mSumB=0, mSumC=0,mSumU=0,mSumConst=0;
    /**
     * @brief mANonMean, mBNonMean, mConstNonMean, mALinMean,mBLinMean used to store a, b , c values from linear and non linear equations
     */
    double mANonMean, mBNonMean, mConstNonMean, mALinMean,mBLinMean;
    /**
     * @brief mCSize stores the length of x values in C variable
     */
    int mCSize;
    public:
    /**
     * @brief MathLibSub constructor
     * @param cVals store value in mC
     * @param uVals store value in mU
     */
    MathLibSub(QVector<double> cVals, QVector<double> uVals);
    /**
     * @brief solveEquations initiates methods solveLinearMeanVals() and solveNonLinearVals()
     */
    void solveEquations();
    /**
     * @brief solveLinearMeanVals solve linear a,b values
     */
    void solveLinearMeanVals();
    /**
     * @brief solveNonLinearVals solve non linear a,b,c values
     */
    void solveNonLinearVals();
    /**
     * @brief getALinMean to return linearValue of A
     * @return mALinMean
     */
    double getALinMean();
    /**
     * @brief getBLinMean to return linearValue of B
     * @return mBLinMean
     */
    double getBLinMean();
    /**
     * @brief getANonLinMean to return Non linearValue of B
     * @return mANonMean
     */
    double getANonLinMean();
    /**
     * @brief getBNonLinMean to return Non linearValue of B
     * @return mBNonMean
     */
    double getBNonLinMean();
    /**
     * @brief getConstNonLinMean to return Non linearValue of constant c
     * @return mConstNonMean
     */
    double getConstNonLinMean();
    QVector<double> getDetSet();
    QVector<double> getDetSetA();
    QVector<double> getDetSetB();
    QVector<double> getDetSetConst();
    /**
     * @brief getLinearVariables to return vector of linear mean values
     * @return  linear values a, b
     */
    QVector<double> getLinearVariables();
    /**
     * @brief getNonLinearVariables to return vector of non linear values
     * @return  non linear values a, b, c
     */
    QVector<double> getNonLinearVariables();
};

#endif // MATHLIBSUB_H
