#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verify(char dna[]);
void find (char dna[], char * therons[]);

int main() {

	char dna[10000];

	char * threons[4] = {"ACT", "ACC", "ACA", "ACG"};

	printf("Enter the DNA sequecen: ");
	//read up to 9999 characters
	scanf("%9999s", dna);
	//char * dnaptr = dna;
	//int i = 0;
	//printf("%s", dna);

	if(verify(dna) == -1){
		printf("-1\n");
		return -1;
	}
	else{
		find(dna, threons);
	}



	/*
	TODO: add your code here (or in the additional
	functions that are called from here).
	*/


	return 0;

}

int verify(char dna[]){
	int i = 0;
	while( dna[i] != '\0'){
		if(dna[i] != 'A' && dna[i] != 'C' && dna[i] != 'T' && dna[i] != 'G'){
			return -1;
		}
		i++;
	}
	return 1;
}

void find(char dna[], char * threons[]){
	int found;
	int i;
	//int times = 0;
	//char temp [3];
	for(i = 0; i < 4; i++){
		char *position_ptr = strchr(dna, * threons[i]);
		int position = (position_ptr == NULL ? -2 : position_ptr - dna);
	}

}
