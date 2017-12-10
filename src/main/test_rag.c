/*
 * ENSICAEN
 * 6 Boulevard Marechal Juin
 * F-14050 Caen Cedex
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */
 #include <stdio.h>
 #include "image/image.h"
 #include "list/linkedlist.h"
 #include "fct/region.h"
 #include "fct/rag.h"

 int main(int argc,char* argv[])
 {

   image img=FAIRE_image();

   char* file = "/home/julien/Documents/Cours/ProgC/ProjetC/fille.ppm";
   image_charger(img,file);

   printf("Image %dx%d with %d dim\n", image_give_largeur(img), image_give_hauteur(img), image_give_dim(img));

   Rag rag = createRag(img, 256, 256);
   Node iter = getIterator(getBlocks(rag));
   Region region = NULL;
   Region region2 = NULL;
   rgb color;
   Node next = iter;
   int nb_reg;
   int num_reg = 1;

   while(hasNext(iter)) {
     iter = next;
     next = getNext(iter);
     region = getElement(iter);
     color = getColor(region);
     printf("Bloc %d => R:%d G:%d B:%d", num_reg, (int)color.red, (int)color.green, (int)color.blue);

     Node iter2 = getIterator(getNeighbourgs(region));
     Node next2 = iter2;
     while(hasNext(iter2)) {
       iter2 = next2;
       next2 = getNext(iter2);
       region2 = getElement(iter2);
       nb_reg =  getIndex(getNeighbourgs(region),region2);
       printf(" / %d ", nb_reg);
     }

     printf("\n");
     num_reg++;
   }

   DEFAIRE_image(img);
   return 0;
 }
