#include <array>
#include <iostream>

using namespace std;

int correlateWithShift(array<int, 1023> sumSignal, array<int, 1023> chipSequence, int shift) {
    int ret = 0;
    int tempDelta = 0;
    for (int index = 0; index < 1023; index++) {
        tempDelta = (index + shift) % 1023;
        ret += sumSignal.at(index) * chipSequence.at(tempDelta);
    }
    return ret;
}

int calculateSatelliteShift(array<int, 1023> sumSignal, array<int, 1023> chipSequence) {
    int result = -1;
    int correlationV;
    for (int shift = 0; shift < 1023; shift++) {
        correlationV = correlateWithShift(sumSignal, chipSequence, shift);

        if (1023 - 195 <= correlationV && correlationV <= 1023 + 195) { 
            result = shift;
            break;
        }
    }

    return result;
}

void invertChipSequence(array<int, 1023> &chipsequence) {
    for (int index = 0; index < chipsequence.size() - 1; index++) {
        if (chipsequence.at(index) == -1) {
            chipsequence.at(index) = 1;
        } else {
            chipsequence.at(index) = -1;
        }
    }
}