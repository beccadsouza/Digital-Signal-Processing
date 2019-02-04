n=-8:6;

x=[0 0 -2 -1 0 1 2 3 4 4 4 4 4 0 0];

subplot(3,1,1);
stem(n,x);
title('Signal x(n)');

subplot(3,1,2);
stem(-n,x);
title('Folded signal y(n) = x(-n)');


subplot(3,1,3);
stem(n/2,x);
title('Time scaled signal y(n) = x(2n)');

print -dpng figure.png
