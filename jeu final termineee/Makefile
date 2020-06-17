programme:main.o menu.o background.o evan.o scrolling.o mouvment.o animation.o objet.o enigme.o cbb.o enigme.o gesenigme.o effet.o ennemie.o cpp.o gestionvie.o arduino.o pmap.o mutli.o enigme2.o
	gcc main.o menu.o background.o evan.o scrolling.o mouvment.o animation.o objet.o cbb.o enigme.o gesenigme.o ennemie.o effet.o cpp.o gestionvie.o arduino.o pmap.o mutli.o enigme2.o -o programme -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -g
main.o:main.c
	gcc -c main.c -g 
menu.o:menu.c
	gcc -c menu.c -g
background.o:background.c 
	gcc -c background.c -g
evan.o:evan.c
	gcc -c evan.c -g
scrolling.o:scrolling.c
	gcc -c scrolling.c -g
mouvment.o:mouvment.c
	gcc -c mouvment.c -g
animation.o:animation.c
	gcc -c animation.c -g
objet.o:objet.c
	gcc -c objet.c -g
cbb.o:cbb.c
	gcc -c cbb.c -g 
enigme.o:enigme.c
	gcc -c enigme.c -g 
gesenigme.o:gesenigme.c
	gcc -c gesenigme.c -g 
ennemie.o:ennemie.c
	gcc -c ennemie.c -g 
cpp.o:cpp.c
	gcc -c cpp.c -g 
gestionvie.o:gestionvie.c
	gcc -c gestionvie.c -g 
effet.o:effet.c
	gcc -c effet.c -g 
arduino.o:arduino.c
	gcc -c arduino.c -g
pmap.o:pmap.c
	gcc -c pmap.c -g
mutli.o:mutli.c
	gcc -c mutli.c -g
enigme2.o:enigme2.c
	gcc -c enigme2.c -g

clean:
	rm -fr *.o
mrproper:clean
	rm -f programme
