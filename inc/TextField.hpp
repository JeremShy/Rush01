#ifndef TEXTFIELD_HPP
# define TEXTFIELD_HPP

# include <string>
# include <AField.hpp>

class TextField : public AField
{
public:
	TextField();
	TextField(std::string text, unsigned int size);
	TextField(TextField const & textfield);
	~TextField();
	std::string				getText(void) const;
	unsigned int			getSize(void) const;
	void							setText(std::string const text);
	void							setSize(unsigned int const size);
	std::vector<int>	getFieldSizeForNcurse(void) const;
	std::vector<int>	printFieldForNcurse(int x, int y) const;

private:
	TextField		& operator=(TextField const & textfield);

	std::string				_text;
	unsigned int			_size;
};

# endif
