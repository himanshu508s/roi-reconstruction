function [ntor1,ntor2,ntor3,ntor4,ntor5,ntor6] =func(tor)
tor1=tor(:,1);
tor2=tor(:,2);
tor3=tor(:,3);
tor4=tor(:,4);
tor5=tor(:,5);
tor6=tor(:,6);
ntor1=tor1/(max(abs(tor1)));
ntor2=tor2/(max(abs(tor2)));
ntor3=tor3/(max(abs(tor3)));
ntor4=tor4/(max(abs(tor4)));
ntor5=tor5/(max(abs(tor5)));
ntor6=tor6/(max(abs(tor6)));
% result(1,:)=ntor1;
% result(2,:)=ntor2;
% result(3,:)=ntor3;
% result(4,:)=ntor4;
% result(5,:)=ntor5;
% result(6,:)=ntor6;
%return result;
end
