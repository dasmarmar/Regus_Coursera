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
 * @file stats.h 
 * @brief This header file contains function prototypes for the C program stats.c.
 *
 * Functions contained in this header file:
 * print_statistics()
 * print_array()
 * find_median()
 * find_mean()
 * find_maximum()
 * find_minimum()
 * sort_array()
 *
 * @author Mario Regus
 * @date   9/26/17
 *
 */

#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief print_statistics() This function prints the statistics of an array. 
 *
 * Function calls printf in stdio.h to print the minimum, maximum, mean, and median values of an array.
 *
 * @param unsigned char min    Minimum value
 * @param unsigned char max    Maximum value
 * @param unsigned char mean   Mean or average value
 * @param unsigned char median The mid value of the array
 *
 * @return void
 */

void print_statistics(unsigned char min, unsigned char max, unsigned char mean, unsigned char median);


/**
 * @brief print_array() Given an array of data and a length, prints the array to the screen
 *
 * Function calls printf in stdio.h
 * 
 * @param unsigned char *ptr  Pointer to an n-element array
 * @param unsigned int length Size of array
 *
 *@return void
 */

void print_array(unsigned char *ptr, unsigned int length);


/**
 * @brief find_median() Given an array of data and a length, returns the median value
 *
 *@param unsigned char *ptr  Pointer to an n-element array
 *@param unsigned int length Size of array
 *
 *@param void
 */

unsigned char find_median(unsigned char *ptr, unsigned int length);


/**
 * @brief find_mean() Given an array of data and a length, returns the mean value
 *
 * @param unsigned char *ptr  Pointer to an n-element array
 * @param unsigned int length Size of array
 *
 * @return unsigned char mean
 */

unsigned char find_mean(unsigned char *ptr, unsigned int length);


/**
 * @brief find_maximum() Given an array of data and a length, return the maximum value
 *
 * @param unsigned char *ptr  Pointer to an n-element array
 * @param unsigned int length Size of array
 *
 * @return unsigned char max
 */

unsigned char find_maximum(unsigned char *ptr, unsigned int length);


/**
 * @brief find_minimum() Given an array of data and a length, returns the minimum value
 *
 * @param unsigned char *ptr  Pointer to an n-element array
 * @param unsigned int length Size of array
 *
 * @return unsigned char min
 */

unsigned char find_minimum(unsigned char *ptr, unsigned int length);


/**
 * @brief sort_array() Given an array of data and a length, sorts the array from largest to smallest.
 *
 * @param unsigned char *ptr  Pointer to an n-element array
 * @param unsigned int length Size of array
 *
 * @return void
 */

void sort_array(unsigned char *ptr, unsigned int length);


/**
 * @brief <Add Brief Description of Function Here>
 *
 * <Add Extended Description Here>
 *
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 *
 * @return <Add Return Informaiton here>
 */


#endif /* __STATS_H__ */
