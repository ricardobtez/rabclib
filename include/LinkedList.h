/**
 * \file LinkedList.h
 * \brief This file contains the main function for the unit tests
 *
 * \author Ricardo Benitez
 *
 * This file is part of rabclib which is released under MIT Licence.
 * See file LICENSE for full license details.
 **/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct LinkedList
{
    struct LinkedList* next;
    int data;
} LinkedList;

typedef enum
{
    nenError_Ok = 0,
    nenError_InvalidInput,
    nenError_GeneralError,
    nenError_NotFound,
} tenError;

/// \brief
/// Example function
LinkedList* create_linked_list(int data);
tenError append_linked_list(LinkedList* head, int data);
tenError find_linked_list(LinkedList* head, int data, LinkedList* item);
int size_linked_list(LinkedList* head);
tenError delete_linked_list(LinkedList* head, int data);
tenError empty_linked_list(LinkedList* head);


#endif /* LINKEDLIST_H */

