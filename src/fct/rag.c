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
  * @file rag.c
  */
#include "fct/region.h"
#include "fct/rag.h"
#include <stdlib.h>
#include <stdio.h>


struct rag {
  Image image;
  int height, width;
  LinkedList blocks;
}
