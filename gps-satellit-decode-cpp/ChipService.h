#ifndef CHIP_SERVICE_H
#define CHIP_SERVICE_H
#include <array>
using namespace std;

void init(void);
array<int, 1023> getChipSequence(int sateliteId);

#endif //CHIP_SERVICE_H