#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fms.h"

void print_main(FMS *pFMS);
int right_align(char* var_string, int spaces);

void print_main(FMS *pFMS){
    //int *fms = &pFMS->cntAirline;
    for (int Line_Count = 0; Line_Count < pFMS -> cntAirline; Line_Count++)
    {
        Airline *airline = &pFMS->pAirline[Line_Count];
        Airplane *airplane = airline -> pAirplane;
        right_align(airline -> AirlineName, 10);
        printf("%s|", airline -> AirlineName);
        right_align(airplane -> AirplaneName, 5);
        printf("%s|\n", airplane -> AirplaneName);

    }
};

int right_align(char* var_string, int spaces){
    int length = 0;
    int align = spaces;
    while (*var_string != '\0'){
        length++;
        var_string++;
    }
    int aligner = align - length;
    if (aligner > 0){    
        for (int count = 0; count < aligner; count++){
            printf(" ");
        }
    }
} 

