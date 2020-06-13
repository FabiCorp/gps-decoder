executable: ChipService.o CalculationService.o GpsDecodingService.o main.o
	gcc -O3 ChipService.o CalculationService.o GpsDecodingService.o main.o -o executable
	rm *.o

main.o: main.c
	gcc -O3 -c main.c

CalculationService.o: CalculationService.c
	gcc -O3 -c CalculationService.c

GpsDecodingService.o: GpsDecodingService.c
	gcc -O3 -c GpsDecodingService.c

ChipService.o: ChipService.c
	gcc -O3 -c ChipService.c

clean: 
	rm *.o executable