#include <iostream>

using namespace std;

int arr[7] = { 50, 700, 76, 85, 92, 73, 101 };

// N is Array Size..
int N = 7;

int hashTab[7];

// L is Hash Table Size..
int L = 7;

void initialize_HashTable(){
	for(int i=0; i<L; i++){
		hashTab[i] = -1;
	}
}

int newHash(int hVal){
	int t = 0;
	for (int j = 0; j < L; j++) { 
        t = (hVal + j * j) % L; 
        if (hashTab[t] == -1) { 
			break;
        } 
    }
	return t;
}

void hashFunc(){
	for (int i = 0; i < N; i++) {
        int hv = arr[i] % L;
        if (hashTab[hv] == -1) 
        {
        	hashTab[hv] = arr[i]; 
		}
        else { 
			int nVal = newHash(hv);
			hashTab[nVal] = arr[i];        	 
        }
    }
}

void print_HashTab(){
	for(int i=0; i<L; i++){
		cout << "[" << i <<"]" << " --> " << hashTab[i] << endl;
	}
}

int main(){
	initialize_HashTable();
	hashFunc();
	print_HashTab();
	
	return 0;
}
