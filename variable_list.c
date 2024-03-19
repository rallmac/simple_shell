#include "shell.h"

/**
 * add_rvar_node - Adds a new node to the r_var linked list.
 * @head: Pointer to a pointer to the head of the linked list.
 * @lvar: Length of the variable name.
 * @val: Value of the variable.
 * @lval: Length of the variable value.
 * Return: Pointer to the head of the linked list.
 */
r_var *add_rvar_node(r_var **head, int lvar, char *val, int lval)
{
	r_var *new, *temp;

	new = malloc(sizeof(r_var));
	if (new == NULL)
		return (NULL);

	new->len_var = lvar;
	new->val = val;
	new->len_val = lval;

	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}

/**
 * free_rvar_list - Frees the memory allocated
 * for the r_var linked list.
 * @head: Pointer to a pointer to the head of the linked list.
 * Return: None.
 */
void free_rvar_list(r_var **head)
{
	r_var *temp;
	r_var *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}
