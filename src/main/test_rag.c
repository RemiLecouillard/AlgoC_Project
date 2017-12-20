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
 #include <stdlib.h>
 #include <time.h>
 #include "image/image.h"
 #include "list/linkedlist.h"
 #include "fct/region.h"
 #include "fct/rag.h"
 #include "fct/algo.h"

 int main(int argc,char* argv[]){

   if(argc <= 3){

     int x, y;
     image input, output = NULL;
     char* input_name = "img/fille.ppm";
     char* output_name = "img/output.ppm";
     FILE* foutput = NULL;
     Rag rag = NULL;
     Region region, region_neighbour = NULL;
     rgb color;
     int nb_reg;
     int num_reg = 0;
     Iterator iter, iter_neighbour = NULL;
     clock_t start, end;
     double exec_time;

     start = clock();

     input = FAIRE_image();
     image_charger(input, input_name);

     printf("Image %dx%d\n", image_give_largeur(input), image_give_hauteur(input));

     if(argc == 1){
       x = 4;
       y = x;
     }else if(argc == 2){
       x = atoi(argv[1]);
       y = x;
     }else{
       x = atoi(argv[1]);
       y = atoi(argv[2]);
     }

     rag = createRag(input, x, y);

      end = clock();
      exec_time = (double)(end - start) / CLOCKS_PER_SEC;
      printf("Execution time : %f\n", exec_time);
      printf("\n");

     if(rag != NULL){
       iter = getIterator(getBlocks(rag));

       while(moveNext(iter)) {
         region = getElement(iter);
         color = getColor(region);
         printf("Region %p => R:%d G:%d B:%d\n", region, (int)color.red, (int)color.green, (int)color.blue);

         iter_neighbour = getIterator(getNeighbours(region));

         printf("--> neighbours regions : ");

         while(moveNext(iter_neighbour)) {
           region_neighbour = getElement(iter_neighbour);
           nb_reg =  getIndex(getBlocks(rag),region_neighbour);
           printf("%p ", region_neighbour);
         }
         printf("\n");
         num_reg++;
       }

       segmentateRegion(rag, 999999999999.0);

       output = getRegionImage(rag);
       foutput = fopen(output_name, "w+");
       if(foutput != NULL){
         image_to_stream(output, foutput);
         system("sudo emacs img/output.ppm &");
       }else{
         printf("Output file opening failed.\nYou should execute the program with sudo\n");
       }

       DEFAIRE_image(input);

     }else{
       printf("RAG generation failed\n");
    }

   }else{
     printf("Too much arguments\n");
   }


   return 0;

 }
