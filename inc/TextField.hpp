#ifndef TEXTFIELD_HPP
# define TEXTFIELD_HPP

# include <string>
# include <AField.hpp>

class TextField : public AField
{
public:
	TextField();
	TextField(std::string text, unsigned int size);
	~TextField();
	std::string				getText(void) const;
	unsigned int			getSize(void) const;
	void							setText(std::string const text);
	void							setSize(unsigned int const size);
private:
	TextField(TextField const & textfield);
	TextField		& operator=(TextField const & textfield);

	std::string				_text;
	unsigned int			_size;
};

# endif
