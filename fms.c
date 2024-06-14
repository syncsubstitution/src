#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "fms.h"
#define M_PI 3.14159265358979323846

void Generate_Time_Table(FMS *pFMS);
void Main_Print(char* var_string, int spaces, int bar);
void Time_Print(Time Deptime, Time Arrtime);
void Generate_Distance_Table(FMS *pFMS);
double DistanceCalc(Airport *Departure, Airport *Arrival);
double calculateDegree(double D, double M, double S);
double sinDeg();
double cosDeg();
void Generate_Duration_Table(FMS *pFMS);

void Generate_Time_Table(FMS *pFMS){
    printf("   Airline|Flight No.|from|  to|Departure| Arrival|Airplane\n");
    printf("----------|----------|----|----|---------|--------|--------\n");
    for (int Line_Count = 0; Line_Count < pFMS -> cntAirline; Line_Count++)
    {
        Airline *airline = &pFMS->pAirline[Line_Count];
        Airplane *airplane = airline -> pAirplane;
        for (int Path_Count = 0; Path_Count < airplane -> cntFlightPath; Path_Count++)
        {   
            FlightPath *flightpath = &airplane ->pFlightPath[Path_Count];
            Main_Print(airline -> AirlineName,  10,1);
            Main_Print(flightpath -> pathName,          10,1);
            Main_Print(flightpath -> pDepAirport ->iata,4,1);
            Main_Print(flightpath -> pArrAirport ->iata,4,1);
            Time_Print(flightpath -> DepTime, flightpath ->ArrTime);
            Main_Print(airplane ->AirVehReg, 8,0);
            printf("\n");
        };
    }
};

void Main_Print(char* var_string, int spaces, int bar)
{
    int length = 0;
    char* temp = var_string;
        while (*var_string != '\0'){
            length++;
            var_string++;
        }
        int align = spaces - length;   
        for (int count = 0; count < align; count++){
            printf(" ");            
        }
    printf("%s", temp);
    if (bar == 1)
        {printf("|");}  
} 

void Time_Print(Time Deptime, Time Arrtime){
    printf("    %02u:%02u|   %02u:%02u|", 
    *Deptime.Hours, *Deptime.Minutes, 
    *Arrtime.Hours, *Arrtime.Minutes);
}

void Generate_Distance_Table(FMS *pFMS){
    for (int Line_Count = 0; Line_Count < pFMS -> cntAirline; Line_Count++)
    {
        Airline *airline = &pFMS->pAirline[Line_Count];
        Airplane *airplane = airline -> pAirplane;
        double total = 0;
        printf("\n   Airline|Flight No.|from|  to|Distance\n");
        printf("----------|----------|----|----|--------\n");
        for (int Path_Count = 0; Path_Count < airplane -> cntFlightPath; Path_Count++)
        {   
            FlightPath *flightpath = &airplane ->pFlightPath[Path_Count];
            Main_Print(airline -> AirlineName,  10,1);
            Main_Print(flightpath -> pathName,          10,1);
            Main_Print(flightpath -> pDepAirport ->iata,4,1);
            Main_Print(flightpath -> pArrAirport ->iata,4,1);
            double distance = 0;
            distance = DistanceCalc(flightpath ->pDepAirport, flightpath -> pArrAirport);
            printf("%.2f", distance);
            printf("\n");
            total += distance;
        }
        printf("\nTotal flight distance for %s %s is %.2f\n", airline->AirlineName, airplane -> AirplaneName, total);

    }
    
}

double DistanceCalc(Airport *Departure, Airport *Arrival){
    double deplat = calculateDegree(
        Departure ->pCoordLat.CoordDeg, 
        Departure ->pCoordLat.CoordMin, 
        Departure ->pCoordLat.CoordSec
    );
    double deplon = calculateDegree(
       Departure ->pCoordLon.CoordDeg,
       Departure ->pCoordLon.CoordMin,
       Departure ->pCoordLon.CoordSec
    );
    double arrlat = calculateDegree(
        Arrival ->pCoordLat.CoordDeg, 
        Arrival ->pCoordLat.CoordMin, 
        Arrival ->pCoordLat.CoordSec
    );
    double arrlon = calculateDegree(
       Arrival ->pCoordLon.CoordDeg,
       Arrival ->pCoordLon.CoordMin,
       Arrival ->pCoordLon.CoordSec
    );
    double dist = r * acos(sinDeg(arrlat) * sinDeg(deplat) + 
    cosDeg(arrlat) * cosDeg(deplat) * cosDeg(arrlon - deplon));
    return dist;
}

double calculateDegree(double D, double M, double S){
    double combined = D + (M / 60.0) + (S / 3600.0);
    return combined;
}
double sinDeg(double deg) {
    return sin(deg * M_PI / 180.0);
}
double cosDeg(double deg) {
    return cos(deg * M_PI / 180.0);
}