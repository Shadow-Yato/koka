/**********************
* Михайлов Даниил     *
* Линейные алгоритмы  *
* вариант 14    
**********************/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
  // Константы из задания
  double coef = 4.87;
  double t1 = 15.2;
  double k1 = 6.55;
  double t2 = -56.6;
  double k2 = 0.01;
  double hMax = 11.0;

  // Массив времени
  double tau[5] = {0.5, 1.0, 2.0, 5.0, 10.0};

  // Считаем для каждого времени
  for (int tauIndex = 0; tauIndex < 5; ++tauIndex) {
    // Считаем высоту
    double h = coef * sqrt(tau[tauIndex]);

    // Считаем температуру
    double t;
    if (h < hMax) {
      t = t1 - k1 * h;
    } else {
      t = t2 + k2 * h;
    }

    // Выводим результат
    cout << "Time: " << tau[tauIndex] << " h" << endl;
    cout << "Altitude: " << h << " km" << endl;
    cout << "Temperature: " << t << " C" << endl;
    cout << "-------------------" << endl;
  }

  return 0;
}
