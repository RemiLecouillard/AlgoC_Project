/*
 * ENSICAEN
 * 6 Boulevard Marechal Juin
 * F-14050 Caen Cedex
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */
/**
  * @file linkedlist.c
  */
#include "list/linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

struct node {
  Region element;
  Node next;
}

struct linkedlist {
  Node first;
  Node last;
  int size;
}

LinkedList createList(Region reg);
