#include <stdlib.h>
/**
 * delete_dnodeint_at_index - deletes the node at index index of a dlistint_t linked list
 * @head: pointer to the head of the list
 * @index: index of the node to delete
 * Return: 1 if it succeeded, -1 if it failed
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current_node, *prev_node;
    unsigned int i = 0;

    if (*head == NULL)
        return (-1);

    current_node = *head;
    if (index == 0) {
        *head = (*head)->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(current_node);
        return (1);
    }

    while (current_node != NULL && i < index) {
        prev_node = current_node;
        current_node = current_node->next;
        i++;
    }

    if (current_node == NULL)
        return (-1);

    prev_node->next = current_node->next;
    if (current_node->next != NULL)
        current_node->next->prev = prev_node;
    free(current_node);

    return (1);
}
