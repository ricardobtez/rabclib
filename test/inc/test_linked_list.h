/**
 * \file test_linked_list.h
 * \brief This file contains the test Linked List test cases definition 
 *
 * \author Ricardo Benitez
 *
 * This file is part of rabclib which is released under MIT Licence.
 * See file LICENSE for full license details.
 **/
#ifndef TEST_LINKED_LIST_H
#define TEST_LINKED_LIST_H

#include "test_common.h"

void create_linked_list_small_test(void **state);
void append_linked_list_small_test(void **state);
void find_linked_list_small_test(void **state);
void size_linked_list_small_test(void **state);
void delete_linked_list_small_test(void **state);
void empty_linked_list_small_test(void **state);

#endif /* TEST_LINKED_LIST_H */
