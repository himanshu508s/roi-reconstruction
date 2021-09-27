#include <stdio.h>
#include <gsl/gsl_linalg.h>
#include<iostream>
#include <pcl/point_cloud.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>


using namespace std;

double* metric_tensor(double dx1,double dy1,double dz1,double ds1,double dx2,double dy2,double dz2,double ds2,double dx3,double dy3,double dz3,double ds3,double dx4,double dy4,double dz4,double ds4,double dx5,double dy5,double dz5,double ds5,double dx6,double dy6,double dz6,double ds6,FILE *myfile,pcl::PointXYZ searchPoint,FILE *myfile1)
{
  double a_data[36];

  double b_data[6]; 
  size_t var=6;


 a_data[0]=dx1*dx1;
 a_data[1]=dy1*dy1;
 a_data[2]=dz1*dz1;
 a_data[3]=2*dx1*dy1;
 a_data[4]=2*dy1*dz1;
 a_data[5]=2*dx1*dz1;

 a_data[6]=dx2*dx2;
 a_data[7]=dy2*dy2;
 a_data[8]=dz2*dz2;
 a_data[9]=2*dx2*dy2;
 a_data[10]=2*dy2*dz2;
 a_data[11]=2*dx2*dz2;

 a_data[12]=dx3*dx3;
 a_data[13]=dy3*dy3;
 a_data[14]=dz3*dz3;




 a_data[15]=2*dx3*dy3;
 a_data[16]=2*dy3*dz3;
 a_data[17]=2*dx3*dz3;

 a_data[18]=dx4*dx4;
 a_data[19]=dy4*dy4;
 a_data[20]=dz4*dz4;
 a_data[21]=2*dx4*dy4;
 a_data[22]=2*dy4*dz4;
 a_data[23]=2*dx4*dz4;

 a_data[24]=dx5*dx5;
 a_data[25]=dy5*dy5;
 a_data[26]=dz5*dz5;
 a_data[27]=2*dx5*dy5;
 a_data[28]=2*dy5*dz5;
 a_data[29]=2*dx5*dz5;

 a_data[30]=dx6*dx6;
 a_data[31]=dy6*dy6;
 a_data[32]=dz6*dz6;
 a_data[33]=2*dx6*dy6;
 a_data[34]=2*dy6*dz6;
 a_data[35]=2*dx6*dz6;

	
 b_data[0]=ds1*ds1;
 b_data[1]=ds2*ds2;
 b_data[2]=ds3*ds3;
 b_data[3]=ds4*ds4;
 b_data[4]=ds5*ds5;
 b_data[5]=ds6*ds6;
	


  gsl_matrix_view m 
    = gsl_matrix_view_array (a_data, var, var);

  gsl_vector_view b
    = gsl_vector_view_array (b_data, var);

  gsl_vector *x = gsl_vector_alloc (var);
  
  int s;

  gsl_permutation * p = gsl_permutation_alloc (var);
//cout<<"p.data:"<<p->data<<"\n";
 /* for(size_t i=0;i<6;i++)
	{
	for(size_t j=0;j<6;j++)
	{
		cout<<gsl_matrix_get(&m.matrix,i,j)<<"\t\t";
	}
	cout<<"\n\n";
	}*/
  gsl_linalg_LU_decomp (&m.matrix, p, &s);
 
  double det = gsl_linalg_LU_det (&m.matrix, s);

  if(det!=0)
  {
  gsl_linalg_LU_solve (&m.matrix, p, &b.vector, x);
  

  //printf ("x = \n");
  //gsl_vector_fprintf (stdout, x, "%g");

  fprintf(myfile1,"%f\n%f\n%f\n",searchPoint.x,searchPoint.y,searchPoint.z); // this file is not essential over here
  gsl_vector_fprintf(myfile, x, "%g");
  

  gsl_permutation_free (p);
  gsl_vector_free (x);
  }
  return 0;
}



double dist(char *name,std::vector<int> idx)
{
 pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ> ());
 pcl::io::loadPCDFile (name, *cloud);  
double ds[10];
int k=0;

std::vector<float> pointNKNSquaredDistance(10);

pcl::KdTreeFLANN<pcl::PointXYZ> kdtree;

kdtree.setInputCloud (cloud);

std::vector<int> idx2(10);

std::vector<int> idx3(10);

kdtree.nearestKSearch (cloud->points[idx[9]], 10, idx2, pointNKNSquaredDistance); //change idx[9] to idx[10]

for(int i=0;i<10;i++)
{
for(int j=0;j<10;j++)
{
if(idx[i]==idx2[j]) //try finding inbuild array_intersect and store into a new_array
{
idx3[k]=idx2[j];
k=k+1; //can break the loop, once there is match by putting break for next iteration of i
}
}
}

//Calculation of euclidean distance between interested points
float ds1=sqrt(pow(cloud->points[idx[0]].x-cloud->points[idx[9]].x,2)+pow(cloud->points[idx[0]].y-cloud->points[idx[9]].y,2)+pow(cloud->points[idx[0]].z-cloud->points[idx[9]].z,2));
double ds2=0;
int i=0;

for(i=0;i<k-1;i++)
{
ds2+=sqrt(pow(cloud->points[idx3[i]].x-cloud->points[idx3[i+1]].x,2)+pow(cloud->points[idx3[i]].y-cloud->points[idx3[i+1]].y,2)+pow(cloud->points[idx3[i]].z-cloud->points[idx3[i+1]].z,2));
}

//add ds1 to ds2 before returning ds2

return ds2;
}
