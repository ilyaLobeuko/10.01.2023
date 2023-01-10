#pragma once
#include "SFML/Graphics.hpp"
#include "bat.h"
#include "game.h"

void checkEvents(sf::RenderWindow& window) {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void updateGame(Bat& bat) {
	batControl(bat);
	batReboundEdges(bat);
}

void checkCollisions() {}



void initBall(Ball& ball)
{
	ball.shape.setRadius(BALL_RADIUS);
	ball.shape.setFillColor(BALL_COLOR);
	ball.shape.setPosition(BALL_START_POS);
	float arr_speed[]{ -5.f,-4.f,-3.f,-2.f,-1.f,1.f,2.f,3.f,4.f,5.f };
	int index = rand() % 10;
	ball.speedX = arr_speed[index];
	index = rand() % 10;
	ball.speedY = arr_speed[index];
}
void drawGame(sf::RenderWindow& window, Bat& bat, Ball& ball) {
	window.clear();
	batDraw(window, bat);
	window.display();
}
