#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <utility>

template<typename T>
static void swap(T &val1, T &val2);

template <typename T>
size_t max(T con);


template <class T>
size_t min(T con);

class	PmergeMe
{
	private:
	std::vector<std::pair<int, int> >	con;
	int									RestElem;
	std::vector<int>					JacobSeq;
	std::vector<int>					main;
	std::vector<std::pair<int, int> >	pend;

	public:
	//CCF
	PmergeMe(void);
	~PmergeMe(void);
	PmergeMe(const PmergeMe &obj);
	PmergeMe &operator=(const PmergeMe &obj);

	//O CONSTRUCTOR
	PmergeMe(char **av, int ac);

	//GETERS AND SETERS
	std::vector< std::pair<int, int> >	GetContainer(void);
	void								SetContainer(std::vector< std::pair<int, int> > cn);

	void								SortTheElementsOfPairs(void);
	void								PrintPairs(std::vector<std::pair<int, int> > con);
	void								GenerateJacobSthalSequence(size_t n);
	template <typename T>
	T MergeSortAlgo(T origine);
	template <typename T>
	T InsertionPhase(T right, T left);


	void								PrintJacob(void) ;/*to remove*/
	void								GenerateChains(void);
	void								GenerateInsertionOrder(void);
	size_t								BinarySearch(size_t PendPosition, size_t value);
	void								InsertionAndBinarySearch(void);
	size_t								GetIndexInMain(size_t val);
	size_t								ItsMain(size_t val);
	size_t								GetJacobIndex(size_t i);
	size_t								GetPendInIndex(size_t index);
	void								FindAndRemoveInPend(size_t val);
	void								InsertToMain(size_t index, size_t IndexInPend);
	size_t								ItIsFound(size_t val);
};

template <typename T>
T PmergeMe::InsertionPhase(T left, T right)
{
	bool	modify = 0;

	for (size_t i = 0; i < right.size(); i++)
	{
		for (size_t ii = 0; (ii < left.size()); ii++)
		{
			if (right.size() && (left[ii].first > right[i].first))
			{
				modify = 1;
				left.insert(left.begin() + ii, right[i]);
				right.erase(right.begin() + i);
				ii = -1;
			}
		}
		if (!modify)
		{
			left.push_back(right[i]);
			right.erase(right.begin() + i);
		}
		i = -1;
		modify = 0;
	}
	return left;
}

template <typename T>
T PmergeMe::MergeSortAlgo(T origine)
{
	T left;
	T right;

	if (origine.size() <= 2)
	{		
		if (origine.size() > 1 && (origine[0].first > origine[1].first))
			swap(origine[0], origine[1]);
		return origine;
	}
	for (size_t i = 0; i < origine.size(); i++)
	{
		if (i < (origine.size() / 2))
			left.push_back(origine[i]);
		else
			right.push_back(origine[i]);
	}
	left = MergeSortAlgo(left);				// recursively call the merge sort on the righ side.
	left = InsertionPhase(left, right); 	// after end with the left side call the insertion phase
	origine = left;
	return origine;
}

#endif


