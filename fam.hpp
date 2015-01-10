#ifndef FAM_HPP
#define FAM_HPP

/*link libraries*/
#include<iostream>
#include<string>
class fam{
	public:
		/*constructors*/
		fam();//initialisation constructor
		fam(std::string T,std::string E);
		fam(const fam&);//copying constructor
		~fam();
		bool ends_with(std::string Pq,std::string Pk);
		void match(std::string pattern);
		//operators are not in use(without overloading)
		int** ctf(std::string);//computing transition function for finite automata
		/* suffix and prefix checker */
		bool suffix(std::string P,int q,std::string A);
		std::string pattern;
		std::string text;		
		std::string E;



};

#endif
