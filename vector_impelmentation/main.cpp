#include <iostream>
#include "vector.hpp"


int main()
{
    My_vector vec(3, 7);
    vec.push_back(10);
    vec.pop_back();
    vec.push_back(3);
    vec.push_back(6);
    vec.push_back(3);
    vec.push_back(1);
    vec.print();
    std::cout<<"capacity - "<<vec.Capacity()<<" size - " << vec.Size()<<std::endl;

	My_vector vec1(vec);

	My_vector vec2;

	vec2 = vec1;

	My_vector vec3(std::move(vec2));

	My_vector vec4;

	vec4 = std::move(vec1);

	vec4.print();
	vec3.print();


    return 0;

}

