/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: pointer to the head of the list
 * @idx: index of the list where the new node should be added
 * @n: integer value to be stored in the new node
 * Return: the address of the new node, or NULL if it failed
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
    dlistint_t *new_node, *current_node;
    unsigned int i = 0;

    if (h == NULL)
        return (NULL);

    new_node = malloc(sizeof(dlistint_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = n;

    if (idx == 0) {
        new_node->prev = NULL;
        new_node->next = *h;
        if (*h != NULL)
            (*h)->prev = new_node;
        *h = new_node;
        return (new_node);
    }

    current_node = *h;
    while (current_node != NULL && i < idx) {
        current_node = current_node->next;
        i++;
    }

    if (current_node == NULL && i == idx) {
        new_node->prev = current_node->prev;
        new_node->next = current_node;
        current_node->prev->next = new_node;
        current_node->prev = new_node;
        return (new_node);
    }

    free(new_node);
    return (NULL);
}
