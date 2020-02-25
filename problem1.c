#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/*
 * This program analyzes the DNA strand and determines
 * the locations of the triples that encode Threonine.
 * Those triples are ACT, ACC, ACA, ACG.
 * Author: Keyanee Alexandre
 *
 */

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
	return 0;

}

/*
 * Makes sure that the DNA string intered contains the correct
 * characters. if not return -1.
 * Parameters:
 *		dna[] - the dna string entered.
 * Return:
 *		-1-not valid.
 *		1-valid.
 *
 */
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

/*
 * finds the locations of the triples that encode Threonine.
 * Parameters:
 *		dna[] - the dna string entered.
 *		threons[] - the patterns to find
 *
 */

void find(char dna[], char * threons[]){
	int found;//keep track of where match found
	int times;//number of times found updated
	int i;
	char temp [3];//temp array to hold the three positions in dna to be checked

	//iterate through dna chain
	for(i = 0; i < strlen(dna); i+=3){
		strncpy(temp, &dna[i], 3);
		temp[3] = '\0';
		int j;

		//iterate through threons
		for(j = 0; j < 4; j++){
			if(strcmp (temp, threons[j]) == 0){
				found = i;
				times++;
				printf("%d\n", found);
			}
		}
	}
	if(times == 0){
			printf("-2");
	}

}
