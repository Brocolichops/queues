#include <iostream>

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

bool checkEmpty(struct Node* head) {
	return (head == NULL);
}

void enqueue(struct Node* head, struct User data) {
	struct Node* newNode = (Node*)malloc(sizeof(struct Node));

	if (newNode == NULL) {
		cout << "Memory allocation failed" << endl;
		return;
	}

	newNode->data = data;

	if (head == NULL) {
		head = newNode;
	}
	newNode->next = NULL;
	tail->next = newNode;
	tail = newNode;
}

int main(void) {



	return 0;
}