
#include "test_linked_list.h"
#include "LinkedList.h"
#include <stdio.h>

void create_linked_list_small_test(void **state)
{
    (void)state;
    LinkedList* new = NULL;
    new = create_linked_list(12);
    assert_non_null(new);
    assert_int_equal(new->data, 12);
    assert_null(new->next);
}

void append_linked_list_small_test(void **state)
{
    (void)state;
    LinkedList* head = create_linked_list(24);
    tenError enError = append_linked_list(head, 45);
    assert_int_equal(nenError_Ok, enError);
}

void find_linked_list_small_test(void **state)
{
    (void)state;
    LinkedList* head = create_linked_list(56);
    LinkedList* temp = NULL;
    temp = find_linked_list(head, 45);
    assert_null(temp);

    temp = NULL;
    tenError enError = append_linked_list(head, 45);
    temp = find_linked_list(head, 45);
    assert_int_equal(nenError_Ok, enError);
    assert_non_null(temp);
}

void size_linked_list_small_test(void **state)
{
    (void)state;
    LinkedList* head = create_linked_list(87);
    assert_int_equal(size_linked_list(head), 1);
    (void)append_linked_list(head, 22);
    assert_int_equal(size_linked_list(head), 2);
    (void)append_linked_list(head, 45);
    assert_int_equal(size_linked_list(head), 3);
}

void delete_linked_list_small_test(void **state)
{
    (void)state;
}

void empty_linked_list_small_test(void **state)
{
    (void)state;
}
