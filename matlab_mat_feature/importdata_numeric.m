% 
% prompt = 'Enter number of subfolders present:';
% N = input(prompt);
% % prompt = 'Enter directory name:';
% % str = input(prompt,'s');
% %N=7;
% %dir = sprintfc('hand%d',1:N);
% % strcat('hand', num2str(i))
% for x=1:N 
% %prompt = 'Enter directory name:';
% %str = input(prompt,'s');
% %str = strcat('F:\\3DCategorizaton\\build\\',result)
% result =num2str(x);
% if exist(result,'dir')
%     cd(result)
% else
%     continue;
% end
%cd ..
% tic
points = dlmread('points.txt');
metric = dlmread('metric.txt');
inv_metric = dlmread('inv_metric.txt');
affine = dlmread('affine.txt');
% T = toc;
% pause(2-T)
affine_norm
normalization
data
point
 eval([ 'ref_roi' num2str(1) ' = chair1;' ]);
%rename(chair1,'result1');
%cd ..
if exist('classdata.mat','file')
    
save('classdata.mat',strcat('ref_roi', num2str(1)),'-append')
clear
else
    
    save('classdata',strcat('ref_roi', num2str(1)))
clear
end
% end
% i=0;
% %A(7,1) = zeros;
% S = load('classdata.mat');
% for f = fieldnames(S)
%    
%     disp(['Field named: ' f{1} ]);
%    disp('Has value ')
%    A = [A,S.(f{1})];
%    %disp(S.(f{1}));
% end

      
% matObj = matfile('classdata.mat');
% myvars = who(matObj);
% for i=1:length(myvars)
%     disp(myvars{i})
%     %myfunction(eval(myvars(i)))
% end