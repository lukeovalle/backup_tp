/********
 * FILE array.h
 ********/
#ifndef ARRAY__H
#define ARRAY__H

#include <stdio.h>
#include "types.h"
#include "kml.h"

typedef status_t (*destructor_t)(void *);
typedef status_t (*printer_t)(const void *, FILE *);
typedef struct{
	void ** elements;
	size_t size;
	desctructor_t destructor;
	printer_t printer;
} ADT_Array_t;

/****Prototipos****/
status_t ADT_Array_create(ADT_Array_t ** arr);
status_t ADT_Array_delete(ADT_Array_t ** arr);
status_t ADT_Array_set_destructor(ADT_Array_t * arr, status_t (*destr)(void *));
status_t ADT_Array_set_printer(ADT_Array_t * arr, status_t (*pf)(void *));
status_t ADT_Array_append(ADT_Array_t * arr, const void * value);
status_t ADT_Array_export_to_csv(const ADT_Array_t * arr, char delimiter, FILE * fo);
status_t ADT_Array_export_to_kml(const ADT_Array_t * arr, FILE * fo);

#endif
