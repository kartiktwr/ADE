
using namespace std;

bool Setup();

bool loop();


int main(){
	Setup();
	bool flag = true;
	flag = Setup();
	
	while(flag){
		
		flag = loop();
	}
	return 0;
}
