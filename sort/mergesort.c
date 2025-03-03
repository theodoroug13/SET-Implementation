//Για MERGE SORT
void merge(Vector vec, Vector vec1, Vector vec2, CompareFunc compare) {
    int size1 = vector_size(vec1);
    int size2 = vector_size(vec2);
    
	int i= 0, j= 0, k= 0;
    while (i< size1 && j< size2) {
        if (compare(vector_get_at(vec1, i), vector_get_at(vec2, j))<0){
            vector_set_at(vec, k, vector_get_at(vec1, i));
            i++;
        } 
		else{
            vector_set_at(vec, k, vector_get_at(vec2, j));
            j++;
        }
        k++;
    }

    while (i< size1) {
        vector_set_at(vec, k, vector_get_at(vec1, i));
        i++;
        k++;
    }
    while (j< size2) {
        vector_set_at(vec, k, vector_get_at(vec2, j));
        j++;
        k++;
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
    merge(vec, vec1, vec2, compare);

    vector_destroy(vec1);
    vector_destroy(vec2);
}