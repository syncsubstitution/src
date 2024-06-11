#ifndef FMS_H
#define FMS_H
#define r 6378.388 

typedef struct Coordinates
{
    int CoordDeg;
    int CoordMin;
    int CoordSec;
}Coordinates;

typedef struct Time
{
    unsigned char Hours;
    unsigned char Minutes;
}Time;

typedef struct Airport
{
    char icao[5];
    char iata[4];

    Coordinates pCoordLat;
    Coordinates pCoordLon;

    float hAMSL;
}Airport;

typedef struct FlightPath
{
    char pathName[256];
    Airport *pDepAirport;
    Airport *pArrAirport;
    Time DepTime;
    Time ArrTime;
}FlightPath;

typedef struct Airplane
{
    char AirplaneName[256];
    char AirVehReg[256];
    FlightPath *pFlightPath;
    unsigned int cntFlightPath;
}Airplane;

typedef struct Airline
{
    char AirlineName[256];
    Airplane *pAirplane;
    unsigned int cntAirplane;
}Airline;

typedef struct FMS
{
    Airline *pAirline;
    unsigned int cntAirline;
}FMS;

#endif





