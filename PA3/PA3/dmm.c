/*
Name: Reid Pace
Class: 122
Assignment: PA2
Date: January 25th, 2025
Lab Section: 10
Description: source file for function definition.
*/

#include "dmm.h"

int main_menu() {

	int choice = 0;

	printf("Digital Music Maker:\n(1) Load\n(2) Store\n(3) Display\n(4) Insert\n(5) Delete\n(6) Edit\n(7) Sort\n(8) Rate\n(9) Play\n(10) Shuffle\n(11) Exit\n\n");
	scanf("%d", &choice);

	return choice;
}

// function shown in class
Node* create_node(Record newData) {
	Node* tempNode = (Node*)malloc(sizeof(Node));

	if (tempNode != NULL) {

		tempNode->next = NULL; tempNode->prev = NULL;
		tempNode->data = newData;

	}
	return tempNode;
}

int insert_front(Node** head, Record newData) { // head of list

	Node* tempNode = create_node(newData);// temp = current

	int success = 0;
	
	if (newData.plays < 0 || newData.rating > 5) return success;

	if (tempNode != NULL) {
		
		success = 1;
		if (*head == NULL) {
			*head = tempNode;
		}
		else {
			
			tempNode->next = *head; // temp points to head, A
			(*head)->prev = tempNode; // points prev head, A, to temp; bidirectional link
			*head = tempNode; // temp (new node) is now at head

		}
		
	}
	return success;
}

void load(FILE* input, Node** head) {
	input = fopen("musicPlayList.csv", "r"); // read

	char line[500] = "";
	char* token;
	Record newData = { "" };

	while (fgets(line, sizeof(line), input)) {

		if (line[0] == '"') {// in case of last, first 

			token = strtok(line, "\"");
			strcpy(newData.artist, token);

		}
		else {
			token = strtok(line, ",");
			strcpy(newData.artist, token);
		}

		token = strtok(NULL, ",");
		strcpy(newData.album, token);

		token = strtok(NULL, ",");
		strcpy(newData.title, token);

		token = strtok(NULL, ",");
		strcpy(newData.genre, token);

		token = strtok(NULL, ":");
		newData.length.minutes = atoi(token);

		token = strtok(NULL, ",");
		newData.length.seconds = atoi(token);

		token = strtok(NULL, ",");
		newData.plays = atoi(token);

		token = strtok(NULL, "\n");
		newData.rating = atoi(token);

		if (!insert_front(head, newData)) printf("\nLoad Fail\n");

	}

	printf("\nLoad Success\n\n");
	printf("\n"); system("pause"); system("cls");
}

void store(FILE* output, Node** head) {

	output = fopen("musicPlayList.csv", "w");
	Node* current = *head;

	while (current != NULL) {

		fprintf(output, "%s,", current->data.artist);
		fprintf(output, "%s,", current->data.album);
		fprintf(output, "%s,", current->data.title);
		fprintf(output, "%s,", current->data.genre);
		fprintf(output, "%d:%d,", current->data.length.minutes, current->data.length.seconds);
		fprintf(output, "%d,", current->data.plays);
		fprintf(output, "%d,", current->data.rating);
		fprintf(output, "\n");

		current = current->next; // go to next song
	}
	printf("\nStored Successfully\n");
	printf("\n"); system("pause"); system("cls");
}

void display(Node* head) {

	Node* current = head;
	int option = 0, numArtist = 1, uniqueCount = 0, exists = 0;
	char* uniqueArtists[100][100];

	system("cls");
	printf("(1) Display All Records\n(2) Display Records by Artist\n\n"); scanf("%d", &option);
	system("cls");

	if (option == 1) {// display all

		while (current != NULL) {

			printf("Artist: %s\n", current->data.artist);
			printf("Album: %s\n", current->data.album);
			printf("Title: %s\n", current->data.title);
			printf("Genre: %s\n", current->data.genre);
			printf("Length: %d:%d\n", current->data.length.minutes, current->data.length.seconds);
			printf("Plays: %d\n", current->data.plays);
			printf("Rating: %d\n\n", current->data.rating);

			current = current->next;
		}

	}
	else {// display artist

		current = head;

		while (current != NULL) {
			// checks if artist is on the list
			for (int i = 0; i < uniqueCount; i++) {
				if (strcmp(uniqueArtists[i], current->data.artist) == 0) {
					exists = 1;
					break;
				}
			}
			// if not add to unique list
			// unique makes sure there is no duplicates displayed to user
			if (!exists) {
				strcpy(uniqueArtists[uniqueCount], current->data.artist);
				uniqueCount++;
			}
			current = current->next;
		}

		// display artist no duplicates
		printf("Select an Artist:\n");
		for (int i = 0; i < uniqueCount; i++) {
			printf("(%d) %s\n", i + 1, uniqueArtists[i]);
		}
		int choice;
		printf("\n");
		scanf("%d", &choice);

		// display records
		system("cls");
		current = head;
		while (current != NULL) {
			if (strcmp(current->data.artist, uniqueArtists[choice - 1]) == 0) {// chosen artist is current node
				printf("Artist: %s\n", current->data.artist);
				printf("Album: %s\n", current->data.album);
				printf("Title: %s\n", current->data.title);
				printf("Genre: %s\n", current->data.genre);
				printf("Length: %d:%d\n", current->data.length.minutes, current->data.length.seconds);
				printf("Plays: %d\n", current->data.plays);
				printf("Rating: %d\n\n", current->data.rating);
			}
			current = current->next;

		}
	}
	printf("\n"); system("pause"); system("cls");
}

