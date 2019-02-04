n=-8:6;

x=[0 0 -2 -1 0 1 2 3 4 4 4 4 4 0 0];

subplot(3,1,1);
stem(n,x);
title('Signal x(n)');

subplot(3,1,2);
stem(n+2,x);
title('Delayed signal y(n) = x(n-2)');


subplot(3,1,3);
stem(n-2,x);
title('Advanced signal y(n) = x(n+2)');

print -dpng figure.png
