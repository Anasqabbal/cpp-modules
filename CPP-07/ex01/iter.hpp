#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *x1, size_t x2, void (*Name)(T &))
{
	if (!x1)
		return ;
	size_t i = 0;
	for (i = 0; i < x2; i++)
		Name(x1[i]);
}

template <typename T>
void iter(T *x1, size_t x2, void (*Name)(const T &))
{
	if (!x1)
		return ;
	size_t i = 0;
	for (i = 0; i < x2; i++)
		Name(x1[i]);
}

#endif