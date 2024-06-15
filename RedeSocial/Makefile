# Makefile

# Variáveis
CXX = g++
CXXFLAGS = -std=c++11

# Arquivos fonte
SRCS = RedeSocial.cpp Conta.cpp Comentario.cpp Post.cpp

# Arquivo executável
TARGET = rede_social.out

# Regra de construção do executável
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Regra para limpar arquivos temporários e o executável
clean:
	rm -f $(TARGET)