/*
Name: Reid Pace
Class: 122
Assignment: PA1
Date: January 10th, 2025
Lab Section: 10
Description: main file for program execution
*/
#include "fitbit.h"

int main() {

	FILE *infile, *outfile;

	FitbitData fitbit[1442] = { 0 };

	infile = fopen("FitbitData.csv", "r"); outfile = fopen("Results.csv", "w");

	if ((infile == NULL) || (outfile == NULL)) printf("Error opening files");
		
	scan_file(infile, fitbit);

	print_file(outfile, fitbit);

	fclose(infile); fclose(outfile);

	return 0;
}