#include <stdio.h>
#include <time.h> 
#include "GpsDecodingService.h"

int main(int argc, char* argv[]) {

    clock_t t = clock();

    if (argc == 1) {
        printf("ERROR: Missing gps_sequence file path\n");
        return -1;
    } else if (argc > 2) {
        printf("ERROR: Only one argument supported\n");
        return -1;
    }

    printf("INFO: Using gps sequence from: %s\n", argv[1]);

    initService();

    int gpsArray[1023];
    readGPSSequenceToArray(argv[1], gpsArray);
    findSatelliteIdsAndBits(gpsArray);

    t = clock() - t;

    double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds 
    printf("INFO: Function took %f seconds to execute \n", time_taken);
    return 0;
    
}