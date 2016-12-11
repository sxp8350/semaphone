res: control.c
	gcc control.c -o res
	gcc write.c -o writ

clean:
	rm res
	rm writ
	rm *~
	rm *dump 
	rm *txt
