# DS_Using_c
Data Structures Using C 

It is Data Structure Library Using C.
Theres is so many work which can be easy to do if we will have this library.
For Example.

ArrayUtil=>
       The ArrayUtil contains base, typeSize ,length.
        base which is a pointer to the array
        typeSize,  which is size of one array element
        length, which is how many elements are there.

To use the array you just have to cast the base to the pointer of the respective type: like int* a, float* a ,etc and then a[5] will give you the fifth int or float

int areEqual(ArrayUtil a, ArrayUtil b)
        will compare a with b and return 1 if both are equal, if not it returns 0 

ArrayUtil create(int typeSize, int length) 
        will create an array and wrap it with the ArrayUtil and return it.
        the array contents will all be set to zero or its equivalent value.

ArrayUtil resize(ArrayUtil util, int length) 
        will resize the array and return the modified ArrayUtil. 
        the array contents should be trimmed if new size is less and copied over if the new size is more.
        
       https://github.com/sitaramyadav/DS_Using_c/blob/master/ArrayUtil_1.0/array_util_lib.c