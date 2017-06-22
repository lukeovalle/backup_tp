/********
 * FILE kml.h
 ********/
#ifndef KML__H
#define KML__H

#define XML_TAG_HEADER "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
#define KML_TAG_NAMESPACE_OPEN "<kml xmlns=\"http://www.opengis.net/kml/2.2\">"
#define KML_TAG_NAMESPACE_CLOSE "</kml>"
#define KML_TAG_DOCUMENT_OPEN "<Document>"
#define KML_TAG_DOCUMENT_CLOSE "</Document>"
#define KML_TAG_DOCUMENT_NAME "<name>Rutas</name>"
#define KML_TAG_DOCUMENT_DESCRIPTION "<description>Ejemplos de rutas</description>"
#define KML_TAG_STYLE_OPEN "<Style id=\"yellowLineGreenPoly\">"
#define KML_TAG_STYLE_CLOSE "</Style>"
#define KML_TAG_LINESTYLE "<LineStyle><color>7f00ffff</color><width>4</width></LineStyle>"
#define KML_TAG_POLYSTYLE "<PolyStyle><color>7f00ff00</color></PolyStyle>"
#define KML_TAG_PLACEMARK_OPEN "<Placemark>"
#define KML_TAG_PLACEMARK_CLOSE "</Placemark>"
#define KML_TAG_PLACEMARK_NAME "<name>Relieve absoluto</name>"
#define KML_TAG_PLACEMARK_DESCRIPTION "<description>Pared verde transparente con contornos amarillos</description>"
#define KML_TAG_PLACEMARK_STYLEURL "<styleUrl>#yellowLineGreenPoly</styleUrl>"
#define KML_TAG_LINESTRING_OPEN "<LineString>"
#define KML_TAG_LINESTRING_CLOSE "</LineString>"
#define KML_TAG_LINESTRING_EXTRUDE "<extrude>1</extrude>"
#define KML_TAG_LINESTRING_TESSELLATE "<tessellate>1</tessellate>"
#define KML_TAG_LINESTRING_ALTITUDEMODE "<altitudeMode>absolute</altitudeMode>"
#define KML_TAG_COORDINATES_OPEN "<coordinates>"
#define KML_TAG_COORDINATES_CLOSE "</coordinates>"
#define KML_COORDS_DELIMITER ','

#endif