void edit(Node* head) { // similar logic from display function

	Node* current = head;
	char uniqueArtists[100][100];
	int uniqueCount = 0;
	int choice = 0, songChoice = 0, exists = 0, songCount = 0;
	Node* songNodes[100];// song selection

	system("cls");

	current = head;

	while (current != NULL) {
		// checks if artist is on the list
		for (int i = 0; i < uniqueCount; i++) {
			if (strcmp(uniqueArtists[i], current->data.artist) == 0) {
				exists = 1;
				break;
			}
		}
		// if not add to unique list
		// unique makes sure there is no duplicates displayed to user
		if (!exists) {
			strcpy(uniqueArtists[uniqueCount], current->data.artist);
			uniqueCount++;
		}
		current = current->next;
	}

	// display artist no duplicates
	printf("Select an Artist to Edit:\n");
	for (int i = 0; i < uniqueCount; i++) {
		printf("(%d) %s\n", i + 1, uniqueArtists[i]);
	}

	scanf("%d", &choice);

	system("cls");
	current = head;

	while (current != NULL) {
		if (strcmp(current->data.artist, uniqueArtists[choice - 1]) == 0) {//song under selected artist
			printf("(%d) %s\n", songCount + 1, current->data.title);
			songNodes[songCount] = current; //index the current song
			songCount++;
		}
		current = current->next;
	}
	printf("\nEnter the number of the song you want to edit: ");
	scanf("%d", &songChoice);
	system("cls");

	//user edit
	Node* selectedSong = songNodes[songChoice - 1];

	printf("Editing: %s by %s\n", selectedSong->data.title, selectedSong->data.artist);

	printf("Enter new Album: ");
	scanf(" %[^\n]", selectedSong->data.album); //[^\n] reads until newline

	printf("Enter new Title: ");
	scanf(" %[^\n]", selectedSong->data.title);

	printf("Enter new Genre: ");
	scanf(" %[^\n]", selectedSong->data.genre);

	printf("Enter new Song Length (minutes): ");
	scanf("%d", &selectedSong->data.length.minutes);

	printf("Enter new Song Length (seconds): ");
	scanf("%d", &selectedSong->data.length.seconds);

	printf("Enter new Play Count: ");
	scanf("%d", &selectedSong->data.plays);

	printf("Enter new Rating (1-5): ");
	scanf("%d", &selectedSong->data.rating);

	printf("\nUpdated Successfully\n");

	printf("\n"); system("pause"); system("cls");
}

void rate(Node* head) {

	Node* current = head;
	char uniqueSong[100][100];
	Node* songNodes[100];
	int uniqueCount = 0;
	int exists = 0, songChoice = 0;

	system("cls");

	// finding unique songs for display
	while (current != NULL) {
		exists = 0;

		// checking for duplicates
		for (int i = 0; i < uniqueCount; i++) {
			if (strcmp(uniqueSong[i], current->data.title) == 0) {
				exists = 1;
				break;
			}
		}

		// if song is unique add to list and use index to allow for user to select the node
		if (!exists) {
			strcpy(uniqueSong[uniqueCount], current->data.title);
			songNodes[uniqueCount] = current; //store node
			uniqueCount++;
		}

		current = current->next;
	}

	// display songs no duplicates
	printf("Select a Song to Rate:\n");
	for (int i = 0; i < uniqueCount; i++) {
		printf("(%d) %s\n", i + 1, uniqueSong[i]);
	}

	scanf("%d", &songChoice);

	system("cls");

	// make selected song the current node
	Node* selectedSong = songNodes[songChoice - 1];

	printf("Rating: %s by %s\n\n", selectedSong->data.title, selectedSong->data.artist);
	printf("Rating (1-5): "); scanf("%d", &selectedSong->data.rating); // changes rating
	printf("\nUpdated Successfully\n\n");
	printf("\n"); system("pause"); system("cls");

}

