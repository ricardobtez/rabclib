#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"

int main()
{
    LinkedList* ll = create_linked_list(12);
    append_linked_list(ll, 45);
    LinkedList* temporal = NULL;
    temporal = find_linked_list(ll, 45);
    empty_linked_list(ll);
    return 0;
}
