#include <iostream>
#include <fstream>
#include <array>
#include "GpsDecodingService.h"
#include <time.h> 

using namespace std;

int main(int argc, char* argv[]) {

    clock_t t = clock();

    if (argc == 1) {
        cout << "ERROR: Missing gps_sequence file path" << endl;
        return -1;
    } else if (argc > 2) {
        cout << "ERROR: Only one argument supported" << endl;
        return -1;
    }

    cout << "INFO: Using gps sequence from: " << argv[1] << endl;

    initChipSequenceArray();
    array<int, 1023> gpsArray = readGPSSequenceToArray(argv[1]);

    testSequences(gpsArray);

    t = clock() - t;

    double time_taken = ( (double) t ) / CLOCKS_PER_SEC; // in seconds 
    printf("INFO: Function took %f seconds to execute \n", time_taken);
}