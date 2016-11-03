#include "GUI.h"

template <typename T>
  std::string NumberToString ( T Number )
  {
    std::ostringstream ss;
    ss << Number;
    return ss.str();
  }

//---------------------------------------------------------------------------

// enum class GameState {Gui, Play};
// GameState gameMode;

GUI::GUI(void)
:mShutDown(false),
isServer(false),
isClient(false),
stategui(true),
startingSinglePlayer(false),
startingMultiPlayer(false),
playingSingle(false),
playingServer(false),
playingClient(false)
{
	score = 0;
	score2 = 0;
  highScore = 0;
  // stategui = true;
	mRenderer = &CEGUI::OgreRenderer::bootstrapSystem();

	CEGUI::ImageManager::setImagesetDefaultResourceGroup("Imagesets");
	CEGUI::Font::setDefaultResourceGroup("Fonts");
	CEGUI::Scheme::setDefaultResourceGroup("Schemes");
	CEGUI::WidgetLookManager::setDefaultResourceGroup("LookNFeel");
	CEGUI::WindowManager::setDefaultResourceGroup("Layouts");

	CEGUI::SchemeManager::getSingleton().createFromFile("TaharezLook.scheme"); 

	CEGUI::System::getSingleton().getDefaultGUIContext().getMouseCursor().setDefaultImage("TaharezLook/MouseArrow");
	CEGUI::WindowManager &wmgr = CEGUI::WindowManager::getSingleton();
	sheet = wmgr.createWindow("DefaultWindow", "Volleyball/Sheet");

	menu = wmgr.createWindow("TaharezLook/FrameWindow", "Volleyball/Menu");
  menu->setSize(CEGUI::USize(CEGUI::UDim(0.4, 0), CEGUI::UDim(0.3, 0)));
  menu->setPosition(CEGUI::Vector2<CEGUI::UDim>(CEGUI::UDim(0.3,0), CEGUI::UDim(0.25,0)));

  CEGUI::Window *onePlayer = wmgr.createWindow("TaharezLook/Button", "Volleyball/Menu/OnePlayer");
  onePlayer->setText("Single Player Mode");
  onePlayer->setSize(CEGUI::USize(CEGUI::UDim(0.75, 0), CEGUI::UDim(0.16, 0)));
  onePlayer->setPosition(CEGUI::Vector2<CEGUI::UDim>(CEGUI::UDim(0.125,0), CEGUI::UDim(0.02,0)));
  menu->addChild(onePlayer);

  //the two-player game button
  CEGUI::Window *twoPlayer = wmgr.createWindow("TaharezLook/Button", "Volleyball/Menu/TwoPlayer");
  twoPlayer->setText("Multiplayer Player Mode");
  twoPlayer->setSize(CEGUI::USize(CEGUI::UDim(0.75, 0), CEGUI::UDim(0.16, 0)));
  twoPlayer->setPosition(CEGUI::Vector2<CEGUI::UDim>(CEGUI::UDim(0.125,0), CEGUI::UDim(0.22,0)));
  menu->addChild(twoPlayer);

  CEGUI::Window *sound = wmgr.createWindow("TaharezLook/Button", "Volleyball/Menu/Sound");
  sound->setText("Disable Sound");
  sound->setSize(CEGUI::USize(CEGUI::UDim(0.75, 0), CEGUI::UDim(0.16, 0)));
  sound->setPosition(CEGUI::Vector2<CEGUI::UDim>(CEGUI::UDim(0.125,0), CEGUI::UDim(0.42,0)));
  menu->addChild(sound);

  CEGUI::Window *quit = wmgr.createWindow("TaharezLook/Button", "Volleyball/Menu/Quit");
  quit->setText("Quit");
  quit->setSize(CEGUI::USize(CEGUI::UDim(0.75, 0), CEGUI::UDim(0.16, 0)));
  quit->setPosition(CEGUI::Vector2<CEGUI::UDim>(CEGUI::UDim(0.125,0), CEGUI::UDim(0.62,0)));
  menu->addChild(quit);

  scoreBox = wmgr.createWindow("TaharezLook/StaticText", "Volleyball/Game");
  scoreBox->setText("Score: 0");
  scoreBox->setSize(CEGUI::USize(CEGUI::UDim(0.2, 0), CEGUI::UDim(0.05, 0)));
  scoreBox->setPosition(CEGUI::Vector2<CEGUI::UDim>(CEGUI::UDim(.35,0), CEGUI::UDim(0,0)));

  multiMenu = wmgr.createWindow("TaharezLook/FrameWindow", "Volleyball/Menu/MultiplayerMenu");
  multiMenu->setSize(CEGUI::USize(CEGUI::UDim(0.4, 0), CEGUI::UDim(0.5, 0)));
  multiMenu->setPosition(CEGUI::Vector2<CEGUI::UDim>(CEGUI::UDim(0.3,0), CEGUI::UDim(0.25,0)));

  CEGUI::Window *server = wmgr.createWindow("TaharezLook/Button", "Volleyball/Menu/Sound");
  server->setText("Start Server");
  server->setSize(CEGUI::USize(CEGUI::UDim(0.75, 0), CEGUI::UDim(0.16, 0)));
  server->setPosition(CEGUI::Vector2<CEGUI::UDim>(CEGUI::UDim(0.125,0), CEGUI::UDim(0.02,0)));
  multiMenu->addChild(server);

  CEGUI::Window *client = wmgr.createWindow("TaharezLook/Button", "Volleyball/Menu/Sound");
  client->setText("Connect to server");
  client->setSize(CEGUI::USize(CEGUI::UDim(0.75, 0), CEGUI::UDim(0.16, 0)));
  client->setPosition(CEGUI::Vector2<CEGUI::UDim>(CEGUI::UDim(0.125,0), CEGUI::UDim(0.22,0)));
  multiMenu->addChild(client);

  hostIP = wmgr.createWindow("TaharezLook/FrameWindow", "Volleyball/Menu/MultiplayerMenu/hostIP");
  hostIP->setSize(CEGUI::USize(CEGUI::UDim(0.4, 0), CEGUI::UDim(0.5, 0)));
  hostIP->setPosition(CEGUI::Vector2<CEGUI::UDim>(CEGUI::UDim(0.3,0), CEGUI::UDim(0.25,0)));

  editBox = wmgr.createWindow("TaharezLook/Editbox", "Volleyball/Menu/MultiplayerMenu/hostIP/Editbox");
  editBox->setSize(CEGUI::USize(CEGUI::UDim(0.75, 0), CEGUI::UDim(0.2, 0)));
  editBox->setPosition(CEGUI::Vector2<CEGUI::UDim>(CEGUI::UDim(0.125,0), CEGUI::UDim(0.16,0)));
  hostIP->addChild(editBox);

  CEGUI::Window *search = wmgr.createWindow("TaharezLook/Button", "Volleyball/Menu/MultiplayerMenu/hostIP/Search");
  search->setText("Search Host IP");
  search->setSize(CEGUI::USize(CEGUI::UDim(0.75, 0), CEGUI::UDim(0.2, 0)));
  search->setPosition(CEGUI::Vector2<CEGUI::UDim>(CEGUI::UDim(0.125,0), CEGUI::UDim(0.4,0)));
  hostIP->addChild(search);

  CEGUI::Window *clientBack = wmgr.createWindow("TaharezLook/Button", "Volleyball/Menu/MultiplayerMenu/hostIP/Back");
  clientBack->setText("Back");
  clientBack->setSize(CEGUI::USize(CEGUI::UDim(0.75, 0), CEGUI::UDim(0.2, 0)));
  clientBack->setPosition(CEGUI::Vector2<CEGUI::UDim>(CEGUI::UDim(0.125,0), CEGUI::UDim(0.64,0)));
  hostIP->addChild(clientBack);

  CEGUI::Window *multiback = wmgr.createWindow("TaharezLook/Button", "Volleyball/Menu/Sound");
  multiback->setText("Back");
  multiback->setSize(CEGUI::USize(CEGUI::UDim(0.75, 0), CEGUI::UDim(0.16, 0)));
  multiback->setPosition(CEGUI::Vector2<CEGUI::UDim>(CEGUI::UDim(0.125,0), CEGUI::UDim(0.42,0)));
  multiMenu->addChild(multiback);




	CEGUI::System::getSingleton().getDefaultGUIContext().setRootWindow(sheet);
	sheet->       addChild(menu);
	onePlayer->   subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&GUI::startSinglePlayer, this));
	twoPlayer->   subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&GUI::startMultiPlayer,  this));
  quit->        subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&GUI::quit, this));  
  multiback->   subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&GUI::multiBack, this));  
  server->      subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&GUI::startServer, this));  
  clientBack->  subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&GUI::clientBack, this)); 
  client->      subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&GUI::clientStart, this)); 
  search->      subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&GUI::searchIP, this)); 

}
//---------------------------------------------------------------------------
GUI::~GUI(void)
{
}

