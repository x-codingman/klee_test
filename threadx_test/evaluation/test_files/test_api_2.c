#include "stdio.h"
#include "stdint.h"

#include "test_api.h"

void test_api_2(test_structure_2_t * test_ptr_2,int b, int c);
int main(){
    test_structure_2_t *  test_ptr_2;
    test_api_2(test_ptr_2);
}

void test_api_2(test_structure_2_t * test_ptr_2, int b, int c){
    if((uint32_t)test_ptr_2 >= ATTACK_CAPABILITY_REGION_END && (uint32_t)test_ptr_2 <= ATTACK_CAPABILITY_REGION_START){
        test_ptr_2->b = b;
        test_ptr_2->c = c;
    }
}