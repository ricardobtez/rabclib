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

tenError find_linked_list(LinkedList* head, int data, LinkedList* item)
{
    tenError enError = nenError_InvalidInput;
    LinkedList* temp = head;

    if (head && NULL == item)
    {
        while (NULL != temp && NULL == item)
        {
            if (temp->data == data)
            {
                item = temp;
                enError = nenError_Ok;
            }
            temp = temp->next;
        }

        if (NULL == item)
        {
            enError = nenError_NotFound;
        }
    }

    return enError;
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
