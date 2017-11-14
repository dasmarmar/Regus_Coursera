/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c 
 * @brief This program prints out the statistics of an n-element array
 *
 * Given an n-element array, this program calculates the maximum, minimum,
 * mean, and median values of the array. Additionaly it sorts the array in
 * descending order from largest to smallest, and prints out the values of
 * the array.
 * 
 *
 *
 * @author Mario Regus
 * @date   9/26/17
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = {34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                              7,  87, 250, 230,  99,   3, 100,  90};

/* Other Variable Declarations Go Here */
 
unsigned char maximum, minimum, mean, median; 
 
/* Statistics and Printing Functions Go Here */
  
void sort_array(unsigned char *ptr, unsigned char length){

unsigned char temp;

for(int i = 0; i < length; i++){

for(int j = i + 1; j < length; j++){
		
if(test[j] >= test[i]){

temp = test[j];
test[j] = test[i];
test[i] = temp;}
}

}

return;

}
  
unsigned char find_max(unsigned char *ptr, unsigned int length){

unsigned char max = test[0];

for(int i = 0; i < SIZE; i++){

if(max >= test[i]){

max = max;
}

else{

max = test[i];
i = 0;
}

}

return max;

}

unsigned find_min(unsigned char *ptr, unsigned int length){

unsigned char min = test[0];

for(int i = 0; i < length; i++){

if(min <= test[i]){

min = min;
}

else{

min = test[i];
i = 0;
}

}

return min;

}

unsigned char find_mean(unsigned char *ptr, unsigned int length){

unsigned int sum = 0;

for(int i = 0; i < length; i++){

sum += test[i];
}

mean = sum / length;

return mean;

}

unsigned char find_median(unsigned char *ptr, unsigned int length){

sort_array(test, length);

unsigned char x, y;

x = test[19];
y = test[20];

median = ( x + y ) / 2;

return median;

}

void print_statistics(unsigned char min, unsigned char max, unsigned char mean, unsigned char median){

printf("\n");

printf("The maximum value is: %3i\n", max);
printf("\n");
printf("The minimum value is: %3i\n", min);
printf("\n");
printf("The mean value is:    %3i\n", mean);
printf("\n");
printf("The median value is:  %3i\n", median);

printf("\n");

return;

}


void print_array(unsigned char *ptr, unsigned int length) {
         
/*printf("\n");
printf("The values in the array are:\n");*/
printf("\n");
printf("Index\tValue\tIndex\tValue\n");
printf("\n");

for (int i = 0; i < length / 2; i++) {
                 
for ( int j = i; j < length; j += 20) { 
	
printf("%3i\t%3i\t", j, test[j]);
}
                 
printf("\n");
}

return;

}


/* Add other Implementation File Code Here */
  
printf("\n");
printf("The unsorted values in the array are:\n");

print_array(test, SIZE);

maximum = find_max(test, SIZE);

minimum = find_min(test, SIZE);

mean = find_mean(test, SIZE);

median = find_median(test, SIZE);

printf("\n");

printf("The Sorted values in the array are: \n");

sort_array(test, SIZE);

print_array(test, SIZE);

print_statistics(minimum, maximum, mean, median);

return;

}

