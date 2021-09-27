function [ntor1] =nor(tor,i)
tor1=tor(:,i);
ntor1=tor1/(max(abs(tor1)));  
end