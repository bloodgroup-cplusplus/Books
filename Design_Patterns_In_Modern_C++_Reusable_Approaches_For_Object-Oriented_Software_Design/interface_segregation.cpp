#include<iostream>
#include<string>
#include<vector>


struct Document;

/*struct Imachine

{
	virtual void print(Document &doc)=0;
	virtual void scan(Document &doc)=0;
	virtual void fax(Document &doc) =0;
};

struct MFP : Imachine
{
	void print(Document &doc) override
	{


	}

	void scan(Document &doc) override
	{


	}


	void fax(Document &doc) override
	{


	}

};


struct Scanner: I
*/

struct IPrinter
{
	virtual void print(Document &doc)=0;

};

struct IScanner
{
	virtual void scan(Document &doc)=0;
};

struct IFax
{
	virtual void fax(Document &doc)=0;
};

struct Printer :IPrinter
{

};

// both scanning and printing
//
struct IMachine: IPrinter, IScanner {};


struct Machine: IMachine
{
};



struct Scanner:IScanner
{


};
int main()
{
	return 0;
}

