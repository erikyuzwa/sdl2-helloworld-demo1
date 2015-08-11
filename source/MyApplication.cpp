
#include "MyApplication.h"

MyApplication::MyApplication() : SysCore() {

	label1 = NULL;
	sprite1 = NULL;

}

MyApplication::~MyApplication() {
}

int MyApplication::startupApp() {

	//setup our TTF font
	mainFont->loadFont("console", "../../../assets/fonts/04b_03__.ttf", 18);
    
	SDL_Color yellow = { 255, 255, 0 };
	label1 = mainFont->generateTextLabel("console", "press 1-5 number keys", yellow);

	sprite1 = new SysSprite();
	sprite1->loadImage("../../../assets/images/sample.png", mainRenderer);

	mainAudio->loadMusic("bg", "../../../assets/music/Crazy_Games_-_02_-_Wake_Up.ogg");
	mainAudio->playMusic("bg");

	mainAudio->loadSound("sound5", "../../../assets/sounds/5.ogg");
	mainAudio->loadSound("sound4", "../../../assets/sounds/4.ogg");
	mainAudio->loadSound("sound3", "../../../assets/sounds/3.ogg");
	mainAudio->loadSound("sound2", "../../../assets/sounds/2.ogg");
	mainAudio->loadSound("sound1", "../../../assets/sounds/1.ogg");


	return 0;
}

int MyApplication::handleInputKeys(SDL_Event* keyboardEvent){

	if (keyboardEvent->type == SDL_KEYUP){
		switch (keyboardEvent->key.keysym.sym){
		    case SDLK_q:
				return -1;
			break;
			case SDLK_1:
				mainAudio->playSound("sound1");
			break;
			case SDLK_2:
				mainAudio->playSound("sound2");
			break;
			case SDLK_3:
				mainAudio->playSound("sound3");
			break;
			case SDLK_4:
				mainAudio->playSound("sound4");
			break;
			case SDLK_5:
				mainAudio->playSound("sound5");
			break;
		}
		
	}


	return 0;
}

void MyApplication::updateApp(Uint32 delta) {

	SDL_Rect labelCoords = {10, 10, 400, 30};
	SDL_RenderCopy(mainRenderer, label1->data, nullptr, &labelCoords);

	SDL_Rect imageCoords = { 200, 200, 450, 300 };
	SDL_RenderCopy(mainRenderer, sprite1->getImageData(), nullptr, &imageCoords);

}

void MyApplication::shutdownApp() {

	//cleanup our SysSprite
	if (sprite1) {
		delete sprite1;
	}

}