void GUI::incrementScore()
{
	score++;
  if (score > highScore)
    highScore = score;
	scoreBox->setText("Score: " + NumberToString(score) + "  High Score: " + NumberToString(highScore));
}

void GUI::resetScore() {
  score = 0;
  scoreBox->setText("Score: " + NumberToString(score) + "  High Score: " + NumberToString(highScore));
}

void GUI::player1Win(bool win)
{
	if (win){ 
		score++;
	}
	else
	{
		score2++;
	}
	scoreBox->setText("Player 1: " + NumberToString(score) + " Player 2: " + NumberToString(score2));
}


bool GUI::clientBack(const CEGUI::EventArgs &e){
  sheet->removeChild(hostIP);
  sheet->addChild(multiMenu);
  return true;
}

bool GUI::startMultiPlayer(const CEGUI::EventArgs &e)
{
  sheet->removeChild(menu);
  sheet->addChild(multiMenu);
  return true;
}

bool GUI::startSinglePlayer(const CEGUI::EventArgs &e)
{
  // sheet->addChild(pause);
  sheet->addChild(scoreBox);
  sheet->removeChild(menu);
  stategui = false;
  startingSinglePlayer = true;
  return true;
}

bool GUI::clientStart(const CEGUI::EventArgs &e){
  sheet->addChild(hostIP);
  sheet->removeChild(multiMenu);
  return true;
}

bool GUI::quit(const CEGUI::EventArgs &e)
{
  mShutDown = true;
  return true;
}

bool GUI::multiBack(const CEGUI::EventArgs &e) {
  sheet->addChild(menu);
  sheet->removeChild(multiMenu);
  return true;
}

bool GUI::isGui(){
  return stategui == true;
}

bool GUI::startServer(const CEGUI::EventArgs &e){
  isServer = true;
  return true;
}

bool GUI::searchIP(const CEGUI::EventArgs &e)
{
  address = editBox->getText();
  isClient = true;
  printf(address.c_str());
  printf("\n");


  return true;
}

void GUI::startServerGame(){
  sheet->addChild(scoreBox);
  sheet->removeChild(multiMenu);
}

void GUI::startClientGame(){
  sheet->addChild(scoreBox);
  sheet->removeChild(hostIP);
}


// void GUI::stopServer(){
//   isServer = false;
// }