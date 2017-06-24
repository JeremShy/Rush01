#ifndef AFIELD_HPP
# define AFIELD_HPP

class AField
{
public:
	AField();
	~AField();
private:
	AField(AField const & afield);
	AField		& operator=(AField const & afield);
};

# endif
