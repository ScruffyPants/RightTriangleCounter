#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h"

void nuskaitymas(){
	FILE *inputas, *outputas;
	int n,eilutes=0,i;
	outputas=fopen("/home/scruffypants/Desktop/Programming/C/Uzd5/Uzd5/Uzd5/output.txt","w");
	fclose(outputas);
	inputas=fopen("/home/scruffypants/Desktop/Programming/C/Uzd5/Uzd5/Uzd5/input.txt","r");
	if(inputas == NULL) printf("Nepavyko nuskaityti failo!");
	while(!feof(inputas)){
		fscanf(inputas," %d", &n);
		eilutes++;
	}
	eilutes=(eilutes-1)/2;
	int* x=malloc(eilutes * sizeof(int)); 
	int* y=malloc(eilutes * sizeof(int));
	rewind(inputas);
	for(i=0;i<eilutes;i++) fscanf(inputas, " %d %d", &x[i],&y[i]);
	fclose(inputas);
	skaiciavimas(x,y,eilutes);
}
void skaiciavimas(int* x, int* y, int eilutes){
	int i, TSk=0, temp1=0, temp2=0, temp3=0, maziausias1, maziausias2, maziausias3, ASk=(eilutes*(eilutes-1)*(eilutes-2))/6;
	double maziausias=0;
	for(i=0;i<ASk;i++){
	temp3++;
			while((temp3==temp2) || (temp2==temp1) || (temp1==temp3) || (temp3>eilutes-1) || (temp2>eilutes-1)){
				temp3++;
				if(temp3>eilutes-1){
					temp2++;
					temp3=temp2+1;
				}
				if(temp2>eilutes-1){
					temp1++;
					temp2=temp1+1;
					temp3=temp2+1;
				}
			}
		double S1=sqrt(pow((x[temp1]-x[temp2]),2)+pow((y[temp1]-y[temp2]),2));
		double S2=sqrt(pow((x[temp2]-x[temp3]),2)+pow((y[temp2]-y[temp3]),2));
		double S3=sqrt(pow((x[temp1]-x[temp3]),2)+pow((y[temp1]-y[temp3]),2));
		if(((S1+S2)>S3) && ((S2+S3)>S1) && ((S1+S3)>S2)){
			if((S3==(sqrt(pow(S2,2)+pow(S1,2)))) || (S2==(sqrt(pow(S1,2)+pow(S3,2)))) || (S1==(sqrt(pow(S2,2)+pow(S3,2))))){
				rasymas(x[temp1], y[temp1], x[temp2], y[temp2], x[temp3], y[temp3], 0);
				double S=sqrt(((S1+S2+S3)/2)*(((S1+S2+S3)/2)-S1)*(((S1+S2+S3)/2)-S2)*(((S1+S2+S3)/2)-S3));
				if(S<maziausias || maziausias==0){
				maziausias=S;
				maziausias1=temp1;
				maziausias2=temp2;
				maziausias3=temp3;
				}
			}
		}
	}
	rasymas(x[maziausias1],y[maziausias1],x[maziausias2],y[maziausias2],x[maziausias3],y[maziausias3],maziausias);
}
void rasymas(int x1, int x2, int x3, int y1, int y2, int y3, double maziausias){
	FILE *outputas;
	outputas=fopen("/home/scruffypants/Desktop/Programming/C/Uzd5/Uzd5/Uzd5/output.txt","a");
	if(!maziausias)fprintf(outputas,"(%d;%d),(%d;%d),(%d;%d)\n",x1,y1,x2,y2,x3,y3);
	else fprintf(outputas,"Maziausias plotas: %.2f | (%d;%d),(%d;%d),(%d;%d)\n",maziausias,x1,y1,x2,y2,x3,y3);
	fclose(outputas);
}