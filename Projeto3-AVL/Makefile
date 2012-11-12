FLAGS = -ansi -pedantic -Wall -g -efence
CLASSES = main.cpp AVLTree.cpp Folha.cpp

# regra principal
all: lab3

# gera o executável
lab3:
	g++ -o lab3 ${CLASSES} 
	@echo "\n***** Para executar o programa digite ./lab3 nome_do_arquivo.txt *****"
	@echo "\n***** Para gerar a documentação digite make doxygen *****\n"

# remove o executável
clean:
	rm -f *.o lab3

doxygen:
	g++ ${FLAGS} -o lab3d ${CLASSES}
	doxygen -g
	doxygen
