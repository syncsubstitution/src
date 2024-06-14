#include <stdio.h>
#include <stdlib.h>
#include "fms.h"

extern FMS fms;
void Generate_Time_Table(FMS *pFMS);
void Generate_Distance_Table(FMS *pFMS);
void Generate_Duration_Table(FMS *pFMS);

int main(){
    Generate_Time_Table(&fms);
    Generate_Duration_Table(&fms);
    Generate_Distance_Table(&fms);
}