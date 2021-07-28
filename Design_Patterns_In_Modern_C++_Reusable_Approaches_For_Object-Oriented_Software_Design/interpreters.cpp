#include<iostream>
#include<ostream>
#include<sstream>
#include<string>
#include<vector>

struct Token
{
	// single token acquired from the expression
	// the token can be  integer plus minus lparen rparen
	//
	enum Type {integer, plus, minus, multiplication, division, lparen, rparen} type;

	std::string text;


	Token( Type type, const std::string & text) :type(type), text(text) {}


	friend std::ostream & operator <<(std::ostream & os, const Token & token)
	{

		os << " ' " << token.text << " ' ";

		return os;
	}
	
};



std::vector<Token> lex(const std::string & input)
{
	std::vector<Token> result;
	
	
	for (int i=0; i<input.size();++i)
	{
			switch(input[i])
			{
				case '+':
					result.push_back(Token {Token::plus, "+"});
					break;

				case '-':

					result.push_back(Token {Token::minus , "-"});

					break;
					


				case '*':
					result.push_back(Token {Token :: multiplication , "*"});


					break;


				case '/':
					result.push_back(Token {Token:: division , "/"});
					break;


				case '(':
					result.push_back(Token {Token:: lparen , "("});

					break;

				case ')':
					result.push_back(Token {Token:: rparen, ")"});

					break;

				default:
					// we will read integer character at a time and parse them

					std::ostringstream buffer;
					buffer<< input[i];
					for(int j=i+1;j<input.size();j++)
					{
						if (isdigit(input[j]))
						{
							buffer<< input[j];
							++i;
						}

						else
						{
							result.push_back(Token {Token::integer, buffer.str()});
							break;
						}
						
					}
					
			}

		}

	

	return result;
}
			


































int main()
{
	std::string input {"(13-4)-(12+1)"};
	// turn it to sequence of tokens and parse
	//
	auto tokens= lex(input);
	for(auto & t:tokens)
	{
		std::cout<<t<<"  " <<std::endl;
	}

	return 0;

}

