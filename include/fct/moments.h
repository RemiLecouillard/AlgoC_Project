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
  * @file moments.h Contains all the functions manipulating moments.
  * Moments are data about a list of pixels.
  */
#ifndef _MOMENTS_H
#define _MOMENTS_H

/** The structure moments with privates fields. This is always a pointer.
  * Calling a function with it may changes its fields. If you want to keep
  * it as it is you may call copyMoments to create a new instance.
  */
typedef struct moments* Moments;

/** The structure rgb. Basicly a vector.
  */
typedef struct{
  double red;
  double green;
  double blue;
}rgb;

/* Public Functions */

/** Creates Moments for the given list of pixels.
  * @param pixels the list of the pixels
  * @param nbPixels the number of pixels in the list
  * @return moments the moments corresponding to the pixels
  */
Moments createMoments(int pixels[][3],int nbPixels);

/** destroyes the given moments by calling free
  */
void destroyMoments(Moments moments);

/** Merges two moments by summing their components.
  * @param m1 the first moments to merge
  * @param m2 the second moments to merge
  * @return the resulting moments
  */
Moments mergeMoments(Moments m1,Moments m2);

/** Copies moments to create a new one with the same fields.
  * @param moments moments to copy.
  * @return the new instance of the copied moments.
  */
Moments copyMoments(Moments moments);

/** M0 corresponds to the number of pixels in the block
  * @return The field M0
  */
int getM0(Moments moments);

/** M1 corresponds to sum of colors
  * @return The field M1 (always an array of 3 elements for RGB)
  */
rgb getM1(Moments moments);

/** M2 corresponds to sum of colors^2
  * @return The field M2 (always an array of 3 elements for RGB)
  */
rgb getM2(Moments moments);

/* Privates Functions */

static rgb computeM1(int pixels[][3],int nbPixels);

static rgb computeM2(int pixels[][3],int nbPixels);

#endif
