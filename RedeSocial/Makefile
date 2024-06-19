# Makefile

# Variáveis
CXX = g++
CXXFLAGS = -std=c++11

# Arquivos fonte
SRCS = main.cpp RedeSocial.cpp Conta.cpp Comentario.cpp Post.cpp Gerenciador.cpp Painel.cpp

# Arquivo executável
TARGET = rede_social.out

# Regra de construção do executável
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Regra para limpar arquivos temporários e o executável
clean:
	rm -f $(TARGET)