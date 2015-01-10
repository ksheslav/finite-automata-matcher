#include"fam.hpp"
#include<sstream>
#include<algorithm>
#include<sstream>
fam::~fam(){ }

fam::fam(){ }

fam::fam(std::string T,std::string E){
	this->text=T;
	this->E=E;
}

fam::fam(const fam& fam){
	this->text=fam.text;
}
void fam::match(std::string pattern){
	//std::cout<<"match"<<std::endl;
	int n = this->text.length();
	int q = 0;
	
	int** delta = ctf(pattern);
	
	for(int i=1;i<=n;i++){

		q=delta[q][static_cast<int>(this->text[i-1])];
		if(q==static_cast<int>(pattern.length())){
			std::cout<<"pattern has been found at: "<<i-static_cast<int>(pattern.length())<<std::endl;
		}
	}	
}

int** fam::ctf(std::string pattern){

	int** delta=new int*[pattern.length()];	

	for(int i=0;i<=(int)this->text.length();++i)
		delta[i]=new int[256];

	for(int q=0;q<=static_cast<int>(pattern.length());++q){
		int k;
		for(std::string::iterator it = E.begin(); it!=E.end();++it){
			std::stringstream ss;
			std::string s;
			ss<<*it;
			ss>>s;
			k = std::min(static_cast<int>(pattern.length())+1,q+2);

			do{
				k--;
			}while(!this->ends_with(pattern.substr(0,q)+s,pattern.substr(0,k)));

			delta[q][static_cast<int>(*it)]=k;
		}
	}	


	return delta;
}



bool fam::ends_with(std::string Pq,std::string Pk){

	if(Pq.length()>=Pk.length()){
			//std::cout<<std::endl<<Pq<<"=="<<Pk<<"=>";
		return(0==Pq.compare(Pq.length()-Pk.length(),Pk.length(),Pk));
	}else{
		return false;
	}	
		
}

int main(int argcv, char** argv){
	fam fam("aaaaa","a");	
	fam.match("aaa");
	//fam fam2("abcabccabc","abc");	
	//fam2.match("abc");

	//fam fam3("ababababd","abcd");	
	//fam3.match("abab");

	return 0;
}
