/* Single responsibility principle.cpp

suppose you decide to keep a jouranal of your most intimate thoughts. The journal has a title
And a number of entries. you could model it as follows:

*/
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<boost/lexical_cast.hpp>
struct Journal
{
    std::string title;
    std::vector<std::string> entries;
    explicit Journal(const std::string & title):title{title}{}
    //Now you could add functionality for adding an entry to the journal,
 // prefixed by the entry's ordinal number in the journal. This is easy:
    void add(const std::string &entry);
    void save(const std::string &filename);
};
  
void Journal::add(const std::string &entry)
{
    static int count=1;
    entries.push_back(boost::lexical_cast<std::string>(count++) +":"+entry);
}

//And now the journal is usable as 
// Now suppose you decide to make the journal persist by saving it in a file/cloud/database.
// You add this code to the journal class:
// You now expand the function as given below

void Journal::save(const std::string & filename)
{
    std::ofstream ofs(filename);
    for(auto &s:entries)
    {
        of<<s<<std::endl;
    }
}

//This approach is problematic. The journal’s responsibility is to keep
//journal entries, not to write them to disk. If you add the disk-writing 
//functionality to Journal and similar classes, any change in the approach 
//to persistence (say, you decide to write to the cloud instead of disk) would 
//require lots of tiny changes in each of the affected classes
// In order to solve this problem we can create a seperate structure 

struct PersistenceManager
{
    static void save(const Journal &j, const std::string & filename);
};

void PersistenceManager::save(const Journal &j, const std::string & filename)
{
    std::ofstream ofs(filename);
    for(auto &s:j.entries)
      ofs<<s<<std::endl;
}
int main()
{
  Journal j{"Dear Diary"};
  j.add("I cried today");
  j.add("I ate a bug");
  PersistenceManager p;
  p.save(j);
  
}
