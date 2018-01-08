klucze = xlsread('baza.xlsx');
filename = 'baza.xlsx';

sim vipbarcoderecognition
A = kod;

lp = (kod(1,1)*100 + kod(1,2)*10 + kod(1,3));

% klucz odpowiedzi
klucz = klucze(lp,25);

B = num2str(klucz)- '0';

c=0;
o=0;

stopien = 0;

while c<9
 if A(1,(c+4)) == B(1,(c+1))
    o=o+1; 
 end
    c=c+1;  
end

if o<4
    stopien = 2;
elseif o==4
    stopien = 3;
elseif o==5
    stopien = 3.5;
elseif o==6
    stopien = 4;
elseif o==7
    stopien = 4.5;
elseif o==8
    stopien = 4.75;
elseif o==9
    stopien = 5;
end

in = 'I';
z = num2str(lp+1);
ko = [in,z];

xlswrite(filename,stopien,1,ko); 

close all

h = figure;
hold on

text(0.7,0.5,num2str(stopien),'FontSize',22);
text(0.7,1,baza(lp,1),'FontSize',22);
text(0.7,1.8,baza(lp,2),'FontSize',22);
text(0.7,1.4,baza(lp,3),'FontSize',22);
plot(h);

run ocena29