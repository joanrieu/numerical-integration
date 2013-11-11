set title font ",30"
set tics font ",10"
unset key

set multiplot layout 2,2

set title "Lorenz: chaotic, r = 28"
splot '<./lorenz' using "x":"y":"z":"t" with lines linecolor palette
set title "Lorenz: r = 10"
splot '<./lorenz 10' using "x":"y":"z":"t" with lines linecolor palette
set title "Lorenz: r = 5"
splot '<./lorenz 5' using "x":"y":"z":"t" with lines linecolor palette

set title "Brusselator: a = 1, b = 3"
plot '<./brusselator' using "x":"y":"t" with lines linecolor palette
