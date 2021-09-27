%-- 6/29/2015 3:45 PM --%
% import_numeric
% importdata_numeric
% load('classdata.mat', 'cone100001')
% hist(candle1_1);figure(gcf);
%importdata_numeric
% load('F:\Research\Inpainting(30-6-2015)\Decomposition\Cone10000\cone10000.mat')
% load('F:\Research\Inpainting(30-6-2015)\Decomposition\Cylinder10000\cylinder10000.mat')
% load('sphere10000.mat')
train_set = [yali1_1;yali2_1];
ccat0(1:length(yali1_1),1) = 1;
ccat2(1:length(yali2_1),1) = 2;
% ccat5(1:length(yali2_1),1) = 3;


train_label = [ccat0;ccat2];
addpath('E:\REU\libsvm-3.20\windows');
model_example_yali = svmtrain(train_label, train_set, '-s 0 -c 100 -t 1 -g 1 -r 1 -d 3 -h 0');
% load('bunnyzipped2.mat')
% [sph,con,cyl] = segment(bunnyzipped21,model);
