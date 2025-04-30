/*
Name: Reid Pace
Class: 122
Assignment: PA2
Date: January 25th, 2025
Lab Section: 10
Description: main file for program execution
*/

#include "dmm.h"

int main() {

	int choice = 0;
	Node* head = NULL;
	FILE* musicFile = NULL;

	while (1) {
		choice = main_menu();
		switch (choice) {
		case LOAD:
			load(musicFile, &head);
			break;
		case STORE:
			store(musicFile, &head);
			break;
		case DISPLAY:
			display(head);
			break;
		case INSERT:

			break;
		case DELETE:

			break;
		case EDIT:
			edit(head);
			break;
		case SORT:

			break;
		case RATE:
			rate(head);
			break;
		case PLAY:
			play(head);
			break;
		case SHUFFLE:

			break;
		case EXIT:
			store(musicFile, &head);
			printf("\nExiting...\n");
			return 0;
			break;
		default:
			printf("Invalid input. Please try again.\n");
			break;
		}
	}
	fclose(musicFile);
	return 0;
}