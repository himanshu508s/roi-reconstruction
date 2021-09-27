#include <pcl/point_cloud.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>


#include <iostream>
#include <vector>
#include <ctime>
//#include "quadratic_spline.h"
//#include "cube_spline.h"
#include "metric.h"
#include"affine.h"
//using namespace std;

int
main (int argc, char** argv)
{

  FILE *myfile,*myfile1;
  
  myfile=fopen("metric.txt","w+");
  myfile1=fopen("points.txt","w+");
  int K=10,k=0;
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ> ());
  
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud1 (new pcl::PointCloud<pcl::PointXYZ> ());
  
  pcl::io::loadPCDFile (argv[1], *cloud);  

  pcl::KdTreeFLANN<pcl::PointXYZ> kdtree;

  kdtree.setInputCloud (cloud);

  pcl::PointXYZ searchPoint[6];

  
  size_t no_points=cloud->points.size();
  size_t j = cloud->points.size()+1;
  //cout<<"j=\t"<<j<<"\n";
  
  //cloud1->width    = 2*no_points;
  //cloud1->height   = 1;
  //cloud1->is_dense = false;
  //cloud1->points.resize (cloud1->width * cloud1->height);
  
 // cout<<"no of points\t"<<no_points<<"\n";
  /*for (size_t i = 0; i <= no_points; ++i)
  {
    cloud1->points[i] = cloud->points[i];

  }*/

for (size_t i = 0; i < no_points; i++)
  {
	//if(j < no_points*2)
//{	
  searchPoint[0].x = cloud->points[i].x;
  searchPoint[0].y = cloud->points[i].y;
  searchPoint[0].z = cloud->points[i].z;

  std::vector<int> pointIdxNKNSearch(K);
  std::vector<int> pointIdxNKNSearch1(K);
  std::vector<int> pointIdxNKNSearch2(K);
  std::vector<int> pointIdxNKNSearch3(K);
  std::vector<int> pointIdxNKNSearch4(K);
  std::vector<int> pointIdxNKNSearch5(K);
  std::vector<float> pointNKNSquaredDistance(K);

      	kdtree.nearestKSearch (searchPoint[0], K, pointIdxNKNSearch, pointNKNSquaredDistance);
	
	double ds1=dist(argv[1],pointIdxNKNSearch); 
	double dx1=cloud->points[pointIdxNKNSearch[9]].x-cloud->points[pointIdxNKNSearch[0]].x;
	double dy1=cloud->points[pointIdxNKNSearch[9]].y-cloud->points[pointIdxNKNSearch[0]].y;
	double dz1=cloud->points[pointIdxNKNSearch[9]].z-cloud->points[pointIdxNKNSearch[0]].z;
	
      	kdtree.nearestKSearch (cloud->points[pointIdxNKNSearch[1]], K, pointIdxNKNSearch1, pointNKNSquaredDistance);
	
	double ds2=dist(argv[1],pointIdxNKNSearch1);
	double dx2=cloud->points[pointIdxNKNSearch1[9]].x-cloud->points[pointIdxNKNSearch1[0]].x;
	double dy2=cloud->points[pointIdxNKNSearch1[9]].y-cloud->points[pointIdxNKNSearch1[0]].y;
	double dz2=cloud->points[pointIdxNKNSearch1[9]].z-cloud->points[pointIdxNKNSearch1[0]].z;

      	kdtree.nearestKSearch (cloud->points[pointIdxNKNSearch[2]], K, pointIdxNKNSearch2, pointNKNSquaredDistance);
	
	double ds3=dist(argv[1],pointIdxNKNSearch2);
	double dx3=cloud->points[pointIdxNKNSearch2[9]].x-cloud->points[pointIdxNKNSearch2[0]].x;
	double dy3=cloud->points[pointIdxNKNSearch2[9]].y-cloud->points[pointIdxNKNSearch2[0]].y;
	double dz3=cloud->points[pointIdxNKNSearch2[9]].z-cloud->points[pointIdxNKNSearch2[0]].z;

      	kdtree.nearestKSearch (cloud->points[pointIdxNKNSearch[3]], K, pointIdxNKNSearch3, pointNKNSquaredDistance);
	
	double ds4=dist(argv[1],pointIdxNKNSearch3);
	double dx4=cloud->points[pointIdxNKNSearch3[9]].x-cloud->points[pointIdxNKNSearch3[0]].x;
	double dy4=cloud->points[pointIdxNKNSearch3[9]].y-cloud->points[pointIdxNKNSearch3[0]].y;
	double dz4=cloud->points[pointIdxNKNSearch3[9]].z-cloud->points[pointIdxNKNSearch3[0]].z;

      	kdtree.nearestKSearch (cloud->points[pointIdxNKNSearch[4]], K, pointIdxNKNSearch4, pointNKNSquaredDistance);
	
	double ds5=dist(argv[1],pointIdxNKNSearch4);
	double dx5=cloud->points[pointIdxNKNSearch4[9]].x-cloud->points[pointIdxNKNSearch4[0]].x;
	double dy5=cloud->points[pointIdxNKNSearch4[9]].y-cloud->points[pointIdxNKNSearch4[0]].y;
	double dz5=cloud->points[pointIdxNKNSearch4[9]].z-cloud->points[pointIdxNKNSearch4[0]].z;

      	kdtree.nearestKSearch (cloud->points[pointIdxNKNSearch[5]], K, pointIdxNKNSearch5, pointNKNSquaredDistance);
	
	double ds6=dist(argv[1],pointIdxNKNSearch5);
	double dx6=cloud->points[pointIdxNKNSearch5[9]].x-cloud->points[pointIdxNKNSearch5[0]].x;
	double dy6=cloud->points[pointIdxNKNSearch5[9]].y-cloud->points[pointIdxNKNSearch5[0]].y;
	double dz6=cloud->points[pointIdxNKNSearch5[9]].z-cloud->points[pointIdxNKNSearch5[0]].z;
	double *metric;
	metric=metric_tensor(dx1,dy1,dz1,ds1,dx2,dy2,dz2,ds2,dx3,dy3,dz3,ds3,dx4,dy4,dz4,ds4,dx5,dy5,dz5,ds5,dx6,dy6,dz6,ds6,myfile,searchPoint[0],myfile1);
	/*for(int i=0;i<6;i++)
	{   
	cout<<*metric<<"\n";
	*metric++;  
	}*/
  }
//else
//goto x;
  fclose(myfile);
  fclose(myfile1);
affine();
//sx:   cout<<"HERE EXIT\n";
//pcl::io::savePCDFile (argv[2], *cloud1); 
//pcl::io::savePCDFile (argv[2], *cloud);
  return 0;
}
