#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "assert.h"
#include "array_util_lib.h"

int num_of_test = 0;

void ArrayUtil_can_hold_the_char_type(){
	printf("--------\n-->ArrayUtil_can_hold_the_char_type \n");
	ArrayUtil numbers = create(sizeof(char) , 5);

	char *c = (char *)numbers.base;
	c[0] = 4, c[1] = 'B', c[2] = 'C';

	assert(c[0]==4);
	assert(c[1] =='B');
	assert(c[2]=='C');
	assert(c[3] == 0);

	num_of_test++;
}

void ArrayUtil_can_hold_the_int_type(){
	printf("--------\n-->ArrayUtil_can_hold_the_int_type \n");
	ArrayUtil numbers = create(sizeof(int) , 5);

	int *s = (int *)numbers.base;
	s[0] = 92, s[1] = 70, s[2] = 30;

	assert(s[0] == 92);
	assert(s[1] == 70);
	assert(s[2] == 30);
	assert(s[4] == 0);

	num_of_test++;
}

void ArrayUtil_can_hold_the_float_type(){
	printf("--------\n-->ArrayUtil_can_hold_the_float_type \n");
	ArrayUtil numbers = create(sizeof(float) , 10);

	float *f = (float *)numbers.base;
	f[0] = 0.5, f[1] = 0.50, f[2] = 5.0 ,f[3] = 9.0 ,f[4] = 67.0 ,f[5] = 10.50;

	assert(f[0] == 0.5);
	assert(f[1] == 0.50);
	assert(f[2] == 5.0);
	assert(f[3] == 9.0);
	assert(f[4] == 67.0);
	assert(f[5] == 10.50);

	num_of_test++;
}

void ArrayUtil_can_hold_the_double_type(){
	printf("--------\n-->ArrayUtil_can_hold_the_double_type \n");
	ArrayUtil numbers = create(sizeof(double) , 10);

	double *d = (double *)numbers.base;
	d[0] = 0.5, d[1] = 0.50, d[2] = 5.0 ,d[3] = 9.0 ,d[4] = 67.6 ,d[5] = 10.10;

	assert(d[0] == 0.5);
	assert(d[1] == 0.50);
	assert(d[2] == 5.0);
	assert(d[3] == 9.0);
	assert(d[4] == 67.6);
	assert(d[5] == 10.10);

	num_of_test++;
}

void create_can_create_the_array_of_given_typeSize_and_given_length(){
	printf("--------\n-->create_can_create_the_array_of_given_typeSize_and_given_length \n");
	ArrayUtil numbers = create(4 , 8);
	assert(numbers.length == 8);
	assert(numbers.type_size == 4);

	num_of_test++;
}

void resize_can_resize_the_array_with_given_new_size_and_keep_the_old_value_if_new_size_is_greater_then_old(){
	printf("--------\n-->resize_can_resize_the_array_with_given_new_size_and_keep_the_old_value_if_new_size_is_greater_then_old \n");
	ArrayUtil numbers ,numbers_;
	numbers= create(4 , 8);
	float *f = (float *)numbers.base;
	f[0]=2.5;
	f[1]=5.0;
	assert(f[0]==2.5);
	assert(f[1]==5.0);

	assert(numbers.type_size == 4);
	assert(numbers.length == 8);
	
	numbers_ = resize(numbers,16);
	assert(numbers_.type_size == 4);
	assert(numbers_.length == 16);
	f[0]=2.5;
	f[1]=5.0;
	assert(f[0]==2.5);
	assert(f[1]==5.0);
	num_of_test++;
}

void areEqual_can_compare_two_ArrayUtil_whether_they_are_equla_or_not(){
	printf("--------\n-->areEqual_can_compare_two_ArrayUtil_whether_they_are_equla_or_not\n");

	ArrayUtil numbers ,_numbers;
	assert(areEqual(numbers,_numbers)==0);
	num_of_test++;
}
//--------------1.1--------------

void findIndex_can_find_the_index_of_array(){
	printf("--------\n-->findIndex_can_find_the_index_of_array\n");

	ArrayUtil numbers = create(sizeof(int) , 5);

	int *s = (int *)numbers.base;
	s[0] = 92, s[1] = 70, s[2] = 30;
	assert(findIndex(numbers,s)==0);
	assert(findIndex(numbers,&s[1])==1);
	assert(findIndex(numbers,&s[2])==2);
	assert(findIndex(numbers,&s[3])==3);


	num_of_test++;
}

int isEven(void *hint,void *item){
	int num = *(int *)item;
	if(num % 2==0)
		return 1;
	return 0;
}

int isDivisible(void* hint, void* item){
	int _divider  =*(int *)hint;
	int dividend  =*(int *)item;
	if(dividend % _divider==0){
		return 1;
	} else
	return 0;	
}

void findFirst_find_first_element_of_matching_criteria(){
	printf("--------\n-->findFirst_find_first_element_of_criteria.\n");
	ArrayUtil numbers = create(sizeof(int) , 5);
	MatchFunc *_isEven = isEven ,*_isDivisible = isDivisible;
	int *s = (int *)numbers.base;
	s[0] = 92, s[1] = 70, s[2] = 30,s[3]=3,s[4]=5;
	assert(92 == *(int *)findFirst(numbers,_isEven,0));
	num_of_test++;
}

