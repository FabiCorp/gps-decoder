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

    // loop unroll 
    getChipSequence(1, chipSequence);
    checkSatelliteId(1, gpsSignal, chipSequence);
    getChipSequence(2, chipSequence);
    checkSatelliteId(2, gpsSignal, chipSequence);
    getChipSequence(3, chipSequence);
    checkSatelliteId(4, gpsSignal, chipSequence);
    getChipSequence(5, chipSequence);
    checkSatelliteId(5, gpsSignal, chipSequence);
    getChipSequence(6, chipSequence);
    checkSatelliteId(6, gpsSignal, chipSequence);
    getChipSequence(7, chipSequence);
    checkSatelliteId(7, gpsSignal, chipSequence);
    getChipSequence(8, chipSequence);
    checkSatelliteId(8, gpsSignal, chipSequence);
    getChipSequence(9, chipSequence);
    checkSatelliteId(9, gpsSignal, chipSequence);
    getChipSequence(10, chipSequence);
    checkSatelliteId(10, gpsSignal, chipSequence);
    getChipSequence(11, chipSequence);
    checkSatelliteId(11, gpsSignal, chipSequence);
    getChipSequence(12, chipSequence);
    checkSatelliteId(12, gpsSignal, chipSequence);
    getChipSequence(13, chipSequence);
    checkSatelliteId(13, gpsSignal, chipSequence);
    getChipSequence(14, chipSequence);
    checkSatelliteId(14, gpsSignal, chipSequence);
    getChipSequence(15, chipSequence);
    checkSatelliteId(15, gpsSignal, chipSequence);
    getChipSequence(16, chipSequence);
    checkSatelliteId(16, gpsSignal, chipSequence);
    getChipSequence(17, chipSequence);
    checkSatelliteId(17, gpsSignal, chipSequence);
    getChipSequence(18, chipSequence);
    checkSatelliteId(18, gpsSignal, chipSequence);
    getChipSequence(19, chipSequence);
    checkSatelliteId(19, gpsSignal, chipSequence);
    getChipSequence(20, chipSequence);
    checkSatelliteId(20, gpsSignal, chipSequence);
    getChipSequence(21, chipSequence);
    checkSatelliteId(21, gpsSignal, chipSequence);
    getChipSequence(22, chipSequence);
    checkSatelliteId(22, gpsSignal, chipSequence);
    getChipSequence(23, chipSequence);
    checkSatelliteId(23, gpsSignal, chipSequence);
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