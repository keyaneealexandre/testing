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
	char temp [3];
	for(i = 0; i < strlen(dna); i+=3){
		strncpy(temp, &dna[i], 3);
		temp[3] = '\0';
		int j;
		//printf("%s\n", temp);
		for(j = 0; j < 4; j++){
			//printf("%s\n", threons[j]);
			if(strcmp (temp, threons[j]) == 0){
				found = i;
				printf("%d\n", found);
			}
		}
	}
	if(found == 0){
			printf("-2");
	}

}
