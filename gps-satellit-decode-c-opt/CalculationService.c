#include <stdio.h>

int calculateSatelliteShift(int* sumSignal, int* chipSequence) {
    int resultShift = -1;
    for (int shift = 0; shift < 1023; shift++) {

        int correlationValue = 0;
        int calculatedShift = 0;

        for (int index = 0; index < 1023; index++) {
            calculatedShift = (index + shift) % 1023;
            correlationValue += sumSignal[index] * chipSequence[calculatedShift];
        }

        if (1023 - 195 <= correlationValue && correlationValue <= 1023 + 195) {
            resultShift = shift;
            break;
        }
    }

    return resultShift;
}

void invertChipSequence(int *chipsequence) {
    for (int index = 0; index < 1023; index++) {
        if (chipsequence[index] == -1) {
            chipsequence[index] = 1;
        } else {
            chipsequence[index] = -1;
        }
    }
}