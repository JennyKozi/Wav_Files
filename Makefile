all: wavproc1 wavproc2 wavproc3 wavproc4 wavproc5 wavproc6 wavproc7

wavproc1:
	gcc -DMODE=1 -o wavproc1 wavproc.c -lm

wavproc2:
	gcc -DMODE=2 -o wavproc2 wavproc.c -lm

wavproc3:
	gcc -DMODE=3 -o wavproc3 wavproc.c -lm

wavproc4:
	gcc -DMODE=4 -o wavproc4 wavproc.c -lm

wavproc5:
	gcc -DMODE=5 -o wavproc5 wavproc.c -lm

wavproc6:
	gcc -DMODE=6 -o wavproc6 wavproc.c -lm

wavproc7:
	gcc -DMODE=7 -o wavproc7 wavproc.c -lm

clean:
	rm -rf wavproc1 wavproc2 wavproc3 wavproc4 wavproc5 wavproc6 wavproc7