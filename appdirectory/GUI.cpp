#include "GUI.h"

template <typename T>
  std::string NumberToString ( T Number )
  {
    std::ostringstream ss;
    ss << Number;
    return ss.str();
  }

//---------------------------------------------------------------------------
GUI::GUI(void)
{
	score = 0;

	mRenderer = &CEGUI::OgreRenderer::bootstrapSystem();

	CEGUI::ImageManager::setImagesetDefaultResourceGroup("Imagesets");
	CEGUI::Font::setDefaultResourceGroup("Fonts");
	CEGUI::Scheme::setDefaultResourceGroup("Schemes");
	CEGUI::WidgetLookManager::setDefaultResourceGroup("LookNFeel");
	CEGUI::WindowManager::setDefaultResourceGroup("Layouts");

	CEGUI::SchemeManager::getSingleton().createFromFile("TaharezLook.scheme"); 

	CEGUI::System::getSingleton().getDefaultGUIContext().getMouseCursor().setDefaultImage("TaharezLook/MouseArrow");
	CEGUI::WindowManager &wmgr = CEGUI::WindowManager::getSingleton();
	sheet = wmgr.createWindow("DefaultWindow", "Raquetball/Sheet");
	scoreBox = wmgr.createWindow("TaharezLook/StaticText", "Raquetball/Pause/PauseMenu/Sound");
	scoreBox->setText("Score: 0");
	scoreBox->setSize(CEGUI::USize(CEGUI::UDim(0.1, 0), CEGUI::UDim(0.05, 0)));
	scoreBox->setPosition(CEGUI::Vector2<CEGUI::UDim>(CEGUI::UDim(0.9,0), CEGUI::UDim(0,0)));
	sheet->addChild(scoreBox);
	scoreBox->setText("Score: 0");           
	CEGUI::System::getSingleton().getDefaultGUIContext().setRootWindow(sheet);
}
//---------------------------------------------------------------------------
GUI::~GUI(void)
{
}

void GUI::incrementScore()
{
	score++;
	scoreBox->setText("Score: " + NumberToString(score));
}