void findLast_find_last_element_of_matching_criteria(){
	printf("--------\n-->findLast_find_last_element_of_matching_criteria.\n");
	ArrayUtil numbers = create(sizeof(int) , 5);
	int *s = (int *)numbers.base;
	s[0] = 92, s[1] = 70, s[2] = 30,s[3]=12,s[4]=9;
	assert(12== *(int *)findLast(numbers,isEven,0));
	
	num_of_test++;
}

void count_can_count_the_no_of_matches(){
	printf("--------\n-->count_can_count_the_no_of_matches.\n");

	ArrayUtil numbers = create(sizeof(int) , 5);
	int *s = (int *)numbers.base;
	s[0] = 92, s[1] = 70, s[2] = 30,s[3]=3,s[4]=5;
	assert(count(numbers,isEven,0)==3);
	num_of_test++;
}

void filter_can_filter_element_from_elements(){
	printf("--------\n-->filter_can_filter_element_from_elements.\n");

	ArrayUtil numbers = create(sizeof(int) , 5);
	ArrayUtil destination = create(sizeof(int),3);
	int *s = (int *)numbers.base;

	s[0] = 9, s[1] = 70, s[2] = 30,s[3]=3,s[4]=5;
	int hint = 3;
	int _hint = 7;
	filter(numbers,isEven,NULL ,&destination.base ,3);
	int *ar = (int *)destination.base;
	assert(ar[0] == 70);
	assert(ar[1] == 30);
	assert(filter(numbers,isEven,NULL ,&destination.base ,3)==2);
	assert(filter(numbers,isDivisible,&hint ,&destination.base ,3)==2);

	num_of_test++;
}

void increment_by_hint(void* hint, void* sourceItem, void* destinationItem){
	int source = *(int *)sourceItem;
	int _hint = *(int *)hint;

	int *destination = (int *)destinationItem;
	*destination = source+_hint;
}

void map_can_maps_source_to_destination_using_the_provided_convert_function(){
	printf("--------\n-->map_can_maps_source_to_destination_using_the_provided_convert_function.\n");

	ArrayUtil source = create(sizeof(int) , 3);
	int *s = (int *)source.base;
	int hint =3; 
	s[0] = 9, s[1] = 70, s[2]=12;
	ArrayUtil destination = create(sizeof(int),3);

	map(source,destination,increment_by_hint,&hint);
	int *array = (int *)destination.base;
	assert(array[0] == 12);
	assert(array[1] == 73);
	assert(array[2] == 15);

	num_of_test++;
}	

void decrement_by_hint(void* hint, void* item){
	int *sa = (int *)item;
	int _hint = *(int *)hint;
	*sa = *sa - _hint;	
}
void forEach_can_do_something_to_destionation_using_the_provided_function(){
	printf("--------\n-->forEach_can_do_something_to_destionation_using_the_provided_function.\n");

	ArrayUtil source = create(sizeof(int) , 3);
	int *s = (int *)source.base;
	int hint =3; 
	s[0] = 9, s[1] = 70, s[2]=12;

	forEach(source,decrement_by_hint,&hint);
	int *array = (int *)source.base;
	assert(array[0] == 6);
	assert(array[1] == 67);
	assert(array[2] == 9);

	num_of_test++;
}

void *sum(void *hint,void *initialValue,void *item){
	*(int *)initialValue = *(int *)initialValue + *(int *)item+*(int *)hint;
	return  initialValue;
}
void reduce_can_reduce_the_array_and_will_return_one_ans(){
	printf("--------\n-->reduce_can_reduce_the_array_and_will_return_one_ans.\n");

	ArrayUtil numbers = create(sizeof(int) , 5);

	int *num = (int *)numbers.base;

	int hint =0;
	int initialValue = 0;
	num[0]=1,num[1]=2,num[2]=3,num[3]=4,num[4]=5;
	assert(*(int *)reduce(numbers,sum,&hint,&initialValue)==15);
	ArrayUtil _numbers = create(sizeof(int) , 5);
	int *_num = (int *)_numbers.base;
	int _hint = 1;
	int _initialValue =1;
	_num[0]=1,_num[1]=2,_num[2]=3,_num[3]=4,_num[4]=5;
	assert(*(int *)reduce(_numbers,sum,&_hint,&_initialValue)==21);

	num_of_test++;
}

int main(void){
	//---------1.0------------------------------------
	create_can_create_the_array_of_given_typeSize_and_given_length();
	resize_can_resize_the_array_with_given_new_size_and_keep_the_old_value_if_new_size_is_greater_then_old();
	ArrayUtil_can_hold_the_char_type();
	ArrayUtil_can_hold_the_int_type();
	ArrayUtil_can_hold_the_float_type();
	ArrayUtil_can_hold_the_double_type();
	areEqual_can_compare_two_ArrayUtil_whether_they_are_equla_or_not();
	
	//-----------1.1----------------------------------
		
	findIndex_can_find_the_index_of_array();	

	//-------------1.2--------------------------------
		//Not need test for 1.2
	//----------------1.3------------------------------	

	findFirst_find_first_element_of_matching_criteria();
	
	//---------------1.4--------

	findLast_find_last_element_of_matching_criteria();

	//-----------------1.5---------------------

	count_can_count_the_no_of_matches();

	//------------------1.6--------------------

	filter_can_filter_element_from_elements();

	//-------------------1.7------------------

	map_can_maps_source_to_destination_using_the_provided_convert_function();

	//-------------------1.8-----------------

	forEach_can_do_something_to_destionation_using_the_provided_function();

	//----------------------1.9--------------------

	reduce_can_reduce_the_array_and_will_return_one_ans();

	printf("%d passed\n",num_of_test);
	return 0;
}
