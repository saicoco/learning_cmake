//
// Created by saicoco on 17-11-27.
//

#include <stdio.h>
#include <stdlib.h>
#include "math_func.h"

double power(double base, int exponent){
    int result = base;
    int i;
    if (exponent == 0) {
        return 1;
    }

    for (i = 0; i < exponent; i++) {
        result = result * base;
    }

    return result;
}


