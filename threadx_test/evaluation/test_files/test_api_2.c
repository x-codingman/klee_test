#include "stdio.h"


#include "test_api.h"

void test_api_2(test_structure_2_t * test_ptr_2);
int main(){
    test_structure_2_t *  test_ptr_2;
    test_api_2(test_ptr_2);
}

void test_api_2(test_structure_2_t * test_ptr_2){
    if(test_ptr_2->a == 0){
        *(test_ptr_2->p)=0;
    }
}