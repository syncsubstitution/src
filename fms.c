#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fms.h"

void print_main(FMS *pFMS);

void print_main(FMS *pFMS){
    int *fms = &pFMS->cntAirline;
    for (int Line_Count = 0; Line_Count < pFMS -> cntAirline; Line_Count++)
    {
        Airline *airline = &pFMS->pAirline[Line_Count];
        int *count = &airline-> pAirplane -> cntFlightPath;
        printf("%s | %d | ", airline -> AirlineName, airline -> cntAirplane);
        printf("%d\n", *count);    
    }
};




