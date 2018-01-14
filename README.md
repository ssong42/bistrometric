# bistrometric
The goal of the project is to write a program able to display the result of the evaluation 
of an arithmetic expression composed of numbers with infinite size expressed in any base, 
if GNU’s bc can handle the size, your program should too.

Usage : ./calc base input_size.

Examples :
$>echo  | ./calc
$>echo "3+6" | ./calc 0123456789 3 ;
9
$>echo "--++-6(12)" | ./calc 0123456789 10 ;
syntax error
$>echo "++--6*12" | ./calc 0123456789 8 | cat -e ;
72$
$>echo "-(12-(4*32))" | ./calc 0123456789 12 | cat -e ;
116$
$>echo "-(12-(4*32)"  | ./calc 0123456789 11 | cat -e ;
syntax error
$>echo "-(@-(;*\!@))"  | ./calc "~^@\!;i &[]" 12 | cat -e ;
^@ $
$>echo "-(12*(13+15/5*(6/(12+14%(30%5+(10*25)-46)+16)-20)/43)*20)*(-(12-98*42)*(16+63-50/3))"  | ./calc
     "0123456789" 84 | cat -e ;
-744629760$
