#pragma once
#include"Individuum.h"
class CompareIndividuum
{
public:
	bool operator() (Individuum *lhs, Individuum *rhs);
	CompareIndividuum(void);
};

