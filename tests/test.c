#include <stdio.h>
#include "../include/cymrite/array.h"

int main(void) {
    struct Array myArray = createArray();

    myArray = arrayInsert(myArray, 0, "e");

    printf("%c", myArray);

    return 0;
}