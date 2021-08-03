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

LinkedList* create_linked_list()
{
    LinkedList* node = (LinkedList*)(malloc(sizeof(LinkedList)));
    return node;
}

