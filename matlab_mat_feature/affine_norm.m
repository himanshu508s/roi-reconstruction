f2=fopen('affine.txt','r');
[a,b]=size(affine);
for i=1:(a/27)
temp=fscanf(f2,'%g',27);
if(abs(temp)<=1000000.0)
a_chair1(i,:)=temp;
else
a_chair1(i,:)=temp;
end
end
for i=1:27
    na_chair1(i,:)=nor(a_chair1,i);
end;
n_a_chair1=[na_chair1(1,:); na_chair1(2,:); na_chair1(3,:); na_chair1(4,:); na_chair1(5,:); na_chair1(6,:); na_chair1(7,:); na_chair1(8,:); na_chair1(9,:); na_chair1(10,:); na_chair1(11,:); na_chair1(12,:); na_chair1(13,:); na_chair1(14,:); na_chair1(15,:); na_chair1(16,:); na_chair1(17,:); na_chair1(18,:); na_chair1(19,:); na_chair1(20,:); na_chair1(21,:); na_chair1(22,:); na_chair1(23,:); na_chair1(24,:); na_chair1(25,:); na_chair1(26,:); na_chair1(27,:)];
n_a_chair1=n_a_chair1';
%[nsph1,nsph2,nsph3,nsph4,nsph5,nsph6]=func(a_sph);
fclose(f2);