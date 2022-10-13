#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Keyboard.hpp>
#include<string>
#define modWidth 300
#define mofHeight 400
using namespace sf;
int main() {


	int placarGamer1 = 0;
	int placarGamer2 = 0;
	float eixoX = 0;
	float eixoY = 0;
	float velocidade = 5;
	float dificuldade =1.5;

	RenderWindow window(VideoMode(modWidth, mofHeight), "Pong");
	window.setFramerateLimit(30);
	//Image icone;
	//icone.loadFromFile("/home/uut/Documentos/game_criado_c++/Pong/pong.png");
	//window.setIcon(200, 200, icone.getPixelsPtr());

	Font fonte;
	fonte.loadFromFile("/home/uut/Documentos/game_criado_c++/Pong/Tuffy.ttf");

	Text intro;
	intro.setFont(fonte);
	intro.setString("Pressione ENTER");
	intro.setCharacterSize(20);
	intro.setPosition(80,140);
	intro.setFillColor(Color::White);

	Text texto("", fonte);
	texto.setString(std::to_string(placarGamer1));
	texto.setCharacterSize(30);
	texto.setPosition(60, 0);

	Text texto2("", fonte);
	texto2.setString(std::to_string(placarGamer2));
	texto2.setCharacterSize(30);
	texto2.setPosition(210, 0);

	RectangleShape net(Vector2f(1, 400));
	net.setOutlineColor(Color::White);
	net.setPosition(150, 0);
	RectangleShape ball(Vector2f(10, 10));
	ball.setFillColor(Color::White);
	ball.setPosition(146, 150);

	RectangleShape gamer1(Vector2f(10, 40));
	gamer1.setFillColor(Color::Red);
	gamer1.setPosition(0, 180);

	RectangleShape gamer2(Vector2f(10, 40));
	gamer2.setFillColor(Color::Blue);
	gamer2.setPosition(290, 180); 


     Clock tempoExibicao;
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) window.close();
		}

		if(tempoExibicao.getElapsedTime().asSeconds() > 0.10f){
			intro.setFillColor(Color::White);
		}
		if(tempoExibicao.getElapsedTime().asSeconds() > 1.0f){
			intro.setFillColor(Color::Transparent);
		}

		if(tempoExibicao.getElapsedTime().asSeconds() > 1.80f){
			intro.setFillColor(Color::White);
			tempoExibicao.restart();
		}
		if(Keyboard::isKeyPressed(Keyboard::Enter)){
			intro.setPosition(-1000,-1000);
		}

		Vector2f posicaoBola = ball.getPosition();
		Vector2f posicaoGamer1 = gamer1.getPosition();
		Vector2f posicaoGamer2 = gamer2.getPosition();

		ball.move(eixoX, eixoY);

		if (posicaoBola.y < 0) eixoY = velocidade;
		else if (posicaoBola.y > 400 - 10) eixoY = -velocidade; 

		
		if (posicaoBola.y >= posicaoGamer1.y && posicaoBola.y <= posicaoGamer1.y + 40)
			if (posicaoBola.x <= posicaoGamer1.x + 10) {
				eixoX = velocidade;
			}

		if (posicaoBola.x < 0) { //placarGamer2!!
			placarGamer2 += 1;
			texto2.setString(std::to_string(placarGamer2));
			eixoX = 0;
			eixoY = 0;
			ball.setPosition(145, 200); //middle of field
			gamer2.setPosition(290, 180);
		}

		if (posicaoBola.y >= posicaoGamer2.y && posicaoBola.y <= posicaoGamer2.y + 40)
			if (posicaoBola.x > posicaoGamer2.x - 10) {
				eixoX = -velocidade;
			}

		if (posicaoBola.x > 290) {  //placarGamer1!
			placarGamer1 += 1;
			texto.setString(std::to_string(placarGamer1));
			eixoX = 0;
			eixoY = 0;
			ball.setPosition(145, 200);
			gamer2.setPosition(290, 180);
		}


		if (Keyboard::isKeyPressed(Keyboard::Enter)) {
			eixoX = velocidade,
			eixoY = velocidade;
		}

		//gamer1 go UP
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			if (gamer1.getPosition().y > 0)
			gamer1.move(0, -velocidade);
		}

		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			if (gamer1.getPosition().y < 400 - 40)
			gamer1.move(0, velocidade);
		}

		//nao ajusta... XD
		if (posicaoBola.x > 30 && eixoX > 0)
			if (posicaoGamer2.y > 0)       
				if (posicaoGamer2.y > posicaoBola.y)
					gamer2.move(0, -velocidade);

		
		if (posicaoBola.x > 30 && eixoX > 0)
			if (posicaoGamer2.y < 400 - 40)   
				if (posicaoGamer2.y < posicaoBola.y)
					gamer2.move(0, velocidade);

		window.clear();
		window.draw(net);
		window.draw(texto);
		window.draw(texto2);
		window.draw(intro);
		window.draw(gamer1);
		window.draw(gamer2);
		window.draw(ball);
		window.display();

	}
	return 0;

}