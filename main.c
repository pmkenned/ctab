#include <stdio.h>

#include "ctab.h"

/* this file is a demonstration of the ctab library */

int main() {

    int array0[10];
    int array1[10];
    int array2[10];

    const int rs = sizeof(array0)/sizeof(*array0);

    const char * headers[] = {
        "Name",
        "V0",
        "V1",
        "V2"
    };

    const char * names[] = {
        "first",
        "second",
        "third",
        "fourth",
        "fifth",
        "sixth",
        "seventh",
        "eighth",
        "nineth",
        "tenth"
    };

    const char ** u;

    int sizes[] = {100,10000};
    int i;
    for(i=0; i<rs; i++) {
        array0[i] = rand()/(RAND_MAX/sizes[rand()/(RAND_MAX/2)]);
        array1[i] = rand()/(RAND_MAX/sizes[rand()/(RAND_MAX/2)]);
        array2[i] = rand()/(RAND_MAX/sizes[rand()/(RAND_MAX/2)]);
    }

    u = contab(rs, headers, "siii",names,array0,array1,array2);

    printt(u,rs+1,4);

    return 0;
}
