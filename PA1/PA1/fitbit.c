/*
Name: Reid Pace
Class: 122
Assignment: PA1
Date: January 10th, 2025
Lab Section: 10
Description: source file for function definition.
*/
#include "fitbit.h"

void scan_file(FILE* infile, FitbitData fitbit[]) {
		
	char line[100] = "";

	char target_patient[10] = "";

	int num_mins = 0, data_skip = 0;

	// read and parse the first line to extract the target patient id
	if (fgets(line, 100, infile) == NULL) {
		printf("Fgets = Null"); 
		return;
	}

	//skip the first col
	char *token = strtok(line, ",");

	//extract patient id
	if ((token = strtok(NULL, ",")) == NULL) {
		printf("Token = Null"); 
		return; 
	}
	//copy patient id
	strcpy(target_patient, token);

	while (fgets(line, 100, infile) != NULL) {

		//token variable will hold all of the values at different points in code
		token = strtok(line, ",");
		//if not the same value then skip to the next line
		if (token == NULL || strcmp(token, target_patient) != 0) {
			data_skip++;
			continue;
		}

		//value must be patient so copy value
		strcpy(fitbit[num_mins].patient, token);

		//get minutes
		token = strtok(NULL, ",");
		// if duplicates then skip line
		if (token == NULL || (num_mins > 0 && strcmp(token, fitbit[num_mins - 1].minute) == 0)) continue;

		//copy minutes
		strcpy(fitbit[num_mins].minute, token);

		//extract and validate
		token = strtok(NULL, ",");
		fitbit[num_mins].calories = (token != NULL) ? atof(token) : -1.0;

		token = strtok(NULL, ",");
		fitbit[num_mins].distance = (token != NULL) ? atof(token) : -1.0;

		token = strtok(NULL, ",");
		fitbit[num_mins].floors = (token != NULL) ? (unsigned int)atof(token) : -1;

		token = strtok(NULL, ",");
		fitbit[num_mins].heartRate = (token != NULL) ? (unsigned int)atof(token) : -1;

		token = strtok(NULL, ",");
		fitbit[num_mins].steps = (token != NULL) ? (unsigned int)atof(token) : -1;

		token = strtok(NULL, ",");
		fitbit[num_mins].sleepLevel = (token != NULL) ? atoi(token) : -1;

		num_mins++;
	}

	printf("Data Skipped: %d\n", data_skip);
	printf("Rows Processed: %d\n", num_mins);

}

double calories_total(FitbitData fitbit[]) {

	double cals = 0.0;

	//1440 is the max minutes
	for (int i = 0; i < 1440; i++) {

		cals += fitbit[i].calories;

	}

	return cals;

}

double distance_total(FitbitData fitbit[]) {

	double dist = 0.0;

	//1440 is the max minutes
	for (int i = 0; i < 1440; i++) {

		dist += fitbit[i].distance;

	}

	return dist;

}

unsigned int floors_total(FitbitData fitbit[]) {

	unsigned int floors = 0;

	//1440 is the max minutes
	for (int i = 0; i < 1440; i++) {

		floors += fitbit[i].floors;

	}

	return floors;

}

unsigned int steps_total(FitbitData fitbit[]) {

	unsigned int steps = 0;

	//1440 is the max minutes
	for (int i = 0; i < 1440; i++) {

		steps += fitbit[i].steps;

	}

	return steps;

}

unsigned int heart_rate_avg(FitbitData fitbit[]) {

	unsigned int heart = 0;

	//1440 is the max minutes
	for (int i = 0; i < 1440; i++) {

		heart += fitbit[i].heartRate;

	}

	return heart / 1440;

}

unsigned int steps_max(FitbitData fitbit[]) {

	unsigned int minute = 0;

	unsigned int max = 0;

	//iterate backwards for latest occurance
	for (int i = 1440 - 1; i > 0; i--) {

		//set highest steps count to max
		if (fitbit[i].steps > max) {
			max = fitbit[i].steps;
			minute = i;
		}
	}

	return minute;

}

char* sleep_range(FitbitData fitbit[]) {

	int max_sum = 0, sum = 0, range_num = 0;

	char start[9] = {'\0'};
	char end[9] = {'\0'};
	//allocate mem for range
	char* range = malloc(20 * sizeof(char));
	//error check
	if (range == NULL) {
		printf("Memory allocation failed\n");
		return NULL;
	}

	for (int i = 0; i < 1440; i++) {

		//poor sleep
		if (fitbit[i].sleepLevel > 1) {

			range_num = i;

			//consecutive sleep found, add to range
			while (fitbit[range_num].sleepLevel > 1) {

				sum += fitbit[range_num].sleepLevel;
				range_num++;

			}

			//update if new max is found
			if (sum > max_sum) {

				max_sum = sum;

				//copy start and end minutes to the range
				strcpy(start, fitbit[i].minute);
				strcpy(end, fitbit[range_num - 1].minute);

			}
		}
		//reset
		sum = 0;
	}

	// start:end
	sprintf(range, "%s:%s", start, end);

	return range;
}

void print_file(FILE* outfile, FitbitData fitbit[]) {

	fprintf(outfile, "Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep\n");
	
	fprintf(outfile, "%.2lf,%.2lf,%d,%d,%d,%d at %s,%s\n", calories_total(fitbit), distance_total(fitbit), floors_total(fitbit), steps_total(fitbit), heart_rate_avg(fitbit), fitbit[steps_max(fitbit)].steps, fitbit[steps_max(fitbit)].minute, sleep_range(fitbit));

}