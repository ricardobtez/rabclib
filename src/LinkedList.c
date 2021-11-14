/**
 * \file example.c
 * \brief This file contains the example function definitions
 *
 * \author Ricardo Benitez
 *
 * This file is part of c_starter_template which is released under MIT Licence.
 * See file LICENSE for full license details.
 **/

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

LinkedList* create_linked_list(int data)
{
    LinkedList* node = (LinkedList*)(malloc(sizeof(LinkedList)));
    node->next = NULL;
    node->data = data;
    return node;
}

tenError append_linked_list(LinkedList* head, int data)
{
    tenError enError = nenError_InvalidInput;
    LinkedList* temp = head;
    LinkedList* new = NULL;

    if (NULL != head)
    {
        while(NULL != temp->next)
        {
            temp = temp->next;
        }
        new = create_linked_list(data);
        temp->next = new;
        enError = nenError_Ok;
    }
    return enError;
}

LinkedList* find_linked_list(LinkedList* head, int data)
{
    LinkedList* temp = head;
    LinkedList* item = NULL;

    if (head && NULL == item)
    {
        while (NULL != temp && NULL == item)
        {
            if (temp->data == data)
            {
                item = temp;
                break;
            }
            temp = temp->next;
        }
    }

    return item;
}

int size_linked_list(LinkedList* head)
{
    int size = 0;

    while (head)
    {
        size++;
        head = head->next;
    }

    return size;
}

tenError delete_linked_list(LinkedList* head, int data)
{
    tenError enError = nenError_InvalidInput;
    LinkedList* found = NULL;
    found = find_linked_list(head, data);

    if (found)
        free(found);

    return enError;
}

tenError empty_linked_list(LinkedList* head)
{
    tenError enError = nenError_Ok;
    LinkedList* temp;

    while(head)
    {
        temp = head->next;
        free(head);
        head = temp;
    }
    return enError;
}
