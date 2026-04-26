#include "iter.hpp"
#include <cstring>

void ToUpper(char &c)
{
		if (c >= 97 && c <= 122)
			c -= 32;
}

void ToUpper(const char &c)
{
  (void)c;
  std::cout << "can't operate on const variable" << std::endl;
  return ;
}

int main( void )
{
  char *arr = new char [5];

  memcpy(arr, "hello", 5);

  std::cout << "before: " << arr << std::endl;
  ::iter(arr, 5, (void (*)(char&))ToUpper);
  std::cout << "before: " << arr << std::endl;
  ::iter(arr, 5, (void (*)(const char&))ToUpper);
	return 0;
}

