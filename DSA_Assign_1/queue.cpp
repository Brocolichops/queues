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
	if (checkEmpty(head)) {
		cout << "No nodes to dequeue!" << endl;
		return;
	}

	Node* temp = head;
	head = head->next;
	delete temp;
	if (head == NULL) tail = NULL;

	return;
}

int main(void) {



	return 0;
}