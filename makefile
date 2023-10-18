analysis.exe: analysis.c sales_report.c
	gcc -Wall analysis.c sales_report.c -o analysis.exe

clean:
	del -f analysis.o sales_report.o analysis.exe 