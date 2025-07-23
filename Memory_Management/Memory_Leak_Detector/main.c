#include "memory_leak_detector.h"

int main() {
    int * p = (int * )memtrack_malloc(sizeof(int) * 2);
    float * q = (float * )memtrack_malloc(sizeof(int) * 3);
    char * str = (char * )memtrack_malloc(sizeof(char) * 6);

    memtrack_free(p);
    //memtrack_free(q);
    //memtrack_free(str);

    return 0;
}
