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
  // Call individual checks and combine their results
  return isTemperatureOk(temperature) &&
         isSocOk(soc) &&
         isChargeRateOk(chargeRate);
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  // This will print multiple error messages if all are out of range,
  // but only the first failing condition will cause batteryIsOk to return false
  // due to short-circuiting of '&&'
  assert(batteryIsOk(50, 85, 0.9) == false); // Modified chargeRate for more comprehensive test
  assert(batteryIsOk(-1, 20, 0.5) == false); // Test low temperature
  assert(batteryIsOk(25, 10, 0.5) == false); // Test low SOC
  assert(batteryIsOk(25, 70, 0.9) == false); // Test high charge rate

  // Test case where multiple conditions fail (prints multiple errors)
  cout << "\nTesting multiple failures:\n";
  assert(batteryIsOk(-5, 90, 1.0) == false);
  cout << "Done testing multiple failures.\n\n";

  return 0;
}
