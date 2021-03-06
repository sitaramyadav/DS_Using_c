#include "array_util_lib.h"
#include "stdlib.h"
#include "assert.h"
#include "string.h"
#include <stdio.h>


ArrayUtil create(int typeSize, int length){
	ArrayUtil array;
	array.base = calloc(typeSize ,length);
	array.type_size  = typeSize;
	array.length = length;
	return array;
}

ArrayUtil resize(ArrayUtil util, int length){
	util.base = realloc(util.base,length);
	util.length = length;
	return util;
}
int areEqual(ArrayUtil a, ArrayUtil b){
	if(a.length!=b.length){return 0;}
	return memcmp(a.base,b.base,a.length*a.type_size) == 0;
}

//------------1.1---------------

int findIndex(ArrayUtil util, void* element){
	for(int i=0;i<util.length;i++){
		if(memcmp(util.base,element,util.type_size)==0){
			return i;			
		}
		util.base += util.type_size;
	}
	return -1;
}
//----------------1.2----------------

void dispose(ArrayUtil util){
	free(util.base);
}


//----------------1.3---------------


void *findFirst(ArrayUtil util, MatchFunc* match, void* hint){
	for(int i= 0;i<util.length-1;i++){
		if(hint !=0 && match(0,util.base)==1)
			return &util.base[i];
		if(match(hint,util.base)==1)
			return &util.base[i];
	}
	return NULL;
}


//---------------1.4------------------------------

void *findLast(ArrayUtil util, MatchFunc* match, void* hint){
	void *lastValue = (void *)NULL;
	for (int i = 0; i < util.length; ++i){
		if(match(hint,util.base) == 1){
			lastValue = util.base;
		}
		util.base += util.type_size;
	}
	return lastValue;
}	
int count(ArrayUtil util, MatchFunc* match, void* hint){
	void *lastValue = (void *)NULL;
	int count = 0;
	for (int i = 0; i < util.length; ++i){
		if(match(hint,util.base) == 1){
			count++;
			lastValue = util.base;
		}
		util.base += util.type_size;
	}
	return count;
}

int filter(ArrayUtil util, MatchFunc* match, void* hint, void** destination, int maxItems ){
	int count = 0;
	void *_destination = *destination;
	for (int i = 0; i < maxItems; ++i){
		if(match(hint,util.base) == 1){
			memcpy(_destination,util.base,util.type_size);
			count++;
			_destination += util.type_size;
		}
		util.base += util.type_size;
	}
	return count;
}

void map(ArrayUtil source, ArrayUtil destination, ConvertFunc* convert, void* hint){
	void *maped = (void *)NULL;
	for(int i=0;i<source.length;i++){
		convert(hint ,source.base,destination.base);
		source.base += source.type_size;
		destination.base +=source.type_size;
	}
}

void forEach(ArrayUtil util, OperationFunc* decrement, void* hint){
	for(int i=0;i<util.length;i++){
		decrement(hint ,util.base);
		util.base += util.type_size;
	}
}

void* reduce(ArrayUtil numbers, ReducerFunc* reducer, void* hint, void* intialValue){
	for(int i = 0;i<numbers.length;i++){
		intialValue =  reducer(hint,intialValue,(numbers.base+i*numbers.type_size));
	}
	return intialValue;
}