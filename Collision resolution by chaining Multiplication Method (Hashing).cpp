#include<iostream>

using namespace std;

double a = 0.618;

int array[5] = {27, 33, 46, 89, 77};

struct chain{
	int data;
	chain *next;
};

chain *aLinked_List[11];

void insert_Data(int data, int index){
	chain *node = new chain, *i;
	node->data = data;
	node->next = NULL;
		
	if(aLinked_List[index] == NULL){
		aLinked_List[index] = node;
	}
	else{
		for(i=aLinked_List[index]; i->next!=NULL; i=i->next);
		i->next = node;		
	}
}

double dob_modulusOperator(int key){
	double val = key * 0.618;
	int intVal = (int) val;
	return val - intVal;
}

int hashFunc(int key, int tabSize){
	double afterMod_Val = dob_modulusOperator(key);
	double mul_M = tabSize * afterMod_Val;
	return (int)mul_M;
}

void print_aLinked_List(chain *aList[]){
	for(int j=0; j<11; j++){
		if(aLinked_List[j] == NULL){
			cout << "[" << j  << "] " <<" / "<< endl;
		}
		else{
			chain *x;
			cout << "[" << j  << "] ";
			for(x=aLinked_List[j]; x->next!=NULL; x = x->next){
				cout << x->data << " --> ";
			}
			cout << x->data;
			cout << endl;
		}
	}
}

int main(){
	int ar_Length = sizeof(array)/sizeof(array[0]);
	int iter = 0;
	//	initialize_aLinked_List_NULL();
	while(iter < ar_Length){
		// Computing index for elements in an array of Linked list..
		int hashInd = hashFunc(array[iter], 11);
		
		// Placing element on that index..
		insert_Data(array[iter], hashInd);
		iter++;
	}
	cout << endl;
	print_aLinked_List(aLinked_List);
	return 0;
}
