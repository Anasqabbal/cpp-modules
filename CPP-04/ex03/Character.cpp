#include "Character.hpp"

Character::Character(void) : i(0), ofi(0)
{
	for (int ii = 0; ii < 4; ii++)
		mtr[ii] = NULL;
	for (int ii = 0; ii < CH_UNEQUI; ii++)
		on_floor[ii] = NULL;
	for (int ii = 0; ii < 4; ii++)
		mtrs[ii] = -1;
}

Character::Character(const Character &obj)
{
	for (int i = 0; i < this->i; i++)
		mtr[i] = obj.mtr[i]->clone();
	for (int i = 0; i < this->ofi; i++)
		on_floor[i] = obj.on_floor[i]->clone();
	for (int i = 0; i < 4; i++)
		mtrs[i] = obj.mtrs[i];
	this->i = obj.i;
	this->ofi = obj.ofi;
}

Character::~Character(void)
{
	/* delete the current meteria */
	for (int i = 0; i < this->i; i++)
	{
		delete mtr[i];
		mtr[i] = NULL;
	}
	/*delete the current on_floor*/
	for (int i = 0; i < this->ofi; i++)
	{
		if (on_floor[i] != NULL)
			delete on_floor[i];
		on_floor[i] = NULL;
	}
}
Character &Character::operator=(const Character &obj)
{
	if (this == &obj)
		return (*this);
	/* delete the current meteria */
	for (int i = 0; i < this->i; i++)
	{
		if (on_floor[i] != NULL)
			delete on_floor[i];
		delete mtr[i];
		mtr[i] = NULL;
	}
	/*delete the current on_floor*/
	for (int i = 0; i < this->ofi; i++)
	{
		if (on_floor[i] != NULL)
			delete on_floor[i];
		on_floor[i] = NULL;
	}
	for (int i = 0; i < this->i; i++)	/*mtr*/
		mtr[i] = obj.mtr[i]->clone();
	for (int i = 0; i < this->ofi; i++)	/*on_floor*/
		on_floor[i] = obj.on_floor[i]->clone();
	for (int i = 0; i < 4; i++)			/*mtrs*/
		mtrs[i] = obj.mtrs[i];
	this->i = obj.i;
	this->ofi = obj.ofi;
	return (*this);
}

Character::Character(const std::string &name) : i(0), ofi(0)
{
	this->name = name;
	for (int ii = 0; ii < 4; ii++)
		mtr[ii] = NULL;
	for (int ii = 0; ii < CH_UNEQUI; ii++)
		on_floor[ii] = NULL;
	for (int ii = 0; ii < 4; ii++)
		mtrs[ii] = -1;
}

void    Character::equip(AMateria *m)
{
	int equip_in;
	for (equip_in = 0; equip_in < 4; equip_in++)
	{
		if (mtrs[equip_in] == -1)
			break ;
	}
	if (equip_in == 4)
		return ;
	mtr[equip_in] = m->clone();
	mtrs[equip_in] = 1;
	if (i <= 3)
		i++;
}

void Character::unequip(int idx)
{
	if (idx >= 4)
		return ;
	if (ofi == CH_UNEQUI)
	{
		std::cout << "the floor is full clean the floor to unequip more Materia" << std::endl;
		return ;
	}
	on_floor[ofi++] = mtr[idx];
	mtr[idx] = NULL;
	mtrs[idx] = -1;
}

void Character::use(int idx, ICharacter &target)
{
	if (mtr[idx])
		mtr[idx]->use(target);
}

std::string const &Character::getName(void) const
{
	return (name);
}