#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

struct List
{
	int value;
	List* next;

	List(int val = 0, List * p = NULL) //êîíñòðóêòîð
	{
		value = val;
		next = p;
	}
};

List* Add_last(int n, List* head)
{
	List* q = new List(n), * p = head;
	// åñëè ñïèñîê ïóñò
	if (head == NULL)
		return q;
	// «èäåì â êîíåö ñïèñêà»
	while (p->next != NULL)
		p = p->next;
	p->next = q;
	return head;
}

List* Enter_List()
{
	List* list = NULL;
	char* input = (char*)calloc(25, sizeof(char));

	fgets(input, 25, stdin);
	input[strlen(input) - 1] = '\0';

	while (input[0] != '\0')
	{
		list = Add_last(atoi(input), list);

		fgets(input, 25, stdin);
		input[strlen(input) - 1] = '\0';
	}

	return list;
}
bool Compare_Lists(List* l1, List* l2) // функция, которая проверяет равенство списков L1 и L2.
{

	if (l1 == NULL && l2 == NULL)
		return 1;

	while (l1->next != NULL && l2->next != NULL && l1->value == l2->value)
	{
		l1 = l1->next;
		l2 = l2->next;
	}
	if ((l1->next == l2->next) && (l1->value == l2->value)) {

		return 1;
	}
	return 0;
}

	int main()
	{
		List* l1, * l2;

		setlocale(LC_ALL, "Russian");

		printf("Ââîä L1:\n");
		l1 = Enter_List();

		printf("Ââîä L2:\n");
		l2 = Enter_List();

		if (Compare_Lists(l1, l2)) {
			printf("ñïèñêè ðàâíû");
		}
		else {
			printf("ñïèñêè íå ðàâíû");
		}
		return 0;

	}
