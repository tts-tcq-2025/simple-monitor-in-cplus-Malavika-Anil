#include <assert.h>
#include <iostream>
using namespace std;
 

bool isTemperatureOk(float temperature) {
  if (temperature < 0 || temperature > 45) {
    cout << "Temperature out of range!\n";
    return false;
  }
  return true;
}
 

bool isSocOk(float soc) {
  if (soc < 20 || soc > 80) {
    cout << "State of Charge out of range!\n";
    return false;
  }
  return true;
}

bool isChargeRateOk(float chargeRate) {
  if (chargeRate > 0.8) {
    cout << "Charge Rate out of range!\n";
    return false;
  }
  return true;
}
 
bool batteryIsOk(float temperature, float soc, float chargeRate) {
 
  return isTemperatureOk(temperature) &&
         isSocOk(soc) &&
         isChargeRateOk(chargeRate);
}
 
int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0.9) == false); 
  assert(batteryIsOk(-1, 20, 0.5) == false); 
  assert(batteryIsOk(25, 10, 0.5) == false); 
  assert(batteryIsOk(25, 70, 0.9) == false); 
 
  
  cout << "\nTesting multiple failures:\n";
  assert(batteryIsOk(-5, 90, 1.0) == false);
  cout << "Done testing multiple failures.\n\n";
 
  return 0;
}
