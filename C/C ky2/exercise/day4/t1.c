#include <stdio.h>

int main() {
    char c;
    char* pc;
    
    int a;
    int* pa;
    
    pc = &c;  // Good and valid
    pa = &a;  // Good and valid
    
    pc = &a;  // Error: Different types
    pa = &a;  // Error: Different levels
    

    return 0;
}
