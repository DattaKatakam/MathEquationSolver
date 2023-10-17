#include "errorCheck.h"
#include <QVector>

/**
 * @brief errorCheck::errorCheck
 * @param absVals, contain absilute values for the sample input
 * @param achVals acieved values are obtained by math operations
 */
errorCheck::errorCheck(QVector<double> absVals, QVector<double> achVals){
    absoluteValues=absVals;
    achievedValues=achVals;
}

/**
 * @brief errorCheck::solveAbsoluteError
 */
void errorCheck::solveAbsoluteError(){
    if(absoluteValues.size()==achievedValues.size()){
        if(absoluteValues.size()==3){
            double errorA = absoluteValues.at(0)-achievedValues.at(0);
            double errorB = absoluteValues.at(1)-achievedValues.at(1);
            double errorConst = absoluteValues.at(2)-achievedValues.at(2);
            absoluteErrorPercentage.push_back(errorA);
            absoluteErrorPercentage.push_back(errorB);
            absoluteErrorPercentage.push_back(errorConst);
        }
        else if(absoluteValues.size()==2){
            double errorA = (absoluteValues.at(0)-achievedValues.at(0))/absoluteValues.at(0);
            double errorB = (absoluteValues.at(1)-achievedValues.at(1))/absoluteValues.at(1);
            absoluteErrorPercentage.push_back(errorA);
            absoluteErrorPercentage.push_back(errorB);
        }
    }
}

/**
 * @brief errorCheck::solveRelativeError
 */
void errorCheck::solveRelativeError(){
    if(absoluteValues.size()==achievedValues.size()){
        if(absoluteValues.size()==3){
            double errorA = abs(abs(absoluteValues.at(0)-achievedValues.at(0))/absoluteValues.at(0))*100;
            double errorB = abs(abs(absoluteValues.at(1)-achievedValues.at(1))/absoluteValues.at(1))*100;
            double errorConst = abs(abs(absoluteValues.at(2)-achievedValues.at(2))/absoluteValues.at(2))*100;
            relativeErrorPercantage.push_back(errorA);
            relativeErrorPercantage.push_back(errorB);
            relativeErrorPercantage.push_back(errorConst);
        }
        else if(absoluteValues.size()==2){
            double errorA = (abs(absoluteValues.at(0)-achievedValues.at(0))/absoluteValues.at(0))*100;
            double errorB = (abs(absoluteValues.at(1)-achievedValues.at(1))/absoluteValues.at(1))*100;
            relativeErrorPercantage.push_back(errorA);
            relativeErrorPercantage.push_back(errorB);
        }
    }
}

/**
 * @brief errorCheck::getAbsoluteErrorVals
 * @return
 */
QVector<double> errorCheck::getAbsoluteErrorVals(){
    return absoluteErrorPercentage;
}

/**
 * @brief errorCheck::getRelativeErrorVals
 * @return
 */
QVector<double> errorCheck::getRelativeErrorVals(){
    return relativeErrorPercantage;
}
