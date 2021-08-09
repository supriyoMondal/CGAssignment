#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<graphics.h>
using namespace std;
void Mul(float a[][2],float b[][3],float c[][3],int m,int n,int o){
	int i,j,k;
	for (i=0;i<m;i++) {
        for (j=0;j<o;j++) {
            c[i][j] = 0;
            for (k=0;k<n;k++){
                c[i][j] =c[i][j] + (a[i][k] * b[k][j]);
        	}
        }
    }
}
void Translation(float point[][3],float ty,float tx,int n){
	for(int i=0;i<n;i++){
		point[0][i]+=tx;
		point[1][i]+=ty;
	}
}
int main(){
	int gm,gd=DETECT;
	initgraph(&gd,&gm,(char*)"");
	float x1,y1,x2,y2,x3,y3,tx,ty,A;
	cout<<"Enter the 1st point: ";
	cin>>x1>>y1;
	cout<<"Enter the 2nd point: ";
	cin>>x2>>y2;
	cout<<"Enter the 3rd point: ";
	cin>>x3>>y3;
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x3,y3,x1,y1);
	cout<<"Enter the translation vector: ";
	cin>>tx>>ty;
	cout<<"Enter the rotation angle: ";
	cin>>A;
	float r[2][2];
	A=A*M_PI/180;
	r[0][0]=cos(A);
	r[0][1]=-sin(A);
	r[1][0]=sin(A);
	r[1][1]=cos(A);
	float point[2][3];
	point[0][0]=x1;
	point[0][1]=x2;
	point[0][2]=x3;
	point[1][0]=y1;
	point[1][1]=y2;
	point[1][2]=y3;
	float result1[2][3];
	Mul(r,point,result1,2,2,3);
	Translation(point,tx,ty,3);
	float result[2][3];
	Mul(r,point,result,2,2,3);
	Translation(result1,tx,ty,3);
	cout<<"rotation after translation\n";
	for(int i=0;i<3;i++){
		cout<<"("<<result[0][i]<<","<<result[1][i]<<")\n";
	}
	line(result[0][0]+100,result[1][0]+100,result[0][1]+100,result[1][1]+100);
	line(result[0][1]+100,result[1][1]+100,result[0][2]+100,result[1][2]+100);
	line(result[0][2]+100,result[1][2]+100,result[0][0]+100,result[1][0]+100);
	cout<<"rotation before translation\n";
	for(int i=0;i<3;i++){
		cout<<"("<<result1[0][i]<<","<<result[1][i]<<")\n";
	}
	line(result1[0][0]+100,result1[1][0]+100,result1[0][1]+100,result1[1][1]+100);
	line(result1[0][1]+100,result1[1][1]+100,result1[0][2]+100,result1[1][2]+100);
	line(result1[0][2]+100,result1[1][2]+100,result1[0][0]+100,result1[1][0]+100);
	getch();
}