#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find (char dna[], char therons[]);
int verify(char dna[]);

int main() {

	char dna[10000];

	char * threons[4] = {"ACT", "ACC", "ACA", "ACG"};

	printf("Enter the DNA sequecen: ");
	//read up to 9999 characters
	scanf("%9999s", dna);
	if(verify(dna) == -1){
		return -1
	}
	find(dna, threons);



	/*
	TODO: add your code here (or in the additional
	functions that are called from here).
	*/


	return 0;

}

int find(char dna[], char threons[]){
	int found;
	int i = 0;
	int times = 0;
	char temp [3];
	while(dna[i] != '\0'){
		int j;
		for(j = 0; j < 3; j++){
			temp[j] = dna [i];
			i++;
		}
		int k;
		int m = 0;
		for(k = 0; k < 4; k ++){
			if(threons[m] == dna[m]) {     // if first character of search string matches
			// keep on searching
				while(threons[m] !='\0') {
					if(threons[m] == dna[m]){
						m++;
					}
				}
				if(m == 3){
					found = j;
					printf("%d\n", found);
					times++;
				}
				else{
					m = 0;
					found = 0;
        		}
			}
		}
	}
	if(times == 0){
		//printf("%d\n", found);
		return -1;
	}
}

int verify(char dna[]){
	int i = 0;
	while(dna[i] != '\0'){
		if(dna[i] != 'A' || dna[i] != 'C' || dna[i] != 'T' || dna[i] != 'G'){
			return -1;
		}
		else{
			return 1;
		}

	}
}