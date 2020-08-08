#include<iostream>

using namespace std;

int hashTab[13];
int tabSize = 13, zeroCount = 0;
int array[10] = {27, 33, 46, 89, 77, 88, 93, 59, 60, 40};

void initialize_HashTab(){
	for(int i=0; i<13; i++){
		hashTab[i] = 0;
	}
}

void print_HashTable(){
	for(int i=0; i<13; i++){
		cout << "[" << i << "] --> " << hashTab[i] << endl;
	}
}

int hashFunc(int key){
	return key % 13;
}

int searchSpace(int hI){
	if(hashTab[hI] == 0){
		return hI;
	}
	else{
		if(hI == tabSize-1 && hashTab[hI] != 0){
			/* hI is set to -1 because in
			the next statement it increments 
			and make it zero making possible 
			to search for vacancy of zeroth index
			//*/
			hI = -1;
		}
		hI++;
		searchSpace(hI);
	}
}

void insertkey(int key, int hInd){
	if(hashTab[hInd] == 0){
		hashTab[hInd] = key;
	}
	else{
		int ind = searchSpace(hInd);
		hashTab[ind] = key;
	}
	zeroCount++;
}

int main(){
	int aSize = sizeof(array)/sizeof(array[0]);
	initialize_HashTab();
	int iter = 0;
	
	while(iter < aSize){
		
		if(zeroCount < tabSize){
			// Computing index for elements in an array of Linked list..
			int hashInd = hashFunc(array[iter]);
			
			// Placing element on that index..
			insertkey(array[iter], hashInd);
		}
		else{
			cout << "Hash table if full cant insert anymore..";
			break;
		}
		iter++;
	}
	print_HashTable();
	return 0;
}
