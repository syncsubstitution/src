#include "fms.h"
#include <stdio.h>
#include <stdlib.h>


Airport HAM = {
    "EDDH",
    "HAM",
    {53, 37, 49},
    {9, 59, 18},
    16
};
Airport BER = {
    "EDDB",
    "BER",
    {52, 21, 44},
    {13, 30, 2},
    48
};
Airport DUS = {
    "EDDL",
    "DUS",
    {51, 16, 51},
    {7, 8, 34},
    45
};
Airport CGN = {
    "EDDK",
    "CGN",
    {50, 51, 57},
    {7, 8, 34},
    92.0
};
Airport FRA = {
    "EDDF",
    "FRA",
    {50, 1, 59},
    {8, 34, 14},
    111.0
};
Airport STR = {
    "EDDS",
    "STR",
    {48, 41, 24},
    {9, 13, 19},
    389
};
Airport MUC = {
    "EDDM",
    "MUC",
    {48, 21, 14},
    {11, 47, 10},
    453
};

FlightPath FP_LH[] = { 
{"LH 2147", &MUC, &HAM, {11, 30}, {14, 30}},
{"LH 2147", &HAM, &FRA, {15, 30}, {16, 30}},
{"LH 2147", &FRA, &MUC, {18, 30}, {20, 30}},
{"LH 2147", &MUC, &HAM, {20, 45}, {22, 00}},
{"LH 2147", &HAM, &MUC, {22, 30}, {23, 30}},
};
FlightPath FP_EW[] = { 
{"EW 5953", &MUC, &DUS, {3, 0}, {4, 15}},
{"EW 5953", &DUS, &BER, {8, 0}, {10, 0}},
{"EW 5953", &BER, &CGN, {10, 12}, {13, 15}},
{"EW 5953", &CGN, &MUC, {18, 0}, {20, 30}},
{"EW 5953", &MUC, &DUS, {21, 45}, {23, 30}},
};
FlightPath FP_TF[] = {
{"X3 2174", &HAM, &STR, {8, 0}, {10, 0}},
{"X3 2174", &STR, &BER, {10, 15}, {13, 0}},
{"X3 2174", &BER, &FRA, {13, 10}, {15, 0}},
{"X3 2174", &FRA, &HAM, {15, 12}, {17, 0}},
{"X3 2174", &HAM, &FRA, {22, 0}, {24, 0}}
};

Airplane LH = {
    "A380",
    "D-AIMA",
    FP_LH,
    5
};
Airplane EW = {
    "A320",
    "D-AIAB",
    FP_EW,
    5
};
Airplane TF = { 
    "B747",
    "D-ABCD",
    FP_TF,
    5
};

Airline Airlines[] = {
    {"Lufthansa", &LH, 1},
    {"EuroWings", &EW, 1},
    {"TUIFly", &TF, 1}
};

FMS fms = {
    Airlines, 3
};
