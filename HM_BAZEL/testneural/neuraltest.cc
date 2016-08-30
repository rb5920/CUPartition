#include <stdio.h>
#include "neural_cup.h"
using namespace tensorflow;
using namespace std;

int main()
{
	float *a;
	float inputx[12]={0};
	bool ans;
	FILE* fp;
	printf("haha\n");
	//fp=fopen("CUPartition_s201_CTU16.csv","r");
	//fscanf(fp,"%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%d\n",&inputx[0],&inputx[1],&inputx[2],&inputx[3],&inputx[4],&inputx[5],&inputx[6],&inputx[7],&inputx[8],&inputx[9],&inputx[10],&inputx[11],&inputx[12],&ans);
	inputx[0]=153;
	inputx[1]=136;
	inputx[2]=136;
	inputx[3]=175;
	inputx[4]=166;
	inputx[5]=22.12;
	inputx[6]=5090.38;
	inputx[7]=384;
	inputx[8]=0;
	inputx[9]=0;
	inputx[10]=24;
	inputx[11]=21;
	a=inputx;
	//printf("%d,",(a));
	//printf("%d",(inputx));
	ans = neural_cup(a);
	printf("ans=%d\n",ans);
	return 0;
}
