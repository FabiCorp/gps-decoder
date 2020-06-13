#include <stdio.h>
#include "ChipService.h"
#include "CalculationService.h"

void initService() {
    initChipService();
}

void checkSatelliteId(int satelliteId, int* gpsSignal, int* chipSequence) {
    int shift = calculateSatelliteShift(gpsSignal, chipSequence);

    if (shift != -1) {
        printf("INFO: Signal from Satellite %i send Bit 1 with Shift %i \n", satelliteId + 1, shift);
    } else {
        invertChipSequence(chipSequence);
        shift = calculateSatelliteShift(gpsSignal, chipSequence);
        if (shift != -1) {
            printf("INFO: Signal from Satellite %i send Bit 0 With Shift %i (inverted) \n", satelliteId + 1, shift);
        }
    }
}

void findSatelliteIdsAndBits(int* gpsSignal) {
    int chipSequence[1023];
    for (int index = 0; index < 24; index++) {
        getChipSequence(index, chipSequence);
        checkSatelliteId(index, gpsSignal, chipSequence);
    }
}

void readGPSSequenceToArray(char* fileName, int *gpsArray) {
    FILE* filePointer;
    filePointer = fopen(fileName, "r");
 
    int index;
    for (index = 0; index < 1023; index++) {
        fscanf(filePointer, "%d,", &gpsArray[index]);
    }

    fclose(filePointer);   
}