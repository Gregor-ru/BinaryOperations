#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <conio.h>

#define MAXSIZE 1024

char* concat(char* s1, char* s2) {

	size_t len1 = strlen(s1);
	size_t len2 = strlen(s2);

	char* result = malloc(len1 + len2 + 1);

	if (!result) {
		fprintf(stderr, "malloc() failed: insufficient memory!\n");
		return NULL;
	}

	memcpy(result, s1, len1);
	memcpy(result + len1, s2, len2 + 1);

	return result;
}

int swap_beats(int IntValue, int i, int j) {

	int a = (IntValue >> i) & 1;
	int b = (IntValue >> j) & 1;

	if (a != b) IntValue = IntValue & ~((1 << i) | (1 << j)) | (a << j) | (b << i);

	return IntValue;
}

char* convert_to_bin_string(int StartValueInt, int MinAmountBeats) {

	char* StartValue = malloc(MAXSIZE);
	char* BinValue = malloc(MAXSIZE);

	if (StartValue) {

		_itoa(StartValueInt, StartValue, 2);

		if (strlen(StartValue) % MinAmountBeats > 0) {

			int ZeroCount = MinAmountBeats - (strlen(StartValue) % MinAmountBeats);
			char* ZeroString = "";

			for (int i = 0; i < ZeroCount; i++) {
				ZeroString = concat(ZeroString, "0");
			}

			BinValue = concat(ZeroString, StartValue);

		}
		else {
			BinValue = StartValue;
		}
	}
	else {
		return 0;
	}

	return BinValue;
}

int main() {

	int StartValueInt, FoursOfBeatsCount = 0, IterationCount = 0, Index=0;
	char* BinString = malloc(MAXSIZE);
	char* HexString = malloc(MAXSIZE);

	if (scanf("%d", &StartValueInt));

	BinString = convert_to_bin_string(StartValueInt, 8);
	printf("\nBin: %s	", BinString);

	if(HexString) _itoa(StartValueInt, HexString, 16);
	printf("Hex: %s\n", HexString);

	IterationCount = strlen(BinString);

	for (int i = 0; i < IterationCount / 2; i+=4) {

		StartValueInt = swap_beats(StartValueInt, IterationCount - i - 1, i+3);
		StartValueInt = swap_beats(StartValueInt, IterationCount - i - 2, i + 2);
		StartValueInt = swap_beats(StartValueInt, IterationCount - i - 3, i + 1);
		StartValueInt = swap_beats(StartValueInt, IterationCount - i - 4, i);
		
	}

	BinString = convert_to_bin_string(StartValueInt, 8);
	printf("\nBin: %s	", BinString);

	if (HexString) _itoa(StartValueInt, HexString, 16);
	printf("Hex: %s\n", HexString);
	
}
