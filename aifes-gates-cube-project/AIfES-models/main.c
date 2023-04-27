#include <stdio.h>
#include "test_gates.h"
#include "test_mnist.h"

int main()
{
    printf("Hello AifES!\n");
    printf("Testing gates...\n");
    test_gates();
    printf("Testing MNIST dense model...\n");
    test_mnist();
    printf("End\n");
    return 0;
}
