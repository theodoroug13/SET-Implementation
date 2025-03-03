///////////////////////////////////////////////////////////
//
// Υλοποίηση του set_utils για Sets βασισμένα σε Binary Search Tree.
//
///////////////////////////////////////////////////////////

#include <stdio.h>

#include "set_utils.h"
#include "stdlib.h"


// Χρησιμοποιούμε τη συγκεκριμένη υλοποίηση του UsingBinarySearchTree/ADTSet.c,
// οπότε γνωρίζουμε την ακριβή δομή για την αναπαράσταση των δεδομένων.
// Αντιγράφουμε εδώ τον ορισμό των structs ώστε να μπορούμε να προσπελάσουμε
// τα περιεχόμενά τους.

struct set {
	SetNode root;				// η ρίζα, NULL αν είναι κενό δέντρο
	int size;					// μέγεθος, ώστε η set_size να είναι Ο(1)
	CompareFunc compare;		// η διάταξη
	DestroyFunc destroy_value;	// Συνάρτηση που καταστρέφει ένα στοιχείο του set
};

struct set_node {
	SetNode left, right;		// Παιδιά
	Pointer value;
	int sub_size;   //μέγεθος υποδέντρου
};

//δημιουργία νέου κόμβου
static SetNode node_create(Pointer value) {
	SetNode node = malloc(sizeof(*node));
	node->left = NULL;
	node->right = NULL;
	node->value = value;
	node->sub_size= 1;
	return node;
}

//merge το vec1 και vec2 στο στο vec και επιστροφή του vec
void vector_merge(Vector vec, Vector vec1, Vector vec2, CompareFunc compare) {
    int size1 = vector_size(vec1);
    int size2 = vector_size(vec2);
    
	int i= 0, j= 0;
    while (i< size1 && j< size2) {
        if (compare(vector_get_at(vec1, i), vector_get_at(vec2, j))<0){
            vector_insert_last(vec, vector_get_at(vec1, i));
            i++;
			
        } 
		else{
            vector_insert_last(vec, vector_get_at(vec2, j));
            j++;
        }
    }

    while (i< size1) {
        vector_insert_last(vec, vector_get_at(vec1, i));
        i++;
		
    }
    while (j< size2) {
        vector_insert_last(vec, vector_get_at(vec2, j));
        j++;
		
    }
}

void merge_sort(Vector vec, CompareFunc compare) {
    int size= vector_size(vec);
    if (size <= 1){
		return;
	} 

    Vector vec1 = vector_create(0, NULL);
    Vector vec2 = vector_create(0, NULL);
    for (int i=0; i<size/2; i++){
        vector_insert_last(vec1, vector_get_at(vec, i));
    }
    for (int i = size /2; i<size;i++){
        vector_insert_last(vec2, vector_get_at(vec, i));
    }

    merge_sort(vec1, compare);
    merge_sort(vec2, compare);   
    vector_merge(vec, vec1, vec2, compare);

	vector_destroy(vec1);
	vector_destroy(vec2);

}

//δημιουργία BST από ταξινομημένο vector
SetNode vec_to_BST(Vector vec, int smallest, int biggest){
	if(smallest>biggest){
		return NULL;
	}
	int mid= smallest+ (biggest-smallest)/2;
	Pointer value= vector_get_at(vec, mid);
	SetNode root= node_create(value);
	root->left= vec_to_BST(vec, smallest, mid-1);
	root->right= vec_to_BST(vec, mid+1, biggest);

	return root;

}

Set set_from_vector(Vector vec, CompareFunc compare) {
	Vector sorted= vector_create(0,NULL);
	Vector unsorted= vector_create(0,NULL);

	
	//δημιουργία 2 vector ενα sorted κι ένα unsorted
	vector_insert_last(sorted, vector_get_at(vec,0));
	if(vector_size(vec)>1){
	for(int i=1; i<vector_size(vec); i++){
		
		if(compare(vector_get_at(sorted, vector_size(sorted)-1), vector_get_at(vec, i))<0){
			vector_insert_last(sorted,vector_get_at(vec,i));
		}
		else{
			if(compare(vector_get_at(sorted, vector_size(sorted)-1), vector_get_at(vec, i))!=0){
				vector_insert_last(unsorted,vector_get_at(vec,i));		
			}
		}
	}
	}
	
	//σορτάρουμε το Unsorted με merge sort
	merge_sort(unsorted, compare);
	//κάνουμε merge τα 2 πλέον σορταρισμένα vec
	Vector new_vec= vector_create(0, NULL);
	
	vector_merge(new_vec, sorted, unsorted, compare);

	//φτιάχνουμε το set-BST
	Set set= set_create(compare, NULL);
	set->size= vector_size(new_vec);
	if(vector_size(new_vec)>0){
		set->root= vec_to_BST(new_vec,0, vector_size(new_vec)-1);
	}
	else{
		set->root= NULL;
	}

	vector_destroy(new_vec);
	vector_destroy(sorted);
	vector_destroy(unsorted);
	return set;
}


//In Order Vector Insert
void inorder_vec_insert(Set set, Vector vec, SetNode node){
	Pointer value= NULL;
    if(!node){
        return;
    }
    inorder_vec_insert(set, vec, node->left);
	value= set_node_value(set, node);
    vector_insert_last(vec, value);
    inorder_vec_insert(set, vec, node->right);
}
Vector set_to_vector(Set set) {
	Vector vec= vector_create(0, NULL);
	SetNode node= set->root;
	inorder_vec_insert(set, vec, node);

	return vec;
}

//In Order Traversal Calling f
void inorder_f(Set set, SetNode node, TraverseFunc f){
    Pointer value= NULL;
	if(!node){
        return;
    }
    inorder_f(set, node->left, f);
    value= set_node_value(set, node);
	f(set, value);
    inorder_f(set, node->right, f);
}
void set_traverse(Set set, TraverseFunc f) {
    SetNode node= set->root;
	inorder_f(set, node, f);
}

Set set_merge(Set set1, Set set2, CompareFunc compare) {
	Vector vec1= set_to_vector(set1);
	Vector vec2= set_to_vector(set2);

	Vector new_vec= vector_create(0, NULL);
	vector_merge(new_vec, vec1, vec2, compare);
	Set new_set= set_from_vector(new_vec, compare);

	vector_destroy(vec1);
	vector_destroy(vec2);
	vector_destroy(new_vec);
	
	return new_set;
}

Pointer help_find_k(SetNode node, int k){
	int left;
	if(node->left == NULL){
		left=0;
	}
	else{
    	left = node->left->sub_size;
	}
    if (k == left){
		return node->value;
    }
    else if(k<left){
        return help_find_k(node->left,k);
    }else{
        return help_find_k(node->right,k-left-1);
    }
}


Pointer set_find_k_smallest(Set set, int k) {
	return help_find_k(set->root, k);
}