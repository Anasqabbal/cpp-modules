#include "PmergeMe.hpp"

/*
	parse the arguments;		  		...	
	set the element in the pairs; 		DONE
	sort the elements inside the pairs; DONE
	sort the pairs						...	
	generate JacobsthalSequenece		DONE
	Jacobsthal Insertion with Binary Search
	{
		1- insert the first element in the pend chain
		2- 
		3- use binary search within known comparison bounds
		4- append the extra element by searching in the full current main range
	}
	

*/

// int	ValidArgs(int ac, char **av)
// {
	
// }

int main(int ac, char **av)
{
	if (ac < 2)
		return std::cerr << "Invalid arguments" << std::endl, 1;

	
	PmergeMe vec(av, ac);

	std::string seq = av[1];

	std::vector< std::pair<int, int> > res;

	vec.SortTheElementsOfPairs();
	res = vec.MergeSortAlgo(vec.GetContainer());
	vec.SetContainer(res);
	vec.GenerateChains();
	vec.GenerateInsertionOrder();
	vec.InsertionAndBinarySearch();
	return 0;
}