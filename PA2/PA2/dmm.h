/*
Name: Reid Pace
Class: 122
Assignment: PA2
Date: January 25th, 2025
Lab Section: 10
Description: header file for function declaration
*/

#ifndef DMM
#define DMM
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOAD 1
#define STORE 2
#define DISPLAY 3
#define INSERT 4
#define DELETE 5
#define EDIT 6
#define SORT 7
#define RATE 8
#define PLAY 9
#define SHUFFLE 10
#define EXIT 11

typedef struct duration {
	int minutes;
	int seconds;
} Duration;

typedef struct record { // in order of csv file
	char artist[50];
	char album[50];
	char title[50];
	char genre[50];
	Duration length;
	int plays;
	int rating;
} Record;

typedef struct node {
	Record data;
	struct node* next;
	struct node* prev;
} Node;

/*************************************************************
* Function:	main_menu
* Date Created: 1/25/25
* Date Last Modified: 1/25/25
* Description: displays the main menu to the user and allows for selection
* Input parameters: none
* Returns: the input of the user
* Preconditions: None
* Postconditions: enters screen of user choice
*************************************************************/
int main_menu();

/*************************************************************
* Function:	create_node
* Date Created: 1/25/25
* Date Last Modified: 1/25/25
* Description: creates a node
* Input parameters: Record newData
* Returns: the new node created at the head
* Preconditions: None
* Postconditions: Creates a node using the record struct
*************************************************************/
Node* create_node(Record newData);

/*************************************************************
* Function:	insert_front
* Date Created: 1/25/25
* Date Last Modified: 1/25/25
* Description: inserts the node at the front of the list
* Input parameters: Node head and record newData
* Returns: if the function successfully moved the node to the front
* Preconditions: create_node must be accessible
* Postconditions: adds the new node to the head of the list
*************************************************************/
int insert_front(Node** head, Record newData);

/*************************************************************
* Function:	load
* Date Created: 1/26/25
* Date Last Modified: 1/27/25
* Description: Loads the song information from the playlist file
* Input parameters: music file and head
* Returns: none
* Preconditions: Insert front must be accessible
* Postconditions: loads the csv file into the program
*************************************************************/
void load(FILE* input, Node** head);

/*************************************************************
* Function:	store
* Date Created: 1/28/25
* Date Last Modified: 1/28/25
* Description: stores the current node to the playlist file
* Input parameters: playlist file and head
* Returns: none
* Preconditions: musicfile must be accessible
* Postconditions: stores current node to file
*************************************************************/
void store(FILE* output, Node** head);

/*************************************************************
* Function:	display
* Date Created: 1/28/25
* Date Last Modified: 1/28/25
* Description: display the current node to the screen
* Input parameters:head
* Returns: none
* Preconditions: the node must be accessible
* Postconditions: displays the current to the screen
*************************************************************/
void display(Node* head);

/*************************************************************
* Function:	edit
* Date Created: 1/29/25
* Date Last Modified: 1/29/25
* Description: edits a song of the users choice
* Input parameters: head
* Returns: none
* Preconditions: the node must be accessible
* Postconditions: edited song will appear 
*************************************************************/
void edit(Node* head);

/*************************************************************
* Function:	rate
* Date Created: 1/29/25
* Date Last Modified: 1/29/25
* Description: allows the user to rate a song
* Input parameters: head
* Returns: none
* Preconditions: the node must be accessible
* Postconditions: song will appear with the new rating
*************************************************************/
void rate(Node* head);

/*************************************************************
* Function:	play
* Date Created: 1/29/25
* Date Last Modified: 1/29/25
* Description: "plays" a song then goes through the list until reaching the first played song
* Input parameters: head
* Returns: none
* Preconditions: the node must be accesible
* Postconditions: the songs will "play"
*************************************************************/
void play(Node* head);
#endif
