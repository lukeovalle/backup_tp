/************
 * FILE main.c
 ***********/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "config.h"
#include "types.h"
#include "dates.h"
#include "errors.h"
#include "gps_process.h"

/***************Prototipos******************************/
status_t validate_args(int argc, char *argv[], config_t *);
/*******************************************************/


extern config_t config;


int main(int argc, char *argv[]){
    
    status_t st;

    if((st=(validate_args(argc,argv, &config))) != OK){
        print_error_message(st);
        return EXIT_FAILURE;
    } 
    if((st = process_gps_data()) != OK){
        print_error_message(st);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}


/*********************************************************
Función para validar argumentos ingresados por línea 
de comandos. Valida el número de argumentos ingresados
y que sean correctos, luego guarda lo ingresado en
una estructura de configuración.
**********************************************************/
status_t validate_args(int argc, char *argv[], config_t *config){
    size_t i;
    if(argv == NULL || config == NULL)
	return ERROR_NULL_POINTER;
    if(argc != NUMBER_ARGS)
	return ERROR_INVALID_NUMBER_ARGS;
    i = 1;
    while(i < argc){
	if(!strcmp(argv[i], FORMAT_FLAG)){
	    if(!strcmp(argv[i+1], CSV_FORMAT_ARG))
		config->export_format = CSV_FORMAT;
	    else if(!strcmp(argv[i+1], KML_FORMAT_ARG))
		config->export_format = KML_FORMAT;
	    else
		return ERROR_INVALID_ARGS;
	    i += 2;
	}
	else if(!strcmp(argv[i], OUTPUT_FILE_FLAG)){
	    if((config->output_file = fopen(argv[i+1], "wt")) == NULL){
		/**/




}
