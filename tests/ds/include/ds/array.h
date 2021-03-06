/*
 * The MIT License (MIT)
 * Copyright (c) 2015 Peter Vanusanik <admin@en-circle.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy 
 * of this software and associated documentation files (the "Software"), to deal in 
 * the Software without restriction, including without limitation the rights to use, copy, 
 * modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, 
 * and to permit persons to whom the Software is furnished to do so, subject to the 
 * following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies 
 * or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS 
 * OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, 
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN 
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * array.h
 *  Created on: Dec 24, 2015
 *      Author: Peter Vanusanik
 *  Contents: array implementation
 */

#pragma once

#include "_commons.h"
#include "funcops.h"
#include "random.h"

#ifdef __cplusplus
extern "C" {
#endif

/** Number of elements in starting size */
#define ARRAY_STARTING_SIZE 32

/****************************************//**
 * Array structure
 ********************************************/
typedef struct array {
	/** Contains the data array containing elements */
    void**   data;
    /** Number of elements in the array */
    uint32_t size;
    /** Number of available data elements */
    uint32_t data_size;
    /** Statring size */
    uint32_t starting_size;
} array_t;

array_t* create_array();
array_t* create_array_spec(uint32_t starting_element_size);
uint32_t array_push_data(array_t* array, void* data);
int32_t array_find_data(array_t* array, void* data);
void array_insert_at(array_t* array, uint32_t pos, void* data);
void* array_get_at(array_t* array, uint32_t position);
void array_set_at(array_t* array, uint32_t position, void* data);
void array_remove_at(array_t* array, uint32_t position);
uint32_t array_get_size(array_t* array);
void destroy_array(array_t* array);
void* array_find_by_pred(array_t* array, search_predicate_t predicate, void* data);
void* array_get_random(array_t* array, rg_t* rg);
void array_clean(array_t* array);

#ifdef __cplusplus
}
#endif
