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
  * @file linkedlist.h This file contains all the functions to handle a list
  * and node.
  */
#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

/** This is a pointer to a structure of a node.
  * Every elements of a list is a node.
  * Can be used as an iterator.
  */
typedef struct node* Node;

/** This is a pointer to a structure of a list.
  * The list is indexed from 0 to size - 1.
  */
typedef struct linkedlist* LinkedList;

/** This is an iterator.
  * To go to the first occurence of a list you need
  * to call moveNext one. Then call it for each occurence.
  */
typedef struct iterator* Iterator;

#include "fct/region.h"

/** Creates a LinkedList.
  * @return the created list.
  */
LinkedList createList();

/** Seeks for the Region at the given index
  * The index must be betwen 0 and size-1
  * @param list the list to perform operations
  * @param index the wanted index
  * @return the Region at the given index
  */
Region get(LinkedList list,int index);

/** Deletes the Region at the given index
  * @param list the list to perform operations
  * @param index the wanted index
  */
void deleteIndex(LinkedList list,int index);

/** Returns the index of the first occurence of the given Region
  * @param list the list to perform operations
  * @param reg the wanted region
  * @return the index of the region in the list
  */
int getIndex(LinkedList list,Region reg);

/** Copies a list
  * @param list the list to perform operations
  * @return the copied list
  */
LinkedList copyList(LinkedList list);

/** Deletes the given Region.
  * @param list the list to perform operations
  * @param reg the region to erase from the list
  * @return 1 if the region has been deleted. 0 otherwise.
  */
int deleteRegion(LinkedList list,Region reg);

/** Adds the given Region at the end of the list.
  * @param list the list to perform operations
  * @param reg the region to add
  */
void addRegion(LinkedList list,Region reg);

/**
  * @param list the list to perform operations
  * @return the number of elements in the list
  */
int getSize(LinkedList list);

/** Merges two lists by creating an other one.
  * The old ones are destroyed. You shouldn't use them after.
  * @param l1 the first list to merge
  * @param l2 the second list to merge
  * @return the new list
  */
LinkedList mergeList(LinkedList l1, LinkedList l2);

/** Destroy the giving list by freeing the memory.
  * @param list the list to perform operations
  */
void destroyList(LinkedList list);

/** Returns an object to iterate the list.
  * @param list the list to perform operations
  * @return An iterator of the list
  */
Iterator getIterator(LinkedList list);

/** Moves the iterator to the next Node
  * @param iter the iterator
  * @return 1 if the iter has moved. 0 otherwise.
  */
int moveNext(Iterator iter);

/**
  * @param iter the iterator to perform the operations.
  * @return the Region in where the iterator is pointing.
  */
Region getElement(Iterator iter);

/**
  * Remove all duplicates in a list
  * @param the list where you want to remove duplicates
  */
void removeDuplicates(LinkedList list);

/**
  * @param node the node to perform the operations.
  */
void destroyNode(Node node);

/**
  * @param iter the Iterator to perform the operations.
  */
void destroyIterator(Iterator iter);

#endif
