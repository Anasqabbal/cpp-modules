#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : pi(0)
{
	for (int i = 0; i < 4; i++)
		ptr[i] = NULL;
}
MateriaSource::MateriaSource(const MateriaSource &obj) : Character()
{
	for (int i = 0; i < obj.pi; i++) 
		ptr[i] = obj.ptr[i]->clone();
	pi = obj.pi;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &obj)
{
	if (this == &obj)
		return (*this);
	/*delete the current Materia*/
	for (int i = 0; i < pi; i++)
	{
		delete ptr[i];
		ptr[i] = NULL;
	}
	for (int i = 0; i < obj.pi; i++)
		ptr[i] = obj.ptr[i]->clone();
	pi = obj.pi;
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < pi; i++)
	{
		delete ptr[i];
		ptr[i] = NULL;
	}
}

void    MateriaSource::learnMateria(AMateria* n)
{
	if (pi >= 4)
	{
		delete n;
		n = NULL;
		std::cout << "MateriaSource class can know only 4 Materias" << std::endl;
		return ;
	}
	this->ptr[pi] = n;
	if (pi < 4)
		pi++;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for(int i = 0; i < pi; i++)
	{
		if (ptr[i]->getType() == type)
			return (ptr[i]);
	}
	return (0);
}