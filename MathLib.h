#include <QVector>

#ifndef MATHLIB_H
#define MATHLIB_H
/**
 * @brief The MathLib class for deducing the a,b,c values using Cramer's rule
 */
class MathLib{
    /**
     * @brief C contains x values
     */
    QVector<double> C;
    /**
     * @brief U contains y values
     */
    QVector<double> U;
    /**
     * @brief aSet, bSet, constSet,aNonSet,bNonSet, detSet,detSetA,detSetB,detSetConst varaibles to perform operations
     */
    QVector<double> aSet, bSet,constSet,aNonSet,bNonSet, detSet,detSetA,detSetB,detSetConst;
    /**
     * @brief count to check the iterations
     */
    int count=0;
    /**
     * @brief sumA, sumB, sumC,sumU,sumConst to store values during operations
     */
    double sumA=0, sumB=0, sumC=0,sumU=0,sumConst=0;
    /**
     * @brief aNonMean, bNonMean, constNonMean, aLinMean,bLinMean used to store a, b , c values from linear and non linear equations
     */
    double aNonMean, bNonMean, constNonMean, aLinMean,bLinMean;
    /**
     * @brief cSize stores the length of x values in C variable
     */
    int cSize;
    public:
    /**
     * @brief MathLib constructor
     * @param cVals store value in C
     * @param uVals store value in U
     */
    MathLib(QVector<double> cVals, QVector<double> uVals);
     /**
     * @brief SolveEquations initiates methods solveLinearMeanVals() and solveNonLinearVals()
     */
    void SolveEquations();
    /**
     * @brief solveLinearMeanVals solve linear a,b values
     */
    void solveLinearMeanVals();
    /**
     * @brief solveNonLinearVals solve non linear a,b,c values
     */
    void solveNonLinearVals();
    /**
     * @brief getDeterminant method to find determinant of matrix
     * @param equationMatrix takes this variable as input parameter and calculates determinant
     * @return determinant of equationMatrix
     */
    double getDeterminant(QVector<QVector<double>> equationMatrix);
    /**
     * @brief getDeterminant getDeterminant method to find determinant of matrix
     * @param equationMatrix takes this variable as input parameter and calculates determinant
     * @param i using index as row number
     * @return determinant of equationMatrix
     */
    double getDeterminant(QVector<QVector<double>> equationMatrix,int i);
    /**
     * @brief getALinMean to return linearValue of A
     * @return aLinMean
     */
    double getALinMean();
    /**
     * @brief getBLinMean  to return linearValue of B
     * @return bLinMean
     */
    double getBLinMean();
    /**
     * @brief getANonLinMean  to return Non linearValue of A
     * @return aNonMean
     */
    double getANonLinMean();
    /**
     * @brief getBNonLinMean to return Non linearValue of B
     * @return bNonMean
     */
    double getBNonLinMean();
    /**
     * @brief getConstNonLinMean to return Non linearValue of constant c
     * @return constNonMean
     */
    double getConstNonLinMean();

    QVector<double> getDetSet();
    QVector<double> getDetSetA();
    QVector<double> getDetSetB();
    QVector<double> getDetSetConst();
    /**
     * @brief getLinearVariables to return vector of linear mean values
     * @return linear values a, b
     */
    QVector<double> getLinearVariables();
    /**
     * @brief getNonLinearVariables to return vector of non linear values
     * @return non linear values a, b, c
     */
    QVector<double> getNonLinearVariables();
};

#endif // MATHLIB_H
