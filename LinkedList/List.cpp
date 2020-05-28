#include"List.h"
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
Node* Head = (Node*)malloc(sizeof(Node));
Node* Tail = (Node*)malloc(sizeof(Node));
Node* Temp = NULL;
Node* Temp1 = NULL;
void Init() {
	Head->next = Tail;
	Tail->next = NULL;
	Tail->data = NULL;
}

void DelBetween() {
	int index = 0;
	int i = 0;
	if (Head->next != Tail) {
		printf("������ ��ġ : ");
		scanf_s("%d", &index);
		if (Head->next != Tail) {
			Temp = Head;
			while (Temp->next != Tail) { 
				if (Temp->next->next == Tail) {
					Temp1 = Temp->next;
					Temp->next = Tail;
					printf("\n\n%d�� �ε��� %d   �����Ϸ�\n\n\n", index, Temp1->data);
					system("pause");
					free(Temp1);
					break;
				}
				if (i==index) {
					Temp1 = Temp->next;
					Temp->next = Temp->next->next;
					printf("\n\n%d�� �ε��� %d   �����Ϸ�\n\n\n", index, Temp1->data);
					system("pause");
					free(Temp1);
					break;
				}
				i++;
				Temp = Temp->next;

			}
		}
		else {
			printf("\n\n���̿��߰��ҵ����;���\n\n\n");
			system("pause");
		}
	}
}

void DelFirst() {
	if (Head->next != Tail) {
		Temp1 = Head->next;
		Head->next = Head->next->next;
		free(Temp1);
		printf("\n\n�Ǿջ����Ϸ�\n\n\n");
		system("pause");
	}
	else {
		puts("\n\n�����Ұž���\n\n\n");
		system("pause");
	}

}
void DelLast() {
	
	if (Head->next != Tail) {
		Temp = Head;
		while (1) {
			if (Temp->next->next == Tail) {
				Temp1 = Temp->next;
				Temp->next = Tail;
				free(Temp1);
				puts("\n\n�ǵڻ����Ϸ�\n\n\n");
				system("pause");
				break;
			}
			else {
				Temp = Temp->next;
			}
		}
		
	}else {
		puts("\n\n�����Ұž���\n\n\n");
		system("pause");
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
		printf("\n\n���̿��߰��ҵ����;���\n\n\n");
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
		printf("\n\n%d �߰��Ϸ�\n\n\n", Number);
		printf("\n\n%d �߰��Ϸ�\n\n\n", Number);
		system("pause");
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
		
		printf("\n\n%d �߰��Ϸ�\n\n\n", Number);
		system("pause");
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

		printf("\n\n%d �߰��Ϸ�\n\n\n", Number);
		system("pause");
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
			puts("4. �ڷΰ���");
			puts("5. ����");
			printf("��ȣ�Է� : ");
			scanf_s("%d", &n);
			switch (n) {
			case 1: AddFirst(); break;
			case 2: AddBetween(); break;
			case 3: AddLast(); break;
			case 4: break;
			case 5: exit(0);
			default: printf("\n1~5���� �Է�.\n\n"); system("pause"); continue;
			}
			break;
		case 2:
			system("cls");
			puts("1. �Ǿջ���");
			puts("2. �ǵڻ���");
			puts("3. �ε������ػ���");
			puts("4. �ڷΰ���");
			puts("5. ����");
			printf("��ȣ �Է� : ");
			scanf_s("%d", &n);
			switch (n) {
			case 1: DelFirst(); break;
			case 2: DelLast(); break;
			case 3: DelBetween(); break;
			case 4: break;
			case 5: exit(0);
			default: printf("\n1~5���� �Է�.\n\n"); system("pause"); continue;
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
		default: printf("\n1~5���� �Է�.\n\n"); system("pause"); continue;
		}
	}


}