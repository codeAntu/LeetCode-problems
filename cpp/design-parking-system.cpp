#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class ParkingSystem {
public:
   int space[3];
   ParkingSystem(int big, int medium, int small) {
      space[0] = big;
      space[1] = medium;
      space[2] = small;
   }

   bool addCar(int carType) {
      return space[carType - 1]-- > 0;
   }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
