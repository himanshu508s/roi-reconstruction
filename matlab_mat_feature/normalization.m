f2=fopen('metric.txt','r');
[a,b]=size(metric);
for i=1:(a/6)
temp=fscanf(f2,'%g',6);
if(abs(temp)<=1000000000000000000000000.0)
%chair1(i,:)=temp;
chair1(i,1:length(temp))=temp;
else
chair1(i,:)=0;
end
end
%size(tor)
%size(tor)
[nchair11,nchair12,nchair13,nchair14,nchair15,nchair16]=func(chair1);
fclose(f2);