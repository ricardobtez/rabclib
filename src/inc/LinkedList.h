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

typedef struct
{
    struct LinkedList* next;
    int data;
} LinkedList;

/// \brief
/// Example function
LinkedList* create_linked_list();

#endif /* LINKEDLIST_H */

