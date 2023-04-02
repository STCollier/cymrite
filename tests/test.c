#include <stdio.h>
#include <cymrite/array.h>

int main(void) {
    struct Array myArray = createArray();

    myArray = arrayAppend(myArray, (void*)'e');

    printf("%s", (char*)myArray.data);

    return 0;
}