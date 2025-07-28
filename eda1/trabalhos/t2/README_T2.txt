Autor (individual): Isaac Menezes Pereira, 190088885.

--> Romantissismo:
Dessa vez, sua saga com marmitas continua, mas agora o objetivo é ir até o RU da universidade para se alimentar?
Haverá marmitas o suficiente? Se não, processe o chefe!

Você terá em mãos um mapa com todos os caminhos possíveis para ir ao RU. Você deve definir onde é o RU. 
Os endereços disponíveis são 1 a 9.

--> Instruções para compilação e execução:
Compilar: gcc -Wall t2.c ponderedGraph_adjacentMatrixHeader.c -lm -o t2.x
Rodar: ./t2.x
Observação: os arquivos ponderedGraph_adjacentMatrixHeader.c e ponderedGraph_adjacentMatrixHeader.h devem 
estar no mesmo diretório que t2.c, caso contrário, o caminhos desses arquivos devem ser adicionados no comando de 
compilação.

--> Melhores explicações:
Um grafo ponderado com 10 vértices é gerado e 45% do elementos da matriz de adjacência são preenchidos com valores aleatórios 
em posições aleatórias. Em seguida, um DFS é implementado infomando todos os possíveis caminhos do ponto A (fixado em 0) e 
B (a localidade do RU) escolhido pelo usuário. Como o grafo possui 10 arestas, o usuário pode escolher entre 1 e 9 para a 
localidade do RU. Após a escolha, o DFS mostra todos os caminhos possíveis e os pesos de cada um. Ao escolher um caminho 
(informando o número do caminho em questão; se o caminho 10, 12 ou 98, caso eventualmente existam) o código gera dois números 
aletórios, o primeiro para a quantidade de marmitas que o RU produziria e, o segundo, a primeira quantidade de estudantes que 
iriam no dia. Se sobrarem marmitas, 'printf("Tem marmita!")' e você compraria sua marmita e não processaria o chefe, caso ainda 
hajam marmitas assim que você chegar no RU. Se faltarem marmitas, 'printf("Pode processar")' e você seguiria a ordem. Se a 
quantidade de marmitas for igual a dos estudantes: 'printf("Pode processar")'.
Você precisa chegar a tempo no RU antes que as marmitas acabem. Cada estudante pega uma marmita a cada unidade de tempo. Uma 
unidade de tempo é igual a uma unidade de distância. 
Cada caminho possui um custo e você anda uma unidade de caminho a cada unidade de tempo. Por exemplo, se forem produzidas 
145 marmitas e comparecerem ao RU 98 alunos, sobram, então, 45 marmitas que ainda serão consumidas pelos demais alunos, mas 
você não tem essa informação. Então, caso escolha um caminho de peso 86, você andaria 86 unidades de tempo, mas o restante das 
marmitas seriam consumidas em 45 unidades de tempo, o que implica falta de marmita para você. Processe!

OBS.: são poucos vértices, mas, eventualmente, muitos caminhos.

--> Uma dica de fluxo:
É simples.
- Escolha o vértice 7.
- Depois, suponhamos, o caminho 9.
- Por fim, você descobre se tem marmitas ou, por não ter, visualiza a ordem para processar! 