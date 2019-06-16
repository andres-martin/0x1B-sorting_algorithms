#include "sort.h"
void print_list_rev(const listint_t *list)
{
	int i;


	while(list->next)
		list= list->next;

	i = 0;
	while (list)
	{
		if (i > 0)
			printf(", ");
		printf("%d", list->n);
		++i;
		list = list->prev;
	}
	printf("\n");
}
/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort ailgorithm
 * @list: pointer to the list head
 * Return: no return
 **/
void cocktail_sort_list(listint_t **list)
{
	listint_t *head_tmp2, *aux2;
	int flag = 1;

	if (list)
	{
		head_tmp2 = *list;
		while(flag != 0)
		{
			flag = 0;
			while(head_tmp2->next)
			{
				if (head_tmp2->n > head_tmp2->next->n)
				{

					aux2 = head_tmp2->next;
					if (head_tmp2->prev)
						head_tmp2->prev->next = aux2;
					else
						*list = aux2;
					if (aux2->next)
						aux2->next->prev = head_tmp2;
					head_tmp2->next = aux2->next;
					aux2->prev = head_tmp2->prev;
					aux2->next = head_tmp2;
					head_tmp2->prev = aux2;
					flag = 1;
					print_list(*list);
				}
				else
					head_tmp2 = head_tmp2->next;
			}
			if (flag == 0)
				break;
			flag = 0;
			while(head_tmp2->prev)
			{
				if (head_tmp2->prev->n > head_tmp2->n)
				{
					aux2 = head_tmp2->prev;
					aux2->next->prev = aux2->prev;

					if (aux2->prev)
						aux2->prev->next = aux2->next;
					else
						*list = aux2->next;
					aux2->prev = aux2->next;
					aux2->next = aux2->next->next;
					aux2->prev->next = aux2;
					if (aux2->next)
						aux2->next->prev = aux2;
					flag = 1;
					print_list(*list);
				}
				else
					head_tmp2 = head_tmp2->prev;
			}

		}
	}
}
