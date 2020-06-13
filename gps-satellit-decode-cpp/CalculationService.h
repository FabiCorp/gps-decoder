#ifndef CALCULATION_SERVICE_H
#define CALCULATION_SERVICE_H
#include <array>
using namespace std;
 
int calculateSatelliteShift(array<int, 1023> sumSignal, array<int, 1023> chipSequence);
void invertChipSequence(array<int, 1023> &chipsequence);

#endif //CHIP_SERVICE_H