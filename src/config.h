/************
 * FILE config.h
 ************/
#ifndef CONFIG__H
#define CONFIG__H

#include <stdio.h>
#include "types.h"
#define OUTPUT_STREAM stdout

typedef struct{
	export_format_t export_format;
	FILE * input_file;
	FILE * output_file;
} config_t;

#endif
