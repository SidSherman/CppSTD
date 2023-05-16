#include "pch.h"
#include <iostream>
#include <time.h>

class Vector {
private:
	int x;
	int y;
	int size;
	int *p;

public:


	Vector(int size_f) {
		size = size_f;
		p = (int *)calloc(size, sizeof(int));
		srand(time(NULL));
		int r;
		for (int i = 0; i < size; i++) {
			r = rand() % 100;
			p[i] = r;
		}
	}

	Vector(int size_f, int first, ...) {
		size = size_f;
		int *tmp;
		tmp = (int *)calloc(size, sizeof(int));
		tmp = &first;
		p = (int *)calloc(size, sizeof(int));
		for (int i = 0; i < size; i++) {
			p[i] = tmp[i];
		}
		
		}

	Vector Set_new(Vector & obj) {

		size = obj.get_vector_size();
		int *tmp = obj.get_vector();
		int count = 0;
		p = (int *)realloc(p,size *sizeof(int));

		for (int i = 0; i < size; i++) {
			if (tmp[i] > 0 && tmp[i] % 2 == 0){
				p[count] = tmp[i];
				count++;
		}
			
		}
		size = count;
		p = (int *)realloc(p, count * sizeof(int));
		return 0;
	}

	int * get_vector()
	{
		return p; 
	}
		
	int get_vector_size()
	{
		return size;
	}
	Vector Message()
	{

		for (int i = 0; i < size; i++) {
			printf("%d ", p[i]);
		}
		printf("\n");
		return 0;
	}


};



int main()
{
	Vector v(10, 3, 4, 3, 5, 3, 3,67,4,3,2);
	v.Message();
	Vector a(3);
	a.Message();
	a.Set_new(v);
	a.Message();
	return 0;
}
