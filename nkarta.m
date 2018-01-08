%dane
close all

%drukowanie tabeli
y=[0 0; 1 1; 2 2; 3 3; 4 4; 5 5; 6 6; 7 7; 8 8; 9 9; 10 10; 11 11; 12 12; 13 13];
x=[0 6];
x2=[1 1; 2 2; 3 3; 4 4; 5 5; 6 6];
y2=[0 13];
h = figure;
hold on
g = line(x,y);
f = line(x2,y2);
set(g,'Color','black','LineWidth',1);
set(f,'Color','black','LineWidth',1);
%legenda
text(0.5,-0.7,'poprawnie  -  x     niepoprawnie - x');
text(0.475,-0.75,'                                                O');
%drukowanie numerow zadan
p = randperm(40,12);
B = sort(p);

text(0.5,0.5,num2str(B(1,12)));
text(0.5,1.5,num2str(B(1,11)));
text(0.5,2.5,num2str(B(1,10)));
text(0.5,3.5,num2str(B(1,9)));
text(0.5,4.5,num2str(B(1,8)));
text(0.5,5.5,num2str(B(1,7)));
text(0.5,6.5,num2str(B(1,6)));
text(0.5,7.5,num2str(B(1,5)));
text(0.5,8.5,num2str(B(1,4)));
text(0.5,9.5,num2str(B(1,3)));
text(0.5,10.5,num2str(B(1,2)));
text(0.5,11.5,num2str(B(1,1)));
% drukowanie numerow odpowiedzi
text(1.5,12.5,'1');
text(2.5,12.5,'2');
text(3.5,12.5,'3');
text(4.5,12.5,'4');
%drukowanie danych

tempText = [baza(u,3),baza(u,2),baza(u,1)]; %nazwisko, imie, nr indeksu
text(0.5,14, tempText); %pozycja
text(5,14, num2str(u)); %L.p.

axis([0.5 6 0 14])
axis off

set(gcf, 'PaperUnits', 'centimeters');
set(gcf, 'PaperSize', [6 10]);
myfiguresize = [-0.6, 0, 6, 10];
set(gcf, 'PaperPosition', myfiguresize);

print(h);

%zapis klucza odpowiedzi do excela
odpowiedzi = xlsread('odpowiedzi.xlsx');

i=11;
k=0;
j=0;

while i>=0
  t=B(1,i+1);
  j=j+((odpowiedzi(t,2))*(10.^(k)));
  i=i-1;
  k=k+1;
end

w='Z';
v=[w,(num2str(u+1))];
filename = 'baza.xlsx';
xlswrite(filename,j,1,num2str(v));