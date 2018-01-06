;Homework5
;Abdul Samad Khan
;foo returns the sum of two integers
;myPrint prints out the list if the list is not NULL
;factorial1 finds the factorial by iterative method
;factorial2 finds the factorial by recursive method
;amount finds the number of symbol 'a' in the list
;fib finds the fibonacci sum of the given integer using recursive method
;big finds the greater number from 2 input and returns the greater value
;sum finds the sum of numbers from 0 to n
;part 10 explains the code given
;test runs all the functions

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;Part 2
(defun foo(x y) 	;functions take two variable inputs
  (+ x y) )      	;variables are added 

(print (foo 10 20))    ; output wil be 30
(print (foo 30 40))    ; output wil be 70
(print (foo 40 50))    ; output wil be 90

;java function
;public static int foo(x,y)	;functions take two variable input
;{ return x+y; }		;function returns the added value
;System.out.println(foo(10,20));	;output will be 30
;System.out.println(foo(30,40));	;output will be 70
;System.out.println(foo(40,50));	;output will be 90
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;Part 3
(defun myPrint(l)     	  	                ;myPrint function takes l list as an input
  (if (not (null l))	                        ;check if the list is not NULL
      (progn 		   	                ;to add 2 commands in if
        (print (car l))   	                ;print the first symbol of l list
        (myprint(cdr l))  	                ;again call the function myPrint this time passing list without the first symbol
        )
   )
)

(myPrint (quote (1 2 3 4 5 )))  		;output will be 1 2 3 4 5 
(myPrint (quote (6 7 8 9 0 )))			;output will be 6 7 8 9 0 	
(myPrint (quote ("a" "e" "i" "o" "u" )))	;output will be "a" "e" "i" "o" "u"

;Java function
;public static void myPrint(char[] l){	;take array as input
;if(l.length != 0){			;check if array size is 0
;System.out.println(l[0]);		;print first element of array
;char []check=new char[nums.length-1];	;create an array of size one less then the input array
;   	for(int i=1;i<nums.length;i++)	;run loop length-1 time
;      	{check[i-1]=nums[i];}		;assign value of original array to new array skipping the first element
;	myPrint(check);			; make the recursive call with the new array
;  }
;}
;
;char[] list ={'1','2','3','4','5'};	;intialize an array
;myPrint(list);				;make function call this will print 1 2 3 4 5 
;char[] list ={'6','7','8','9','0'};	;intialize an array
;myPrint(list);				;make function call this will print 6 7 8 9 0
;char[] list ={'a','e','i','o','u'};	;intialize an array
;myPrint(list);				;make function call this will print a e i o u


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;Part 4
(defun factorial1(n)				;factorial1 takes n as an input
        (let ((sum 1)) 				;define a global variable sum equal to 1
          (dotimes (i n)			;run a loop n times
		(setf sum (* sum (1+ i)))) 	;assign the product of sum and i+1 to sum  
          sum)					;return sum
)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;Part 5
(defun factorial2(n)				;factorial2 takes n as an input
	(if (<= n 1) 				;check if n is less then or equal to 1
	1					;if return 1
	(* n (factorial2 (- n 1)))))		;else return the product of n and factorial2(n-1) the recursion call
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;Part 6
(defun amount(list)				;amount takes list as an input		
	(let ((value 0))			;define a global variable equal to 0
	(dolist (x list)			;run a loop uptil the size of list
		( if (equalp x 'a)		;check if the value of list at x is equal to symbol a
		 (setf value (+ value 1)) ))	;if true do an increment to the value by 1
	value))					;return value which will give the number of a in the list
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;Part 7	
(defun fib(n)					;fib takes a number n as input
	(if (= n 0)				;if the number n = 0 
		0 				;return 0
	(if (= n 1)				;(else of first if) (new) if the number n=1
		1				;return 1
	 (+ (fib(- n 1)) (fib(- n 2))))))	;else return the sum of fib(n-1) and fib(n-2) (first else ends)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;Part 8
(defun big(a b)					;big takes two numbers as input a b
	(let ((x 0))				;global variable x is assign 0
		(if (> a b)			;if a is greater then b
			 (setf x a) 		;if true set x=a
			 (setf x b))		;else x=b
	x))					;return x
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;Part 9
(defun sum (n)					;sum takes intger n as an input
	(let ((value 0))			;global variable value is assigned 0
		(dotimes (i n)			;loop is run n times
		(setf value (+ (+ value i) 1))) ;add the value of i to value then we take this sum and add 1 to this and assign the value to value
         value)				        ;return value
)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;Part 10
(setq x '(a b))  	;setq assign list to x   ' sign represent a quote. quote is used to represent a list
(setq y '(a b c))	;setq assign list to y   ' sign represent a quote. quote is used to represent a list
(print (car x))		;print first symbol of list x. car returns a symbol
(print (car y))		;print first symbol of list y. car returns a symbol
(print (cdr x))		;print the list x without first symbol. cdr returns a list
(print (cdr y))		;print the list y without first symbol. cdr returns a list
(print (car(cdr x)))	;cdr x removes the first symbol from the list and then car takes the first symbol of the new list is printed. (car(cdr x)) returns a symbol
(print (car(cdr y)))	;cdr y removes the first symbol from the list and then car takes the first symbol of the new list is printed. (car(cdr y)) returns a symbol
(print (cadr x))	;cadr is the same as (car(cdr x)). returns a symbol
(print (cadr y))	;cadr is the same as (car(cdr y)). returns a symbol
(print (append x y))	;append concatenate the two lists in a new list 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(defun test()
	(print "CSE 240 Assignment 4. ABDUL SAMAD KHAN" )
	(print (factorial1 100))
	(print (factorial2 100))
	(print (amount '(b c (a) a)))
	(print (fib 7))
	(print (big 5 7))
	(print (sum 5))
)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(test)


