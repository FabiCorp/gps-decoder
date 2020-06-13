#include <iostream>
#include <fstream>
#include <array>
#include <sstream>
#include "ChipService.h"
#include "CalculationService.h"

using namespace std;

void initChipSequenceArray() {
    init();
}

void testForId(int sateliteId, array<int, 1023> gpsSignal, array<int, 1023> chipSequence)
{
    int shift = calculateSatelliteShift(gpsSignal, chipSequence); 

    if (shift != -1)
    {
        cout << "INFO: Signal from Satellite " << sateliteId << " send Bit 1 with Shift " << shift << endl;
    }
    else
    {
        invertChipSequence(chipSequence);
        shift = calculateSatelliteShift(gpsSignal, chipSequence);
        if (shift != -1)
        {
           cout << "INFO: Signal from Satellite " << sateliteId << " send Bit 0 with Shift " << shift << " (inverted)" << endl;
        }
    }
}

void testSequences(array<int, 1023> gpsSignal) {

    array<int, 1023> chipSequence;
    for (int index = 1; index <= 24; index++) {
        chipSequence = getChipSequence(index);
        testForId(index, gpsSignal, chipSequence);
    }
}

array<int, 1023> readGPSSequenceToArray(char* fileName) {

    ifstream inFile;
    int gpsSequence[1023];
    int x;
    inFile.open(fileName);
    if (!inFile) {
        cerr << "ERROR: Unable to open file";
        exit(1);
    }

    array<int, 1023> gpsArray;
    int arrayIndex = 0;
    while (inFile >> x) {
        gpsArray.at(arrayIndex) = x;
        arrayIndex++;
    }
    inFile.close();

    return gpsArray;
}
