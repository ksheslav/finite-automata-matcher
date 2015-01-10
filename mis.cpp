#include <iostream>
#include <string>
bool ends_with(std::string Pq,std::string Pk){
	if(Pq>=Pk){
		int counter=0;

		for(int i=Pq.length()-1;i>=0;--i){
			for(int j=0;j<( int)Pk.length();++j){
				if(Pq[i]==(Pk[j])){

					std::cout<<Pq[i]<<" "<<Pk[j]<<std::endl;
					std::cout<<"true"<<std::endl;

					counter++;

				}else if(counter==(int)Pq.length()){

					return true;
				}

			}
		}
	}
	return false;
}
int main(){
	std::string a = "abab";
	std::string b ="ababab";
	std::cout<<ends_with(a,b);
	return 0;
}
