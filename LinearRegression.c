#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define LINE_SIZE 50
//average & variance & std
//sqare_feet 2006.374680 331208.866575 575.507486
//
int main(){
	double average = 0,variance = 0;
	int count = 0,n;
	FILE *fp = fopen("housing_price_dataset.csv","r");
	char line[LINE_SIZE];
	char square_feet[10];
	char *tmp;
	while(fgets(line,LINE_SIZE,fp) != NULL){
		tmp = strchr(line,',');
		strncpy(square_feet,line,tmp-line);
		n = atoi(square_feet);
		average = (count*average+n)*1.0/(count+1);
		variance = (count*variance+(n-2006.37468)*(n-2006.37468))/(count+1);

		count++;
	}
	printf("average:%lf\ncount:%d\nvariance:%lf\nstd:%lf\n",average,count,variance,sqrt(variance));
	return 0;
}