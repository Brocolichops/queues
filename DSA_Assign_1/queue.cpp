#include <iostream>
#include <ctime>
using namespace std;

//user profile struct
struct User {
	string username; //username member
	int level; // level (1-60) member
	string faction; //faction member
};

//Node struct for queue
struct Node {

	struct User data; //Variable representing a 'User' object
	struct Node* next; //Link to next node in queue
};

//Globally declared node pointers head and tail for the queue
static struct Node* head;
static struct Node* tail;

void initQueue() {
	head = tail = NULL; //Initiating head and tail to NULL
}

bool checkEmpty() {
	return (head == NULL); //Checks if head is null, i.e. if queue is empty
}

//Function to add a new node to queue
void enqueue(struct Node*& head, struct User data) {
	struct Node* newNode = new Node; //Allocates memory for a new node

	newNode->data = data; //Assigns the User object data to the new node's data member

	if (head == NULL) {
		head = tail = newNode; //If queue is empty, assigns the new node to both head and tail
	}
	else {
		tail->next = newNode; //If queue is not empty, makes the current tail point to the new tail
		tail = newNode; //Updates the tail of the queue
	}
	newNode->next = NULL; //Makes the new node point to NULL

}

void dequeue(struct Node*& head) {
	if (checkEmpty()) {
		cout << "No nodes to dequeue!" << endl; //Displays message to user if queue is empty
		return;
	}

	Node* temp = head; //Pointer to current head
	head = head->next; //Updates head to new node
	delete temp; //Free memory
	if (head == NULL) tail = NULL; //Updates tail if the queue is now empty.

	return;
}

int populateQueue(struct Node*& head) {
	cout << "How many users would you like to queue?: " << endl; //Prompts user for input on how many nodes they'd like to add
	int users;
	cin >> users;

	string alphabet = "abcdefghijklmnopqrstuvwxyz1234567890"; //String holding alphabets and numbers


	for (int i = 0; i < users; i++) { //For loop that runs as many times as needed depending on number of users to add
		string username = ""; 
		string faction;
		int level;

		level = (rand() % 60) + 1; //Randomly assigns a number from 1 - 60
		for (int j = 0; j < 10; j++) {
			int randomNum = rand() % 36; //Randomly picks a number between 1 - 36 to pick from the alphabet and numbers.
			username += alphabet[randomNum];
		}

		int randomFaction = rand() % 3; //Generate number between 0-2
		switch (randomFaction) { //Switch to assign faction depending on the number generated.
		case 0:
			faction = "Red";
			break;
		case 1:
			faction = "Blue";
			break;
		case 2:
			faction = "Green";
			break;
		default:
			cout << "Switch failed!" << endl; //Exception handling.
			return 1;
		}
		User user; //Creates user object and assigns all the values
		user.username = username;
		user.level = level;
		user.faction = faction;
		enqueue(head, user); //Queues nodes.
	}
	return 0;

}

int main(void) {

	srand(time(NULL)); //Seeing random number generator
	initQueue(); //Initiating queue
	populateQueue(head); //Calling populate function to create and assign random values to the queue

	while (head != NULL) { //Loop to dequeue and print out all nodes
		cout << "--------------" << endl;
		cout << "Username: " << head->data.username << endl;
		cout << "Faction: " << head->data.faction << endl;
		cout << "Level: " << head->data.level << endl;
		cout << "--------------" << endl;
		dequeue(head);
	}

	return 0;
}