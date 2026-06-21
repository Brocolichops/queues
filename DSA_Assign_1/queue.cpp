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

bool checkEmpty(struct node* head) {
	return (head == NULL);
}



int main(void) {



	return 0;
}