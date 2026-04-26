#include "MutantStack.hpp"
#include <vector>
#include <iterator>


int main()
{
	std::cout << "The MutantStack of int: " << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);

	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "\n\ntest string string: " << std::endl;
	MutantStack<std::string> sstack;
	sstack.push("hello");
	std::cout << "the size of your stack          : " <<  sstack.size() << std::endl;
	std::cout << "the first element  in your stack: " << *(sstack.begin()) << std::endl;


	std::cout << "\n\ntest container inside the stack:" << std::endl;

	MutantStack< std::vector<int> > StackVec;
	std::cout << "the size of your vectore is :" << StackVec.size() << std::endl;
	std::cout << "create a vectore and push it" << std::endl;

	//create a vectore in c++98 manner;
	std::vector<int> vec;
	vec.push_back(1);

	StackVec.push(vec);
	std::cout << "the size of your vectore is :" << StackVec.size() << std::endl;
	std::cout << (*StackVec.begin()).at(0) << std::endl;


	std::cout << "\n\nThe list Test: " << std::endl;
	std::list<int> mstack1;
	mstack1.push_back(5);
	mstack1.push_back(17);
	std::cout << mstack1.back() << std::endl;
	mstack1.pop_back();
	std::cout << mstack1.size() << std::endl;
	mstack1.push_back(3);
	mstack1.push_back(5);
	mstack1.push_back(737);
	
	//[...]
	mstack1.push_back(0);
	std::list<int>::iterator it1 = mstack1.begin();
	std::list<int>::iterator ite1 = mstack1.end();
	++it1;
	--it1;
	while (it1 != ite1)
	{
		std::cout << *it1 << std::endl;
		++it1;
	}
	std::list<int> s1(mstack1);
	return 0;
}