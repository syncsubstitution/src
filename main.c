#include <stdio.h>
#include <stdlib.h>
#include "fms.h"

extern FMS fms;
void print_main(FMS *pFMS);

int main(){
    print_main(&fms);
}