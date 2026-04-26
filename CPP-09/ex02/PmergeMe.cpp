#include "PmergeMe.hpp"

//------- class canonical form
PmergeMe::PmergeMe(void)
{
	RestElem = -1;
}

PmergeMe::~PmergeMe(void)
{	
}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
	(void) obj;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
	return *this;
}

size_t ToInt(const std::string &s)
{
	std::istringstream iss(s);
	size_t in;
	iss >> in;
	return in;
}
//------ another constructor
PmergeMe::PmergeMe(char **av, int ac)
{
	RestElem = -1;
	if ((ac - 1) % 2 == 1)
	{
		RestElem = ToInt(av[ac -1]);
		ac -= 1;
	}
	for (size_t i = 1; (i + 1) < ac; i += 2)
	{
		con.push_back(std::make_pair(ToInt(av[i]), ToInt(av[i + 1])));
	}
}



std::string IntToStr(size_t num)
{
	std::ostringstream oss;

	oss << num;
	return oss.str();
}





void PmergeMe::PrintPairs(std::vector<std::pair<int, int>  > con)
{
	for (size_t i = 0; i < con.size(); i++)
	{
		std::cout << i << ": [" << (con[i]).first << ", ";
		std::cout << (con[i]).second << "]\n";
	}
	std::cout << std::endl;
	if (RestElem >= 0)
		std::cout << "your element: " << RestElem << std::endl;
}



void PmergeMe::SortTheElementsOfPairs(void)
{
	PrintPairs(con);
	int order = 1;
	for (size_t i = 0; i < con.size(); i += order)
	{
		if (con[i].first < con[i].second)
			swap(con[i].first, con[i].second);
	}
	PrintPairs(con);
}

void	PmergeMe::GenerateJacobSthalSequence(size_t n)
{
	JacobSeq.push_back(0);
	JacobSeq.push_back(1);
	for (size_t i = 2; i < (n + 2); i++)
		JacobSeq.push_back(JacobSeq[i - 1] + (2 * JacobSeq[i - 2]));
	JacobSeq.erase(JacobSeq.begin(), JacobSeq.begin() + 3);
}

void PmergeMe::PrintJacob(void)
{
	std::cout << "your jacob sequence: " << std::endl;
	for (size_t i = 0; i < JacobSeq.size(); i++)
	{
		std::cout << JacobSeq[i];
		if (i + 1 != JacobSeq.size())
			std::cout << ",";
	}
	std::cout << std::endl;
}


void		PmergeMe::GenerateChains(void)
{
	bool first = 0;

	size_t i = 0;
	std::vector<std::pair<int, int> > con1 = con;

	while (i < con1.size())
	{
		if (!first)
		{
			main.push_back(con1[i].first);
			pend.push_back(std::make_pair(con1[i].second, i + 1));
			first = 1;
		}
		else
		{
			main.push_back(con1[i].first);
			pend.push_back(std::make_pair(con1[i].second, i + 1));
		}
		i++;
	}
}

size_t	PmergeMe::ItsMain(size_t val)
{
	for (size_t i = 0; i < con.size(); i++)
	{
		if (val == con[i].second)
			return con[i].first;
	}
	return -1;
}


std::vector< std::pair<int, int> >	PmergeMe::GetContainer(void)
{
	return con;
}

void PmergeMe::SetContainer(std::vector< std::pair<int, int> >	cn)
{
	 con = cn;
}

static bool ItIsDuplicate(int x, std::vector<int> v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		if (v[i] == x)
			return 1;
	}
	return 0;
}


size_t PmergeMe::BinarySearch(size_t PendPosition, size_t value)
{
	if (PendPosition == -1)
		return 0;
	size_t PosToSearch = PendPosition / 2;
	size_t range = 0;
	size_t index = 0;

	while ((int)PosToSearch > 0)
	{
		if (value < main[PosToSearch])
			PosToSearch /= 2;
		else if (value < main[PosToSearch + 1])
			return PosToSearch + 1;
		else
			PosToSearch += 1;
	}
	if (value > main[0])
		return 1;
	return 0;
}

size_t PmergeMe::GetJacobIndex(size_t i)
{
	if (i >= JacobSeq.size())
		return (JacobSeq.size() - 1);
	return i ;
}



size_t		PmergeMe::GetPendInIndex(size_t index)
{
	for (size_t i = 0; i < pend.size(); i++)
	{
		if (index == pend[i].second)
			return pend[i].first;
	}

	if (index < min(pend))
		index = min(pend);
	else if (index > max(pend))
		index = max(pend);
	
	return (GetPendInIndex(index));
}



void	PmergeMe::InsertionAndBinarySearch(void)
{
	InsertToMain(0, 1); //push the first element
	size_t i = 0;
	while(pend.size())
	{
		int ii = GetJacobIndex(i);
		int IndexInPend = JacobSeq[ii] - 1;
		size_t PendValue = GetPendInIndex(IndexInPend);
		size_t index = BinarySearch(GetIndexInMain(ItsMain(PendValue)), PendValue);
		InsertToMain(index, IndexInPend);
		i++;
	}
	if (RestElem >= 0)
	{
		for (size_t i = 0; i < main.size(); i++)
		{
			if (RestElem < main[i])
			{
				pend.push_back(std::make_pair(RestElem, 1));
				InsertToMain(i, 1);
				RestElem = INT_MAX;
			}
		}
	}
}

size_t PmergeMe::ItIsFound(size_t val)
{
	for (size_t i = 0; i < pend.size(); i++)
	{
		if (val == pend[i].first)
			return i;
	}
	return -1;
}

void	PmergeMe::InsertToMain(size_t index, size_t IndexInPend)
{
	size_t val = GetPendInIndex(IndexInPend);
	main.insert(main.begin() + index, val);
	pend.erase(pend.begin() + ItIsFound(val));
}

size_t PmergeMe::GetIndexInMain(size_t val)
{
	if (val == -1)
		return  -1;
    for (size_t i = 0; i < main.size(); i++)
    {
        if (main[i] == val)
            return i;
    }
    return -1; 
}


void PmergeMe::GenerateInsertionOrder(void)
{
	GenerateJacobSthalSequence(pend.size());
	std::vector<int> edit;

	int x = 0;
	for (size_t i = 0; i < JacobSeq.size() ; i++)
	{
		edit.push_back(JacobSeq[i]);
		for (x = JacobSeq[i]; x != 1; x--)
		{
			if (edit.size() + 1 == pend.size())
				break ;
			if (!ItIsDuplicate(x, edit))
				edit.push_back(x);
		}
	}
	JacobSeq = edit;
}

template<typename T>
void swap(T &val1, T &val2)
{
	T tmp = val1;
	val1 = val2;
	val2 = tmp;
}

template <typename T>
size_t max(T con)
{
	size_t holder = 0;

	typename T::iterator it = con.begin();

	for (size_t i = 0; it < con.end(); it++)
	{
		if (it->second > holder)
			holder = it->second;
	}
	return holder;
}

template <class T>
size_t min(T con)
{
	size_t holder = INT_MAX;

	typename T::iterator it = con.begin();

	for (size_t i = 0; it < con.end(); it++)
	{
		if (it->second < holder)
			holder = it->second;
	}
	return holder;
}
