[a,b]=size(points);
i=1;
for j=1:(a/3)
    rad(j)=sqrt(points(i)^2+points(i+1)^2+points(i+2)^2);

    i=i+3;
end
   rad=rad';
[a,b]=size(d_chair1);
j=1;
for i=1:a-1
    for k=1:33
    dp_chair1(i,k)=rad(j)*d_chair1(i,k);
    
    end
    j=j+2;
end
 for i=1:33
     ndp_chair1(i,:)=nor(dp_chair1,i);
 end;
 ndp_chair1=ndp_chair1';

f2=fopen('points.txt','r');
[a,b]=size(points);
for i=1:(a/3)
temp=fscanf(f2,'%g',3);
if(abs(temp)<=1000000.0)
chair1_pt(i,:)=temp;
else
chair1_pt(i,:)=temp;
end
end

temp=downsample(chair1_pt,2);    
 for i=1:3
     temp1(i,:)=nor(temp,i);
 end;
 temp1=temp1';
[c,d]=size(temp);
chair1=[d_chair1(1:c,:) temp];