#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <iostream>

class Serializer{
    private:
        Serializer(void);
        Serializer (const Serializer &obj);
    public:
        ~Serializer(void);
        Serializer &operator=(const Serializer &obj);
    };
#endif
