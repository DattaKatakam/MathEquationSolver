#include <QVector>
#ifndef ERRORCHECK_H
#define ERRORCHECK_H

/**
 * @brief The errorCheck class for checking errors in achieved values
 */
class errorCheck{
private:
    /**
     * @brief absVals, contain absolute values for the sample input
     * @brief achVals acieved values are obtained by math operations
     */
    QVector<double> absoluteValues, achievedValues;
    /**
     * @brief absoluteErrorPercentage, contain absolute values for the sample input
     * @brief relativeErrorPercentage acieved values are obtained by math operations
     */
    QVector<double> absoluteErrorPercentage, relativeErrorPercantage;
public:
    errorCheck(QVector<double> absVals, QVector<double> achVals);
    /**
     * @brief solveAbsoluteError method to determine absolute error
     */
    void solveAbsoluteError();
    /**
     * @brief solveRelativeError method to determine relative error
     */
    void solveRelativeError();
    /**
     * @brief to obtain absolute error values
     */
    QVector<double> getAbsoluteErrorVals();
    /**
     * @brief to obtain realtive error values
     */
    QVector<double> getRelativeErrorVals();
};

#endif // ERRORCHECK_H
