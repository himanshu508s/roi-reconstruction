#include <stdio.h>
#include <gsl/gsl_linalg.h>
#include<iostream>

using namespace std;




void inverse_metric()
{
ifstream fp1;
FILE *fp2;
fp2=fopen("inv_metric.txt","w+");
fp1.open("metric.txt");
if(fp1.is_open()){
while(!fp1.eof()){
double g[9];
size_t var = 3;
    fp1 >> g[0];
    fp1 >> g[4];
    fp1 >> g[8];
    fp1 >> g[1];
    fp1 >> g[5];
    fp1 >> g[2];
    g[3] = g[1];
    g[6] = g[2];
    g[7] = g[5];
    
    gsl_matrix_view m 
    = gsl_matrix_view_array (g, var, var); 

   gsl_matrix *g_inv = gsl_matrix_alloc (var,var);

  int s;

  gsl_permutation * p = gsl_permutation_alloc (var);

  gsl_linalg_LU_decomp (&m.matrix, p, &s);

 double det = gsl_linalg_LU_det (&m.matrix, s);

  if(det!=0)
{
  gsl_linalg_LU_invert (&m.matrix,  p,  g_inv);
  
  gsl_matrix_fprintf(fp2, g_inv, "%g");
}
}
}
}


void affine_param(double g1[6],double g2[6],double g_inv[9],double x1,double y1,double z1,double x2,double y2,double z2,FILE *afp)
{
double gamma[3][3][3],G1[3][3],G2[3][3],G_inv[3][3];


G1[0][0]=g1[0];
G1[0][1]=g1[3];
G1[0][2]=g1[5];
G1[1][0]=g1[3];
G1[1][1]=g1[1];
G1[1][2]=g1[4];
G1[2][0]=g1[5];
G1[2][1]=g1[4];
G1[2][2]=g1[2];

G2[0][0]=g2[0];
G2[0][1]=g2[3];
G2[0][2]=g2[5];
G2[1][0]=g2[3];
G2[1][1]=g2[1];
G2[1][2]=g2[4];
G2[2][0]=g2[5];
G2[2][1]=g2[4];
G2[2][2]=g2[2];

G_inv[0][0]=g_inv[0];
G_inv[0][1]=g_inv[1];
G_inv[0][2]=g_inv[2];
G_inv[1][0]=g_inv[3];
G_inv[1][1]=g_inv[4];
G_inv[1][2]=g_inv[5];
G_inv[2][0]=g_inv[6];
G_inv[2][1]=g_inv[7];
G_inv[2][2]=g_inv[8];

for(int i=0;i<3;i++){
for(int j=0;j<3;j++){
for(int k=0;k<3;k++){
gamma[i][j][k]=0;
}}}

for(int i=0;i<3;i++){
for(int j=0;j<3;j++){
for(int k=0;k<3;k++){
for(int p=0;p<3;p++){
double G_[3][3];

if(x2!=x1){ //is there a necessaity to check this condition
G_[0][0]=(G2[p][j]-G1[p][j])/(x2-x1);
G_[0][1]=(G2[p][k]-G1[p][k])/(x2-x1);
G_[0][2]=(G2[j][k]-G1[j][k])/(x2-x1);
}

else{
G_[0][0]=0;
G_[0][1]=0;
G_[0][2]=0;
}

if(y2!=y1){
G_[1][0]=(G2[p][j]-G1[p][j])/(y2-y1);
G_[1][1]=(G2[p][k]-G1[p][k])/(y2-y1);
G_[1][2]=(G2[j][k]-G1[j][k])/(y2-y1);
}

else{
G_[1][0]=0;
G_[1][1]=0;
G_[1][2]=0;
}

if(z2!=z1){
G_[2][0]=(G2[p][j]-G1[p][j])/(z2-z1);
G_[2][1]=(G2[p][k]-G1[p][k])/(z2-z1);
G_[2][2]=(G2[j][k]-G1[j][k])/(z2-z1);
}

else{
G_[2][0]=0;
G_[2][1]=0;
G_[2][2]=0;
}

gamma[i][j][k] += G_inv[i][p]*(G_[k][0]+G_[j][1]-G_[p][2]);
}
fprintf(afp,"%g \n",gamma[i][j][k]);
}
}
}

}



void affine()
{
 ifstream fp1,fp2,fp3;
 fp1.open("metric.txt");
 fp2.open("points.txt");
 inverse_metric();
 fp3.open("inv_metric.txt");
 FILE *afp;
 afp=fopen("affine.txt","w+");
 char output1[100],output2[100];
 if (fp2.is_open() && fp1.is_open()) {
 while (!fp2.eof()&&!fp1.eof()) {
 double g1[6],g2[6],g_inv[9],x1,y1,z1,x2,y2,z2;
    fp1 >> g1[0];
    fp1 >> g1[1];
    fp1 >> g1[2];
    fp1 >> g1[3];
    fp1 >> g1[4];
    fp1 >> g1[5];

    fp1 >> g2[0];
    fp1 >> g2[1];
    fp1 >> g2[2];
    fp1 >> g2[3];
    fp1 >> g2[4];
    fp1 >> g2[5];

    
    fp3 >> g_inv[0];
    fp3 >> g_inv[1];
    fp3 >> g_inv[2];
    fp3 >> g_inv[3];
    fp3 >> g_inv[4];
    fp3 >> g_inv[5];
    fp3 >> g_inv[6];
    fp3 >> g_inv[7];
    fp3 >> g_inv[8];
 
    fp2 >> x1;
    fp2 >> y1;
    fp2 >> z1;
    
    fp2 >> x2;
    fp2 >> y2;
    fp2 >> z2;
    
   affine_param(g1,g2,g_inv,x1,y1,z1,x2,y2,z2,afp);
    
 }
}
fp1.close();
fp2.close();
fclose(afp);
}