void play(Node* head) {// similar logic to previous functions

	Node* current = head;
	char uniqueSong[100][100];
	Node* songNodes[100];
	int uniqueCount = 0;
	int exists = 0, songChoice = 0;

	system("cls");

	current = head;

	// finding unique songs for display
	while (current != NULL) {
		exists = 0;

		// checking for duplicates
		for (int i = 0; i < uniqueCount; i++) {
			if (strcmp(uniqueSong[i], current->data.title) == 0) {
				exists = 1;
				break;
			}
		}

		// if song is unique add to list and use index to allow for user to select the node
		if (!exists) {
			strcpy(uniqueSong[uniqueCount], current->data.title);
			songNodes[uniqueCount] = current; //store node
			uniqueCount++;
		}

		current = current->next;
	}

	// display songs no duplicates
	printf("Select a Song to Play:\n");
	for (int i = 0; i < uniqueCount; i++) {
		printf("(%d) %s\n", i + 1, uniqueSong[i]);
	}

	scanf("%d", &songChoice);

	system("cls");

	// make selected song the current node
	Node* selectedSong = songNodes[songChoice - 1];
	current = selectedSong;

	while (current != NULL) {
		printf("Now Playing:\n\n");
		printf("Artist: %s\n", current->data.artist);
		printf("Album: %s\n", current->data.album);
		printf("Title: %s\n", current->data.title);
		printf("Genre: %s\n", current->data.genre);
		printf("Length: %d:%d\n", current->data.length.minutes, current->data.length.seconds);
		printf("Plays: %d\n", current->data.plays);
		printf("Rating: %d\n\n", current->data.rating);

		system("pause");
		system("cls");

		current = current->next;
	}

	//move current to top of list once reached bottom
	current = head;
	while (current != selectedSong) {  // stop before first song
		printf("Now Playing:\n\n");
		printf("Artist: %s\n", current->data.artist);
		printf("Album: %s\n", current->data.album);
		printf("Title: %s\n", current->data.title);
		printf("Genre: %s\n", current->data.genre);
		printf("Length: %d:%02d\n", current->data.length.minutes, current->data.length.seconds);
		printf("Plays: %d\n", current->data.plays);
		printf("Rating: %d\n\n", current->data.rating);

		system("pause");
		system("cls");

		current = current->next;
	}

	printf("End of Playlist\n");
	printf("\n"); system("pause"); system("cls");
}

void insert(Node** head) {

	Record newData = { "" };

	system("cls");

	printf("Enter song details:\n\n");

	printf("Enter Artist: ");
	scanf(" %[^\n]", newData.artist);

	printf("Enter Album: ");
	scanf(" %[^\n]", newData.album); //[^\n] reads until newline

	printf("Enter Title: ");
	scanf(" %[^\n]", newData.title);

	printf("Enter Genre: ");
	scanf(" %[^\n]", newData.genre);

	printf("Enter Song Length (minutes): ");
	scanf("%d", &newData.length.minutes);

	printf("Enter Song Length (seconds): ");
	scanf("%d", &newData.length.seconds);

	printf("Enter Play Count: ");
	scanf("%d", &newData.plays);

	printf("Enter Rating (1-5): ");
	scanf("%d", &newData.rating);



	insert_front(head, newData);

	printf("Successfully Inserted\n\n");

	system("pause"); system("cls");
}

void delete(Node** head) {

	Node* current = *head;
	char uniqueSong[100][100];
	Node* songNodes[100];
	int uniqueCount = 0;
	int exists = 0, songChoice = 0;

	system("cls");

	current = *head;

	// finding unique songs for display
	while (current != NULL) {
		exists = 0;

		// checking for duplicates
		for (int i = 0; i < uniqueCount; i++) {
			if (strcmp(uniqueSong[i], current->data.title) == 0) {
				exists = 1;
				break;
			}
		}

		// if song is unique add to list and use index to allow for user to select the node
		if (!exists) {
			strcpy(uniqueSong[uniqueCount], current->data.title);
			songNodes[uniqueCount] = current; //store node
			uniqueCount++;
		}

		current = current->next;
	}

	// display songs no duplicates
	printf("Select a Song to Delete:\n");
	for (int i = 0; i < uniqueCount; i++) {
		printf("(%d) %s\n", i + 1, uniqueSong[i]);
	}

	scanf("%d", &songChoice);

	system("cls");

	// make selected song the current node
	Node* selectedSong = songNodes[songChoice - 1];
	
	if (selectedSong->prev != NULL) {
		selectedSong->prev->next = selectedSong->next; // take selected song pointers out of list
	}
	else {
		*head = selectedSong->next; 
	}
	if (selectedSong->next != NULL) {
		selectedSong->next->prev = selectedSong->prev; // take selected song pointers out of list
	}
	
	free(selectedSong);
	printf("Successfully Deleted\n\n");
	system("pause"); system("cls");

}

