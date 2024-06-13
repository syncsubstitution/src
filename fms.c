#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fms.h"

void print_main(FMS *pFMS);
void right_align(char* var_string, int spaces);
void Time_align(unsigned char* Hours, unsigned char* Minutes, int spaces);

void print_main(FMS *pFMS){
    //int *fms = &pFMS->cntAirline;
    for (int Line_Count = 0; Line_Count < pFMS -> cntAirline; Line_Count++)
    {
        Airline *airline = &pFMS->pAirline[Line_Count];
        Airplane *airplane = airline -> pAirplane;
        for (int Path_Count = 0; Path_Count < airplane -> cntFlightPath; Path_Count++)
        {   
            FlightPath *flightpath = &airplane ->pFlightPath[Path_Count];
            right_align(airline -> AirlineName,  10);
            //printf("%s|", airline -> AirlineName);
            right_align(airplane -> AirplaneName, 5);
            //printf("%s|\n", airplane -> AirplaneName);
            right_align(flightpath -> pathName,          8);
            right_align(flightpath -> pDepAirport ->iata,7);
            right_align(flightpath -> pArrAirport ->iata,7);
            Time_align(flightpath -> DepTime.Hours, flightpath -> DepTime.Minutes, 7);
            printf("\n");
        };
    }
};

void right_align(char* var_string, int spaces){
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
    printf("%s|", temp);
} 

void Time_align(unsigned char* Hours, unsigned char* Minutes, int spaces)
{
    int length = 0;
    char* tempHours = Hours;
    char* tempMin = Minutes;
    while (*Hours > 0)
    {
        Hours -= 1;
        length++;
    }
    
    printf(" %02u:%02u", *tempHours, *tempMin);
    
}   