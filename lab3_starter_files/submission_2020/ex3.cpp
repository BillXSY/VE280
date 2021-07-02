#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int add(int count, int arr[], bool isVerbose){
	int sum = 0;
	for (int i = 0; i < count; i++){
    	sum += arr[i];
    }
    if (isVerbose == 1) {
    	cout << "This is add operation."<<endl;
    }
    return sum;
}

int small(int addend, int count, int arr[], bool isVerbose){
	int smaller = arr[0];
	for (int i = 1; i < count; i++ ){
		if (arr[i] < smaller){
			smaller = arr[i];
		}
	}
	if (isVerbose == 1) {
    	cout << "This is small operation."<<endl;
    }
    return smaller + addend;
}

int main(int argc, char* argv[])
{
    int count, l_verbose, l_help;
    int arr[50];
    bool isVerbose = false;
    bool isAdd = false;
    bool isSmall = false;

    cin >> count;
    for (int i = 0; i < count; i++){
    	cin >> arr[i];
    }
    cin.ignore(9999,'\n');

    for (int i = 1; i < argc; i++){
    	if (strcmp(argv[i],"--verbose")==0){
    		isVerbose = true;
    		l_verbose = i;
    	}
    }
    
    for (int i = 1; i < argc; i++){
    	if (strcmp(argv[i],"--help")==0){
    		cout << "Hey, I love Integers." << endl;
    		l_help = i;
    		return 0;
    	}
	}
    
    for (int i = 1; i < argc; i++){
    	if (strcmp(argv[i],"--add")==0){
    		cout << add(count, arr, isVerbose) << endl;
    		isAdd = true;
    	}
    }
    
    for (int i = 1; i < argc; i++){
    	if (strcmp(argv[i],"--small")==0){
    		int addend = atoi(argv[i+1]);
    		cout << small (addend, count, arr, isVerbose) << endl;
    		isSmall = true;
    	}
    }
	
	if(isAdd+isSmall == false){
		cout<<"No work to do!"<<endl;
	}
    return 0;
}

