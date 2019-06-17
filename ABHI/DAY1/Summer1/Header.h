void executeStringCompression();

void executeReverseLinks();

void executeCloneList();

void executeTransposeMatrix();

void executeSpiralMatrix();

void executeTwoColorSort();

void executeThreeColorSort();

void executeLinkDetection();

void executeLinkedListAddition();

void executeCloneListHash();

struct SingleLinkedList{
	int data;
	struct SingleLinkedList *next;
};

struct linkedListWIthRandom{
	int data;
	struct linkedListWIthRandom *next;
	struct linkedListWIthRandom *random;
};

typedef struct linkedListWIthRandom LLR;

LLR* cloneData(LLR *head);

LLR *createLinkedListRandom(int data);

typedef struct SingleLinkedList SLL;

SLL *linkedListFromArray(int *arr, int arrSize);

SLL* createNode(int data);

SLL* linkedListCreation();

void displayLinkedList(SLL *head);

SLL* getKthNode(int k, SLL *head);

SLL* getLastNode(SLL *head);

int lengthOfLinkedList(SLL *head);