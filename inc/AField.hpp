#ifndef AFIELD_HPP
# define AFIELD_HPP

class AField
{
public:
	AField();
	virtual ~AField();
	AField		& operator=(AField const & afield);
	AField(AField const & afield);
private:
};

# endif