void sort(Node** head) {

	Record newData;
	int sortChoice = 0;
	Node* pCur = *head;
	int swapped = 0;

	system("cls");
	printf("Sort By:\n(1) Artist (A-Z)\n(2) Album (A-Z)\n(3) Rating (1-5)\n(4) Plays (Low-High)\n\n");
	scanf("%d", &sortChoice);

	switch (sortChoice) {
	case 1: // artist
		swapped = 1;
		while (swapped) {
			// reset each loop
			swapped = 0;
			pCur = *head;
			while (pCur != NULL && pCur->next != NULL) {
				// next name is bigger than cur
				if (strcmp(pCur->data.artist, pCur->next->data.artist) > 0) {
					// swap places using temp switch
					newData = pCur->data;
					pCur->data = pCur->next->data;
					pCur->next->data = newData;
					swapped = 1;
				}
				pCur = pCur->next; // next node
			}
		}
		break;
	case 2: // album
		swapped = 1;
		while (swapped) {
			// reset each loop
			swapped = 0;
			pCur = *head;
			while (pCur != NULL && pCur->next != NULL) {
				// next name is bigger than cur
				if (strcmp(pCur->data.album, pCur->next->data.album) > 0) {
					// swap places using temp switch
					newData = pCur->data;
					pCur->data = pCur->next->data;
					pCur->next->data = newData;
					swapped = 1;
				}
				pCur = pCur->next; // next node
			}
		}

		break;
	case 3: // rating

		swapped = 1;
		while (swapped) {
			// reset each loop
			swapped = 0;
			pCur = *head;
			while (pCur != NULL && pCur->next != NULL) {
				// next name is bigger than cur
				if (pCur->data.rating > pCur->next->data.rating) {
					// swap places using temp switch
					newData = pCur->data;
					pCur->data = pCur->next->data;
					pCur->next->data = newData;
					swapped = 1;
				}
				pCur = pCur->next; // next node
			}
		}

		break;
	case 4:// plays

		swapped = 1;
		while (swapped) {
			// reset each loop
			swapped = 0;
			pCur = *head;
			while (pCur != NULL && pCur->next != NULL) {
				// next name is bigger than cur
				if (pCur->data.plays > pCur->next->data.plays) {
					// swap places using temp switch
					newData = pCur->data;
					pCur->data = pCur->next->data;
					pCur->next->data = newData;
					swapped = 1;
				}
				pCur = pCur->next; // next node
			}
		}
		break;
	default:
		printf("\nInvalid Input\n\n");
		system("pause"); system("cls");
		break;
	}
	
	printf("\nSuccessfully Sorted\n\n");  system("pause"); system("cls");
}

void shuffle(Node** head) {
	
	srand((unsigned int)time(NULL));

	int nodeCount = 0;
	Node* pCur = *head;
	Node* target = NULL;
	// find total nodes
	while (pCur->next != NULL) {
		nodeCount++;
		pCur = pCur->next;
	}
	// malloc for node position
	int *pos = malloc(nodeCount * sizeof(int));

	for (int i = 0; i < nodeCount; i++) {
		pos[i] = i;
	}
	// make random node order
	for (int i = nodeCount - 1; i > 0; i--) {
		int j = rand() % (i + 1);
		int temp = pos[i];
		pos[i] = pos[j];
		pos[j] = temp;
	}

	// find target node
	for (int i = 0; i < nodeCount; i++) {
		int song = pos[i];
		//target node in first half
		if (pos < nodeCount / 2) {
			target = *head;
			for (int k = 0; k < song; k++) {
				target = target->next;
			}
		}
		else {// target node in second half
			target = *head;
			while (target->next != NULL) {
				target = target->next;
			}
			for (int k = nodeCount - 1; k > song; k--) {
				target = target->prev; 
			}
		}
		if (target != NULL) {
			system("cls");
			printf("Now Playing at Position %d:\n", song + 1);
			printf("Artist: %s\n", target->data.artist);
			printf("Album: %s\n", target->data.album);
			printf("Title: %s\n", target->data.title);
			printf("Genre: %s\n", target->data.genre);
			printf("Length: %d:%d\n", target->data.length.minutes, target->data.length.seconds);
			printf("Plays: %d\n", target->data.plays);
			printf("Rating: %d\n\n", target->data.rating);

			system("pause");
			system("cls");

		}

	}

}