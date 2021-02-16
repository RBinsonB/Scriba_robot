/*
    AngleKalmanFilter.cpp - Library for angle estimating Kalman filter
    Created by Robin Baran, January 2021
*/

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
#include "angle_kalman_filter.h"

//-------------------------------------------------------------
//    Construct an angle Kalman filter object with given
// variances for absolute measurement and relative measurement
//-------------------------------------------------------------
AngleKalmanFilter::AngleKalmanFilter(){
}

//----------------------------------------------------------
// Initialize the filter with variances and the given angle
//----------------------------------------------------------
void AngleKalmanFilter::init(float absoluteMeasVariance,  float relativeMeasVariance, float initialAngle){
    //Initialize variances
    updateVariance = absoluteMeasVariance;
    predictionVariance = relativeMeasVariance;

    // set current mean value of filter with given initial angle
    // constrain the angle to normalization
    curMean = constrainAngle(initialAngle);

    // set current variance of filter with update variance, assuming
    // initial value if from same source as update measurements
    curVariance = updateVariance;
}

//--------------------------------------------------------
// Run both steps of Kalman filter and returns mean angle
//--------------------------------------------------------
float AngleKalmanFilter::runKalmanFilter(float deltaAngle, float measuredAngle){
    // predict step using the relative measurement
    predictAngle(deltaAngle);
    // update step using the absolute measurement
    updateAngle(measuredAngle);
    // return mean value of filter as estimated angle
    return curMean;
}

//----------------------------------
// Update step of the Kalman filter
//----------------------------------
void AngleKalmanFilter::updateAngle(float measuredAngle){
    // update values with product of current gaussian and absolute measurement gaussian 
    curMean = constrainAngle(gaussianProductMean(curMean, curVariance, measuredAngle, updateVariance));
    curVariance = gaussianProductVariance(curMean, curVariance, measuredAngle, updateVariance);
}

//--------------------------------------
// Prediction step of the Kalman filter
//--------------------------------------
void AngleKalmanFilter::predictAngle(float deltaAngle){
    // update values with convolution of current gaussian and relative measurement gaussian
    curMean = constrainAngle(curMean + deltaAngle);
    curVariance = curVariance + predictionVariance;
}

//--------------------------------------------------
// Returns the mean value of a product of gaussians
//--------------------------------------------------
float AngleKalmanFilter::gaussianProductMean(float mu, float sigma2, float nu, float r2){
    // make angles positive so mean value can be calculated properly 
    if (mu < 0) mu +=360;
    if (nu < 0) nu +=360;
    // compute mean according to gaussian product
    return (r2*mu + sigma2*nu)/(r2+sigma2);
}

//------------------------------------------------
// Returns the variance of a product of gaussians
//------------------------------------------------
float AngleKalmanFilter::gaussianProductVariance(float mu, float sigma2, float nu, float r2){
    // compute variance according to gaussian product
    return 1/((1/r2) + (1/sigma2));
}
//----------------------------------------------
// Constrain angle to [-180, 180) normalization
//----------------------------------------------
float AngleKalmanFilter::constrainAngle(float x){
    // push value to be between -360, 360
    x = fmod(x + 180,360);
    // push value to be between 0, 360
    if (x < 0){
        x += 360;
    }
    // push value to be between -180, 180
    return x - 180;
}