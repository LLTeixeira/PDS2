Rede Social para eventos permite que usuários:
- Criem posts
- Compartilhem posts
- Comentar de posts

Recursos:
- Inscrição
- Comentários
- Avaliações
- Notificações

Fluxo de Execução:
=> printar Painel Inicial;
Painel Inicial:
[0] Sair
[1] Criar conta
[2] Entrar na conta


=> Se [1]: Cria conta e volta para o Painel Inicial;

=> Se [2] Entrar em conta:
	- Checar se conta existe. Caso não, alertar e voltar ao fluxo inicial;
	- Printar id_conta, num_seguindo, num_seguidores;
	- Caso siga pessoas que poste algo, mostrar os 3 posts com maior score de avaliação, senão, partir pro próximo passo;
		-> Ordenar pelos posts com maior rank dos seguidores, e, em seguida, dos com maiores ranks da rede social
		-> Caso não tenha posts de pessoas seguindo (ex. a 1° conta), mostrar os posts com maior rank no geral.
	- printar Painel Principal
	
	Painel Principal:
	[0] Voltar (Retornar ao Painel Inicial)
	[1] Ver mais post {qtd_posts}
		-> Ordenar pelos posts mais recentes (primeiro de quem segue, depois dos ranks gerais)
			# Caso n siga a ideia acima: Ordenar pelos posts com maior rank de seguindo, e, em seguida, dos com maiores ranks da rede social
		-> Todos os posts vistos serão removidos da pilha_posts_pra_exibir e adicionados à pilha_posts_vistos
		-> Exibir "Painel Principal" no final
	[2] Ver posts anteriores {qtd_posts}
		-> Exibirá a qtd_posts já vistos
		-> A pilha_posts_vistos será zerada sempre que criar um novo post
	[3] Criar um post
		-> Escrever uma mensagem 
		-> Enviar mensagem (definir uma tecla pra enviar a msg)
		-> Notificar seguidores (salvar post no vetor posts_notificacoes de cada conta dos seguidores)
		-> Retornar ao painel Principal
	[4] Entrar no post (id_post) 
		-> Exibir "Painel Post"
		Painel Post:
			[0] Voltar (Retornar ao Painel Principal)
			[1] Comentar 
			[2] Ver comentários do Post
			[3] Seguir / Parar de seguir o Dono
			[4] Avaliar
			[5] Compartilhar
				-> Criar um novo post contendo:
					- Uma mensagem de quem tá compartilhando e, embaixo, as infos do post compartilhado
	[5] Seguir / parar de seguir alguma conta 
	[6] Mostrar seguindo / seguidores
		-> Printa qtd de cada 
		-> Exibir "Painel Principal"
	[7] Notificações {qtd_notificacoes_nao_vistas}
		-> Mostrar todos posts que foram notificados
		-> Exibir "Painel Notificação"
		Painel Notificação:
			[0] Voltar (Retornar ao Painel Principal)
			[1] Entrar no post (id_post)
			-> Exibir "Painel Post Notificação"  (Analisar se vale mesmo criá-lo, talvez algo por referência dentro do RedeSocial)
			Painel Post Notificação:
				[0] Voltar (Retornar ao Painel Notificação)
				[1] Comentar 
				[2] Ver comentários do Post
				[3] Seguir / Parar de seguir o Dono
				[4] Avaliar
				[5] Compartilhar
					-> Criar um novo post contendo:
						- Uma mensagem de quem tá compartilhando e, embaixo, as infos do post compartilhado


Obs.:
- Sobre os paineis, vale:
	. Criarmos classes para cada Painel
	. Na RedeSocial, criar um objeto pilha para salvar os paineis (isso para saber pra qual painel exibir assim que escolher a opção 0).
		Ex: Supor que estamos no Painel Post, então a pilha será: [PainelInicial, PainelPrincipal, PainelPost]
		Ex: Supor que estamos no Painel Post da Notificacao: [PainelInicial, PainelPrincipal, Painel Notificação, PainelPost]
