#ifndef GPS_DECODING_SERVICE_H
#define GPS_DECODING_SERVICE_H
#include <array>
using namespace std;

void testForId(int sateliteId, array<int, 1023> gpsSignal, array<int, 1023> chipSequence);
void testSequences(array<int, 1023> gpsSignal);
array<int, 1023> readGPSSequenceToArray(char* argument);
void initChipSequenceArray();

#endif //GPS_DECODING_SERVICE_H