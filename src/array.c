#include <stdio.h>
#include "array.h"

status_t ADT_Array_create(ADT_Array_t ** arr){
	if(arr == NULL)
		return ERROR_NULL_POINTER;
	if((*arr = (ADT_Array_t *)malloc(sizeof(ADT_Array_t))) == NULL)
		return ERROR_MEMORY;
	if(((*arr)->elements = (void **)malloc(INIT_ARRAY_CHOP*sizeof(void *))) == NULL){
		free(*arr);
		*arr = NULL;
		return ERROR_MEMORY;
	}
	(*arr)->size = 0;
	(*arr)->destructor = NULL;
	(*arr)->exporter_kml = NULL;
	(*arr)->exporter_csv = NULL;
	return OK;
}
status_t ADT_Array_delete(ADT_Array_t ** arr){
	status_t st;
	size_t i;
	if(arr == NULL)
		return ERROR_NULL_POINTER;
	for(i = 0; i < (*arr)->size; i++){
		if((st = (*((*arr)->destructor))((*arr)->elements[i])) != OK)
			return st;
		(*arr)->elements[i] = NULL;
	}
	free((*arr)->elements);
	(*arr)->elements = NULL;
	free(*arr);
	*arr = NULL;
	return OK;
}
status_t ADT_Array_set_destructor(ADT_Array_t * arr, status_t (*destr)(void *)){
	if(arr == NULL)
		return ERROR_NULL_POINTER;
	arr->destructor = destr;
	return OK;
}
status_t ADT_Array_set_printer(ADT_Array_t * arr, status_t (*pf)(void *)){
	if(arr == NULL)
		return ERROR_NULL_POINTER;
	arr->printer = pf;
	return OK;
}
status_t ADT_Array_append(ADT_Array_t * arr, const void * value){
	void ** aux;
	if(arr == NULL || value == NULL)
		return ERROR_NULL_POINTER;
	if((aux = (void **)realloc(arr->elements, (arr->size + 1)*sizeof(void *))) == NULL)
		return ERROR_MEMORY;
	arr->elements = aux;
	arr->size += 1;
	arr->elements[p->size] = value;
	return OK;
}
status_t ADT_Array_export_to_csv(const ADT_Array_t * arr, char delimiter, FILE * fo){
	if(arr == NULL || fo == NULL)
		return ERROR_NULL_POINTER;
	for(i = 0; i < arr->size; i++)
		(*(arr->printer))(arr->elements[i], delimiter, fo);
	return OK;
}
status_t ADT_Array_export_to_kml(const ADT_Array_t * arr, FILE * fo){
	if(arr == NULL || fo == NULL)
		return ERROR_NULL_POINTER;
	fprintf(fo, "%s\n", XML_TAG_HEADER);
	fprintf(fo, "%s\n", KML_TAG_NAMESPACE_OPEN);
	fprintf(fo, "\t%s\n", KML_TAG_DOCUMENT_OPEN);
	fprintf(fo, "\t\t%s\n", KML_TAG_DOCUMENT_NAME);
	fprintf(fo, "\t\t%s\n", KML_TAG_DOCUMENT_DESCRIPTION);
	fprintf(fo, "\t\t%s\n", KML_TAG_STYLE_OPEN);
	fprintf(fo, "\t\t\t%s\n", KML_TAG_LINESTYLE);
	fprintf(fo, "\t\t\t%s\n"; KML_TAG_POLYSTYLE);
	fprintf(fo, "\t\t%s\n", KML_TAG_STYLE_CLOSE);
	fprintf(fo, "\t\t%s\n", KML_TAG_PLACEMARK_OPEN);
	fprintf(fo, "\t\t\t%s\n", KML_TAG_PLACEMARK_NAME);
	fprintf(fo, "\t\t\t%s\n", KML_TAG_PLACEMARK_DESCRIPTION);
	fprintf(fo, "\t\t\t%s\n", KML_TAG_PLACEMARK_STYLEURL);
	fprintf(fo, "\t\t\t%s\n", KML_TAG_LINESTRING_OPEN);
	fprintf(fo, "\t\t\t\t%s\n", KML_TAG_LINESTRING_EXTRUDE);
	fprintf(fo, "\t\t\t\t%s\n", KML_TAG_LINESTRING_TESSELLATE);
	fprintf(fo, "\t\t\t\t%s\n", KML_TAG_LINESTRING_ALTITUDEMODE);
	fprintf(fo, "\t\t\t\t%s\n", KML_TAG_COORDINATES_OPEN);
	for(i = 0; i < arr->size; i++){
		fprintf(fo, "\t\t\t\t\t");
		(*(arr->printer))(arr->elements[i], KML_COORDS_DELIMITER, fo);
	}	
	fprintf(fo, "\t\t\t\t%s\n", KML_TAG_COORDINATES_CLOSE);
	fprintf(fo, "\t\t\t%s\n", KML_TAG_LINESTRING_CLOSE);
	fprintf(fo, "\t\t%s\n", KML_TAG_PLACEMARK_CLOSE);
	fprintf(fo, "\t%s\n", KML_TAG_DOCUMENT_CLOSE);
	fprintf(fo, "%s\n", KML_TAG_NAMESPACE_CLOSE);
	return OK;
}
