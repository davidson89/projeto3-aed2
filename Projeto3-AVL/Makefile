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
	doxygen -g
	sed -i 's/EXTRACT_PRIVATE        = NO/EXTRACT_PRIVATE        = YES/g' Doxyfile
	doxygen
	@echo "\n***** Diretório html criado, contendo toda documentação das classes *****\n"