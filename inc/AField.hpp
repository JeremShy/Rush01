#ifndef AFIELD_HPP
# define AFIELD_HPP

# include <vector>

class AField
{
public:
	AField();
	virtual ~AField();
	AField		& operator=(AField const & afield);
	AField(AField const & afield);

	virtual std::vector<int> getFieldSizeForNcurse(void) const = 0;
	virtual std::vector<int> printFieldForNcurse(int x, int y) const = 0;

private:
};

# endif
