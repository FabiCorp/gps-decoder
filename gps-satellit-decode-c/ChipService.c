
int motherSequenceOne[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
int motherSequenceTwo[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
int chipSequenceArray[24][1023];

struct tuple {
	int firstValue;
	int secondValue;
};

struct tuple generateTupelFromInteger(int valueOne, int valueTwo) {
	struct tuple generatedTuple;
	generatedTuple.firstValue = valueOne;
	generatedTuple.secondValue = valueTwo;
	return generatedTuple;
}

struct tuple satelliteRegisterTupleArray[24];

void fillSatelliteRegisterTupleArray() {
    satelliteRegisterTupleArray[0]  = generateTupelFromInteger(2, 6);
    satelliteRegisterTupleArray[1]  = generateTupelFromInteger(3, 7);
    satelliteRegisterTupleArray[2]  = generateTupelFromInteger(4, 8);
    satelliteRegisterTupleArray[3]  = generateTupelFromInteger(5, 9);
    satelliteRegisterTupleArray[4]  = generateTupelFromInteger(1, 9);
    satelliteRegisterTupleArray[5]  = generateTupelFromInteger(2, 10);
    satelliteRegisterTupleArray[6]  = generateTupelFromInteger(1, 8);
    satelliteRegisterTupleArray[7]  = generateTupelFromInteger(2, 9);
    satelliteRegisterTupleArray[8]  = generateTupelFromInteger(3, 10);
    satelliteRegisterTupleArray[9]  = generateTupelFromInteger(2, 3);
    satelliteRegisterTupleArray[10] = generateTupelFromInteger(3, 4);
    satelliteRegisterTupleArray[11] = generateTupelFromInteger(5, 6);
    satelliteRegisterTupleArray[12] = generateTupelFromInteger(6, 7);
    satelliteRegisterTupleArray[13] = generateTupelFromInteger(7, 8);
    satelliteRegisterTupleArray[14] = generateTupelFromInteger(8, 9);
    satelliteRegisterTupleArray[15] = generateTupelFromInteger(9, 10);
    satelliteRegisterTupleArray[16] = generateTupelFromInteger(1, 4);
    satelliteRegisterTupleArray[17] = generateTupelFromInteger(2, 5);
    satelliteRegisterTupleArray[18] = generateTupelFromInteger(3, 6);
    satelliteRegisterTupleArray[19] = generateTupelFromInteger(4, 7);
    satelliteRegisterTupleArray[20] = generateTupelFromInteger(5, 8);
    satelliteRegisterTupleArray[21] = generateTupelFromInteger(6, 9);
    satelliteRegisterTupleArray[22] = generateTupelFromInteger(1, 3);
    satelliteRegisterTupleArray[23] = generateTupelFromInteger(4, 6);
}

void shiftMotherSequenceAndSetValue(int *motherSequence, int value) {
    for (int i = 9; i > 0; i--) {
        motherSequence[i] = motherSequence[i - 1];
    }
    motherSequence[0] = value;
}

void setSequenceInChipSequenceArray(int satelliteIndex, int *chipSequence) {
    for (int index = 0; index < 1023; index++) {
        chipSequenceArray[satelliteIndex][index] = chipSequence[index];
    }
}

int* copySequenceWithIndexFromTo(int satelliteIndex, int* chipSequence) {
    for (int index = 0; index < 1023; index++) {
        chipSequenceArray[satelliteIndex][index] = chipSequence[index];
    }
}

void initChipSequenceArray(void) {
    int chipSequence[1023];
    int codeValue;

    for (int satelliteIndex = 0; satelliteIndex < 24; satelliteIndex++) {
        struct tuple currentSatelliteRegister = satelliteRegisterTupleArray[satelliteIndex];
        for (int chipSequenceIndex = 0; chipSequenceIndex < 1023; chipSequenceIndex++) {
            
            int firstShiftValue = currentSatelliteRegister.firstValue - 1;
            int secondShiftValue = currentSatelliteRegister.secondValue - 1;
            codeValue = motherSequenceOne[9] ^ (motherSequenceTwo[firstShiftValue] ^ motherSequenceTwo[secondShiftValue]);

            int chipSequenceValue = 0;
            if (codeValue == 0) {
                chipSequenceValue = -1;
            } else {
                chipSequenceValue = 1;
            }

            chipSequence[chipSequenceIndex] = chipSequenceValue;
             

            int newFirstMotherValue = motherSequenceOne[2] ^ motherSequenceOne[9];
            int newSecondMotherValue = motherSequenceTwo[1] ^ motherSequenceTwo[2] ^ motherSequenceTwo[5] ^
                                       motherSequenceTwo[7] ^ motherSequenceTwo[8] ^ motherSequenceTwo[9];

            shiftMotherSequenceAndSetValue(motherSequenceOne, newFirstMotherValue);
            shiftMotherSequenceAndSetValue(motherSequenceTwo, newSecondMotherValue);
        }

        setSequenceInChipSequenceArray(satelliteIndex, chipSequence);
    }
}

void getChipSequence(int satelliteIndex, int *chipSequence) {

    for (int index = 0; index < 1023; index++) {
        chipSequence[index] = chipSequenceArray[satelliteIndex][index];
    }

}

void initChipService(void) {
    fillSatelliteRegisterTupleArray();
    initChipSequenceArray();
}