/*
    AngleKalmanFilter.h - Library for angle estimating Kalman filter
    Created by Robin Baran, January 2021
*/

#ifndef ANGLE_KALMAN_FILTER_H
#define ANGLE_KALMAN_FILTER_H

#include <math.h>

//===========================================================================
//                         Angle Kalman filter class
//   ----------------------------------------------------------------------
// One-dimensional Kalman filter for angle estimation.
// Takes as input:
//  - absolute angle measurement (from absolute encoder, potentiometer,...)
//  - relative angle measurement (from encoder, gyroscope,...)
//
// [-180, 180) normalization for the angle
//===========================================================================
class AngleKalmanFilter
{
public:
    //-------------------------------------------------------------
    //    Construct an angle Kalman filter object with given
    // variances for absolute measurement and relative measurement
    //-------------------------------------------------------------
    AngleKalmanFilter(float absoluteMeasVariance, float relativeMeasVariance);
    //--------------------------------------------
    // Initialize the filter with the given angle
    //--------------------------------------------
    void init(float initialAngle);
    //--------------------------------------------------------
    // Run both steps of Kalman filter and returns mean angle
    //--------------------------------------------------------
    float runKalmanFilter(float deltaAngle, float measuredAngle);
    //--------------------------------------
    // Prediction step of the Kalman filter
    //--------------------------------------
    void predictAngle(float deltaAngle);
    //----------------------------------
    // Update step of the Kalman filter
    //----------------------------------
    void updateAngle(float measuredAngle);

    const float& estimatedAngle = curMean;
    const float& variance = curVariance;

protected:
    //--------------------------------------------------
    // Returns the mean value of a product of gaussians
    //--------------------------------------------------
    float gaussianProductMean(float mu, float sigma2, float nu, float r2);
    //------------------------------------------------
    // Returns the variance of a product of gaussians
    //------------------------------------------------
    float gaussianProductVariance(float mu, float sigma2, float nu, float r2);
    //----------------------------------------------
    // Constrain angle to [-180, 180) normalization
    //----------------------------------------------
    float constrainAngle(float x);

    float curVariance;
    float curMean;

    float updateVariance;
    float predictionVariance;
};
#endif