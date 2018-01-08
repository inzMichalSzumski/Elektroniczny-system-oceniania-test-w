c = 0;

while c == 0
    sim vipbarcoderecognition
    a = kod;
    run string2.m  
end

while c ~= 0  
    u = find (Nralbumu == c);
    run nkarta9.m
    sim vipbarcoderecognition
    a = kod;
    run string2.m;
end