function [e1,e2,e3]= segment1(samp,categ)
addpath('E:\REU\libsvm-3.20\windows');
[a b]=size(samp);
class=zeros(a,1);
[pred accuracy dec_values] = svmpredict(class, samp, categ);
%pred=pred';
[a b]=size(pred);
j=1;
k=1;
m=1;

%Initialization
e1(j,:)=zeros(size(samp(1,:)));
e2(k,:)=zeros(size(samp(1,:)));
e3(m,:)=zeros(size(samp(1,:)));

%e5(q,:)=zeros(size(samp(1,:)));
for i=1:a
    if(pred(i)==1)
        e1(j,:)=samp(i,:);
        j=j+1;
    
    elseif (pred(i)==2)
        e2(k,:)=samp(i,:);
        k=k+1;
    elseif (pred(i)==3)
        e3(m,:)=samp(i,:);
        m=m+1;
	
	%elseif (pred(i)==5)
    %   e5(q,:)=samp(i,:);
    %    q=q+1;
		
    end
    
end


  
    
file = fopen('e1.pcd', 'w');
fprintf(file, '# .PCD v.5 - Point Cloud Data file format\nVERSION .5\nFIELDS x y z\nSIZE 4 4 4\nTYPE F F F\nCOUNT 1 1 1\nWIDTH ');
eval(['fprintf(file, num2str(size(e1,1)));']);
fprintf(file, '\nHEIGHT 1\nPOINTS ');
eval(['fprintf(file, num2str(size(e1,1)));']);
fprintf(file, '\nDATA ascii\n');
fclose(file);


    space=' ';
    append='-append';
    d='delimiter';
   dlmwrite('e1.pcd',e1(:,34:36),append,d,space);
  
   
   
   
   
   
file = fopen('e2.pcd', 'w');
fprintf(file, '# .PCD v.5 - Point Cloud Data file format\nVERSION .5\nFIELDS x y z\nSIZE 4 4 4\nTYPE F F F\nCOUNT 1 1 1\nWIDTH ');
eval(['fprintf(file, num2str(size(e2,1)));']);
fprintf(file, '\nHEIGHT 1\nPOINTS ');
eval(['fprintf(file, num2str(size(e2,1)));']);
fprintf(file, '\nDATA ascii\n');
fclose(file);


    space=' ';
    append='-append';
    d='delimiter';
   dlmwrite('e2.pcd',e2(:,34:36),append,d,space);   


   
   
   file = fopen('e3.pcd', 'w');
fprintf(file, '# .PCD v.5 - Point Cloud Data file format\nVERSION .5\nFIELDS x y z\nSIZE 4 4 4\nTYPE F F F\nCOUNT 1 1 1\nWIDTH ');
eval(['fprintf(file, num2str(size(e3,1)));']);
fprintf(file, '\nHEIGHT 1\nPOINTS ');
eval(['fprintf(file, num2str(size(e3,1)));']);
fprintf(file, '\nDATA ascii\n');
fclose(file);


    space=' ';
    append='-append';
    d='delimiter';
   dlmwrite('e3.pcd',e3(:,34:36),append,d,space);
   
   

   
      
% if(size(e1)==0) e1(1,:)=0;
% elseif(size(e2)==0) e2(1,:)=0;
% elseif(size(e3)==0) e3(1,:)=0;
% end
end

