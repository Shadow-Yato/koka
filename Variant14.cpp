/*******************************
* Author:    Student          *
* Assignment: Variant 14       *
* Description: Meteorological  *
* probe altitude and temp      *
*******************************/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
  // Constants for altitude formula
  double altitudeCoefficient = 4.87;

  // Constants for temperature formula (h < 11 km)
  double tempBaseLow = 15.2;
  double tempSlopeLow = 6.55;

  // Constants for temperature formula (h > 11 km)
  double tempBaseHigh = -56.6;
  double tempSlopeHigh = 0.01;

  // Altitude threshold
  double altitudeThreshold = 11.0;

  // Input: time values
  const int timeCount = 5;
  double timeValues[timeCount] = {0.5, 1.0, 2.0, 5.0, 10.0};

  // Arrays for results
  double altitudeValues[timeCount];
  double temperatureValues[timeCount];

  // Calculation
  for (int timeIndex = 0; timeIndex < timeCount; ++timeIndex) {
    double currentTime = timeValues[timeIndex];

    // Calculate altitude
    double currentAltitude = altitudeCoefficient * sqrt(currentTime);
    altitudeValues[timeIndex] = currentAltitude;

    // Calculate temperature based on altitude
    double currentTemperature;
    if (currentAltitude < altitudeThreshold) {
      currentTemperature = tempBaseLow - tempSlopeLow * currentAltitude;
    } else {
      currentTemperature = tempBaseHigh + tempSlopeHigh * currentAltitude;
    }
    temperatureValues[timeIndex] = currentTemperature;
  }

  // Output
  cout << "Meteorological probe calculation results:" << endl;
  cout << "=========================================" << endl;
  cout << "Time (h)\tAltitude (km)\tTemperature (C)" << endl;
  cout << "-----------------------------------------" << endl;

  for (int resultIndex = 0; resultIndex < timeCount; ++resultIndex) {
    cout << timeValues[resultIndex] << "\t\t"
         << altitudeValues[resultIndex] << "\t\t"
         << temperatureValues[resultIndex] << endl;
  }

  return 0;
}
