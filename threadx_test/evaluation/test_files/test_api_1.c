#include "stdio.h"
#include "test_api.h"

void test_api_1(test_structure_1_t * test_ptr_1);

int main(){
    test_structure_1_t *  test_ptr_1;
    test_api_1(test_ptr_1);
}

void test_api_1(test_structure_1_t * test_ptr_1){
    if(test_ptr_1->a == 0){
        *(test_ptr_1->p)=0;
    }
}