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
  * @file linkedlist.h
  */
#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H


typedef struct linkedlist* LinkedList;

LinkedList createList(Region reg);

Region get(LinkedList list,int index);

void deleteIndex(LinkedList list,int index);

int getIndex(LinkedList list,Region reg);

void deleteRegion(LinkedList list,Region reg);

int getSize(LinkedList list);

#endif
