#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<fstream>
#include<boost/lexical_cast.hpp>

struct Journal
{
	std::string title;
	std::vector<std::string> entries;

	Journal( const std::string & title) :title(title){}


	void add_entry(const std::string & entry)
	{
		static int count=1;
		entries.push_back(boost::lexical_cast<std::string>(count++)+ ":" + entry);

	}
};





struct PersistenceManager
{
	static void save(const Journal & j, const std::string & filename)
	{
		std::ofstream ofs(filename);
		for(auto &e :j.entries)
			ofs<<e<<std::endl;
	}
};


int main()
{
	Journal journal {"Dear Diary"};
	journal.add_entry("I ate a bug");
	journal.add_entry("I cried today");
	PersistenceManager pm;
	pm.save(journal, "diary.txt");

}

