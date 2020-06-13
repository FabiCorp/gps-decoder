#include <iostream>
#include <array>
#include <tuple>

using namespace std;

array<int, 10> motherSequenceOne = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
array<int, 10> motherSequenceTwo = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
array<array<int, 1023>, 24> chipSequenceArray;

tuple<int, int> generateTupelFromInteger(int valueOne, int valueTwo) {
    return make_tuple(valueOne, valueTwo);
}

array<tuple<int, int>, 24> satelliteRegisterTuple = {
    generateTupelFromInteger(2, 6), generateTupelFromInteger(3, 7),
    generateTupelFromInteger(4, 8), generateTupelFromInteger(5, 9),
    generateTupelFromInteger(1, 9), generateTupelFromInteger(2, 10),
    generateTupelFromInteger(1, 8), generateTupelFromInteger(2, 9),
    generateTupelFromInteger(3, 10), generateTupelFromInteger(2, 3),
    generateTupelFromInteger(3, 4), generateTupelFromInteger(5, 6),
    generateTupelFromInteger(6, 7), generateTupelFromInteger(7, 8),
    generateTupelFromInteger(8, 9), generateTupelFromInteger(9, 10),
    generateTupelFromInteger(1, 4), generateTupelFromInteger(2, 5),
    generateTupelFromInteger(3, 6), generateTupelFromInteger(4, 7),
    generateTupelFromInteger(5, 8), generateTupelFromInteger(6, 9),
    generateTupelFromInteger(1, 3), generateTupelFromInteger(4, 6)
};

void shiftMotherSequences(array<int, 10> &mother, int newValue) {
    for (int i = 9; i > 0; i--) {
        mother.at(i) = mother.at(i - 1);
    }
    mother.at(0) = newValue;
}

void init() {
    array<int, 1023> chipSequence;
    int codeValue;

    for (int satelliteIndex = 0; satelliteIndex < 23; satelliteIndex++) {
        for (int chipSequenceIndex = 0; chipSequenceIndex < 1023; chipSequenceIndex++) {
            tuple<int, int> currentSatelliteRegister = satelliteRegisterTuple.at(satelliteIndex);
            int firstShiftValue = get<0>(currentSatelliteRegister) - 1;
            int secondShiftValue = get<1>(currentSatelliteRegister) - 1;
            codeValue = motherSequenceOne.at(9) ^ (motherSequenceTwo.at(firstShiftValue) ^ motherSequenceTwo.at(secondShiftValue));

            int chipSequenceValue = 0;
            if (codeValue == 0) {
                chipSequenceValue = -1;
            } else { 
                chipSequenceValue = 1;
            }

            chipSequence.at(chipSequenceIndex) = chipSequenceValue;

            int mOneNewValue = motherSequenceOne.at(2) ^ motherSequenceOne.at(9);
            int mTwoNewValue = motherSequenceTwo.at(1) ^ motherSequenceTwo.at(2) ^ motherSequenceTwo.at(5) ^
                               motherSequenceTwo.at(7) ^ motherSequenceTwo.at(8) ^ motherSequenceTwo.at(9);

            shiftMotherSequences(motherSequenceOne, mOneNewValue);
            shiftMotherSequences(motherSequenceTwo, mTwoNewValue);
        }

        chipSequenceArray.at(satelliteIndex) = chipSequence;
    }

}

array<int, 1023> getChipSequence(int satelliteId) {

    array<int, 1023> resultChipSequenceArray;
    if (satelliteId > 0 && satelliteId <= 24) {
        resultChipSequenceArray =  chipSequenceArray.at(satelliteId - 1);
    }
   
    return resultChipSequenceArray;
}
