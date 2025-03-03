//////////////////////////////////////////////////////////////////
//
// Unit tests για το set_utils.
// Οποιαδήποτε υλοποίηση οφείλει να περνάει όλα τα tests.
//
//////////////////////////////////////////////////////////////////
#include <stdlib.h>
#include "acutest.h"			// Απλή βιβλιοθήκη για unit testing

#include "set_utils.h"

int compare_ints(Pointer a, Pointer b) {
	return *(int*)a - *(int*)b;
}

int* create_int(int value) {
	int* p = malloc(sizeof(int));
	*p = value;
	return p;
}

//χρήση στην test_set_traverse
int sum=0; 
void sum_of_nodes( Set set, Pointer val){
	sum+= *(int *)val;
}

void test_set_from_vector(void) {

    Vector values = vector_create(0, free);
    vector_insert_last(values, create_int(1));
    vector_insert_last(values, create_int(0));
    vector_insert_last(values, create_int(2));
    vector_insert_last(values, create_int(3));
    vector_insert_last(values, create_int(5));

    Set set= set_from_vector(values, compare_ints);
    
    TEST_ASSERT(set != NULL);
    TEST_ASSERT(set_size(set) == 5);

    TEST_ASSERT(*(int *)set_node_value(set, set_first(set)) == 0);
    TEST_ASSERT(*(int *)set_node_value(set, set_last(set)) == 5);

    set_destroy(set);
    vector_destroy(values);

}


void test_set_to_vector(void) {
	Set set= set_create(compare_ints, free);
	set_insert(set, create_int(1));
	set_insert(set, create_int(0));
	set_insert(set, create_int(2));
	set_insert(set, create_int(3));

	Vector vec= set_to_vector(set);
	TEST_ASSERT(vec != NULL);
	TEST_ASSERT(vector_size(vec) == 4);
	TEST_ASSERT(*(int *)vector_get_at(vec, 0) == 0);
	TEST_ASSERT(*(int *)vector_get_at(vec, 3) == 3);
	
	
	set_destroy(set);
	vector_destroy(vec);

}

void test_set_traverse(void) {
	Set set= set_create(compare_ints, free);
	set_insert(set, create_int(1));
	set_insert(set, create_int(0));
	set_insert(set, create_int(2));
	set_insert(set, create_int(3));

	set_traverse(set, sum_of_nodes);
	TEST_ASSERT(sum = 6);

	set_destroy(set);
}

void test_set_merge(void) {
	Set set1= set_create(compare_ints, free);
	set_insert(set1, create_int(1));
	set_insert(set1, create_int(0));
	set_insert(set1, create_int(2));
	set_insert(set1, create_int(3));

	Set set2= set_create(compare_ints, free);
	set_insert(set2, create_int(1)); //κοινό στοιχείο
	set_insert(set2, create_int(4));
	set_insert(set2, create_int(6));
	set_insert(set2, create_int(10));
	set_insert(set2, create_int(5));

	Set merge= set_merge(set1, set2, compare_ints);

	TEST_ASSERT(merge != NULL);
	TEST_ASSERT(set_size(merge) == 8);
	TEST_ASSERT(*(int *)set_node_value(merge, set_first(merge)) == 0);
	TEST_ASSERT(*(int *)set_node_value(merge, set_last(merge)) == 10);
	
	set_destroy(set1);
	set_destroy(set2);
	set_destroy(merge);

}

void test_set_find_k_smallest(void) {
	Set set= set_create(compare_ints, free);
	set_insert(set, create_int(12));
	set_insert(set, create_int(43));
	set_insert(set, create_int(155));
	set_insert(set, create_int(81));

	Pointer res1= set_find_k_smallest(set,0);
	Pointer res2= set_find_k_smallest(set,1);
	Pointer res3= set_find_k_smallest(set,2);
	Pointer res4= set_find_k_smallest(set,3);
	TEST_ASSERT(*(int *)res1 == 12);
	TEST_ASSERT(*(int *)res2 == 43);
	TEST_ASSERT(*(int *)res3 == 81);
	TEST_ASSERT(*(int *)res4 == 155);

	set_destroy(set);
}


// Λίστα με όλα τα tests προς εκτέλεση
TEST_LIST = {
	{ "test_set_import_from_vector",	test_set_from_vector },
	{ "test_set_export_to_vector",		test_set_to_vector },
	{ "test_set_traverse",				test_set_traverse },
	{ "test_set_merge",					test_set_merge },
	{ "test_set_find_k_smallest",		test_set_find_k_smallest },

	{ NULL, NULL } // τερματίζουμε τη λίστα με NULL
}; 
