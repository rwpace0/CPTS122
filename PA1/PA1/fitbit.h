/*
Name: Reid Pace
Class: 122
Assignment: PA1
Date: January 10th, 2025
Lab Section: 10
Description: header file for function declaration.
*/

#ifndef FITBIT
#define FITBIT
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum sleep
{
	NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
} Sleep;

typedef struct fitbit
{
	char patient[10];
	char minute[9];
	double calories;
	double distance;
	unsigned int floors;
	unsigned int heartRate;
	unsigned int steps;
	Sleep sleepLevel;
} FitbitData;

/*************************************************************
* Function:	scan_file
* Date Created: 1/10/25
* Date Last Modified: 1/21/25
* Description: scans the input file then parses and stores the data in fitbit array.
* Input parameters: input file, fitbit array.
* Returns: none
* Preconditions: FitbitData.csv must be accessible.
* Postconditions: stores information in fitbit[].
*************************************************************/
void scan_file(FILE* infile, FitbitData fitbit[]);

/*************************************************************
* Function:	calories_total
* Date Created: 1/11/25
* Date Last Modified: 1/11/25
* Description: stores the total calories.
* Input parameters: fitbit array.
* Returns: total calories
* Preconditions: calories must have been correctly stored from scan_file
* Postconditions: finds total calories.
*************************************************************/
double calories_total(FitbitData fitbit[]);

/*************************************************************
* Function:	distance_total
* Date Created: 1/11/25
* Date Last Modified: 1/11/25
* Description: stores the total distance walked.
* Input parameters: fitbit array.
* Returns: total distance
* Preconditions: distance must have been correctly stored from scan_file
* Postconditions: finds total distance.
*************************************************************/
double distance_total(FitbitData fitbit[]);

/*************************************************************
* Function:	floors_total
* Date Created: 1/11/25
* Date Last Modified: 1/11/25
* Description: stores the total floors climbed.
* Input parameters: fitbit array.
* Returns: total floors
* Preconditions: floors must have been correctly stored from scan_file
* Postconditions: finds total floors.
*************************************************************/
unsigned int floors_total(FitbitData fitbit[]);

/*************************************************************
* Function:	steps_total
* Date Created: 1/11/25
* Date Last Modified: 1/11/25
* Description: stores the total steps taken.
* Input parameters: fitbit array.
* Returns: total steps
* Preconditions: steps must have been correctly stored from scan_file
* Postconditions: finds total steps.
*************************************************************/
unsigned int steps_total(FitbitData fitbit[]);

/*************************************************************
* Function:	heart_rate_avg
* Date Created: 1/11/25
* Date Last Modified: 1/11/25
* Description: stores the average heart rate.
* Input parameters: fitbit array.
* Returns: average heartrate (total/1440)
* Preconditions: heartrate must have been correctly stored from scan_file
* Postconditions: finds average heartrate.
*************************************************************/
unsigned int heart_rate_avg(FitbitData fitbit[]);

/*************************************************************
* Function:	steps_max
* Date Created: 1/11/25
* Date Last Modified: 1/11/25
* Description: stores the max steps taken.
* Input parameters: fitbit array.
* Returns: minutes
* Preconditions: steps must have been correctly stored from steps_total
* Postconditions: finds the max steps.
*************************************************************/
unsigned int steps_max(FitbitData fitbit[]);

/*************************************************************
* Function:	sleep_range
* Date Created: 1/11/25
* Date Last Modified: 1/11/25
* Description: stores the longest range of consecutive sleep
* Input parameters: fitbit array.
* Returns: range of sleep
* Preconditions: sleeplevel must be correctly stored
* Postconditions: finds max range of poor sleep.
*************************************************************/
char* sleep_range(FitbitData fitbit[]);

/*************************************************************
* Function:	print_file
* Date Created: 1/11/25
* Date Last Modified: 1/12/25
* Description: prints data to output file
* Input parameters: output file, fitbit array.
* Returns: none
* Preconditions: all data must be accessible from the above functions
* Postconditions: prints data to Results.csv
*************************************************************/
void print_file(FILE* outfile, FitbitData fitbit[]);

#endif