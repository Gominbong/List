#include"List.h"
#include<stdio.h>
#include<stdlib.h>
Node* Head = (Node*)malloc(sizeof(Node));
Node* Tail = (Node*)malloc(sizeof(Node));
Node* Temp = NULL;
Node* Temp1 = NULL;
void Init() {
	Head->next = Tail;
	Tail->next = NULL;
	Tail->data = NULL;
}
void DelFirst() {
	if (Head->next != Tail) {
		Temp1 = Head->next;
		Head->next = Head->next->next;
		printf("%p\n", Temp1->next);
		printf("%p\n,", Temp1);
		free(Temp1);
		//printf("%p\n", Temp1->next);
		printf("%p\n,", Temp1);
		printf("\n\n�Ǿջ����Ϸ�\n\n\n");
		system("pause");
	}
	else {
		system("cls");
		printf("\n\n");
		puts("�����Ұž���");
		printf("\n\n");
		system("pause");
	}

}
void DelLast() {
	if (Head->next != Tail) {

	}
	else {
		puts("�����Ұž���");
	}
}
void AddBetween() {
	int Number = 0;
	int index = 0;
	int i = 0;

	if (Head->next != Tail) {
		printf("���� �Է� : ");
		scanf_s("%d", &Number);
		printf("������ ��ġ : ");
		scanf_s("%d", &index);
	}
	else {
		printf("\n\n���̿��߰��ҵ����;���\n \n");
		system("pause");
	}

	Node* NewNode = (Node*)malloc(sizeof(Node));
	if (NewNode != NULL) {
		NewNode->data = Number;
		Temp = Head;
		while (Temp->next != Tail) {
			if (index == i) {
				NewNode->next = Temp->next->next;
				Temp->next->next = NewNode;
			}
			Temp = Temp->next;
			i++;
		}
	}

}
void AddFirst() {
	int Number = 0;
	printf("���� �Է� :  ");
	scanf_s("%d", &Number);

	Node* NewNode = (Node*)malloc(sizeof(Node));
	if (NewNode != NULL) {
		NewNode->data = Number;
		Temp = Head->next;
		Head->next = NewNode;
		NewNode->next = Temp;
	}
}
void AddLast() {
	int Number = 0;
	printf("���� �Է� : ");
	scanf_s("%d", &Number);

	Node* NewNode = (Node*)malloc(sizeof(Node));
	if (NewNode != NULL) {
		NewNode->data = Number;
		Temp = Head;
		while (Temp->next != Tail) {
			Temp = Temp->next;
		}
		Temp->next = NewNode;
		NewNode->next = Tail;
	}
}
void Print() {
	if (Head->next == Tail) {
		printf("\n\n�Էµ� ������ ����\n");
	}
	int index = 0;
	Temp = Head;
	while (Temp->next != Tail) {

		printf("%d��index:%d\t", index, Temp->next->data);
		Temp = Temp->next;
		index++;
		if (index % 7 == 0) printf("\n");
	}
}


void Start() {
	Init();
	int n;
	while (1) {
		system("cls");
		puts("����Ʈ");
		puts("1. �߰� ");
		puts("2. ����");
		puts("3. ���");
		puts("4. ���� ");
		printf("��ȣ �Է� : ");
		scanf_s("%d", &n);

		switch (n) {
		case 1:
			system("cls");
			puts("1. �Ǿ��߰�");
			puts("2. ���̿��߰�");
			puts("3. �ǵ��߰�");
			puts("4. ����");
			printf("��ȣ�Է� : ");
			scanf_s("%d", &n);
			switch (n) {
			case 1: AddFirst(); break;
			case 2: AddBetween(); break;
			case 3: AddLast(); break;
			case 4: exit(0);
			default: exit(0);
			}
			break;
		case 2:
			system("cls");
			puts("1. �Ǿջ���");
			puts("2. �ǵڻ���");
			puts("3. �ε������ػ���");
			puts("4. ����");
			printf("��ȣ �Է� : ");
			scanf_s("%d", &n);
			switch (n) {
			case 1: DelFirst(); break;
			case 2:
			case 3:
			case 4: exit(0);
			default: exit(0);
			}

			break;
		case 3:
			system("cls");
			Print();
			printf("\n\n");
			system("pause");
			break;
		case 4:
			exit(0);
		case 5:
			printf("%p\n", Temp1->next);
			system("pause");
			break;
		default:
			exit(0);
		}
	}


}