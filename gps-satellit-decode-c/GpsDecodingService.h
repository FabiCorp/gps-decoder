#ifndef GPS_DECODING_SERVICE_H
#define GPS_DECODING_SERVICE_H

void initService();
void findSatelliteIdsAndBits(int* gpsSignal);
int* readGPSSequenceToArray(char* fileName, int* gpsArray);

#endif //GPS_DECODING_SERVICE_H