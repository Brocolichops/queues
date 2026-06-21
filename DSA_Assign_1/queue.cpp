#include <iostream>
#include <ctime>
using namespace std;

struct User {
	string username;
	int level;
	string faction;
};

struct Node {

	struct User data;
	struct Node* next;
};

static struct Node* head;
static struct Node* tail;

void initQueue() {
	head = tail = NULL;
}

bool checkEmpty() {
	return (head == NULL);
}

void enqueue(struct Node*& head, struct User data) {
	struct Node* newNode = new Node;

	newNode->data = data;

	if (head == NULL) {
		head = tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}
	newNode->next = NULL;

}

void dequeue(struct Node*& head) {
	if (checkEmpty()) {
		cout << "No nodes to dequeue!" << endl;
		return;
	}

	Node* temp = head;
	head = head->next;
	delete temp;
	if (head == NULL) tail = NULL;

	return;
}

int populateQueue(struct Node*& head) {
	cout << "How many users would you like to queue?: " << endl;
	int users;
	cin >> users;

	string alphabet = "abcdefghijklmnopqrstuvwxyz1234567890";


	for (int i = 0; i < users; i++) {
		string username = "";
		string faction;
		int level;

		level = (rand() % 60) + 1;
		for (int j = 0; j < 10; j++) {
			int randomNum = rand() % 36;
			username += alphabet[randomNum];
		}

		int randomFaction = rand() % 3;
		switch (randomFaction) {
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
			cout << "Switch failed!" << endl;
			return 1;
		}
		User user;
		user.username = username;
		user.level = level;
		user.faction = faction;
		enqueue(head, user);
	}
	return 0;

}

int main(void) {

	srand(time(NULL));
	initQueue();
	populateQueue(head);

	while (head != NULL) {
		cout << "--------------" << endl;
		cout << "Username: " << head->data.username << endl;
		cout << "Faction: " << head->data.faction << endl;
		cout << "Level: " << head->data.level << endl;
		cout << "--------------" << endl;
		dequeue(head);
	}

	return 0;
}