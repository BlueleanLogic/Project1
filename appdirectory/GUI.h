#ifndef __GUI_h_
#define __GUI_h_

#include <CEGUI/CEGUI.h>
#include <CEGUI/RendererModules/Ogre/Renderer.h>

//---------------------------------------------------------------------------
class GUI{

	public:
		GUI(void);
		~GUI(void);
		void incrementScore(void);
   		virtual bool quit(const CEGUI::EventArgs &e);
   		bool mShutDown;

	private:
    	CEGUI::OgreRenderer* mRenderer;
		int score;
		int score2;
		CEGUI::Window *scoreBox;
   		CEGUI::Window *sheet;
   		CEGUI::Window *menu;
   		CEGUI::Window *multiMenu;
   		// CEGUI::Window *sound;	
   		void player1Win(bool win);
   		bool startSinglePlayer(const CEGUI::EventArgs &e);
   		bool startMultiPlayer(const CEGUI::EventArgs &e);



};

#endif // #ifndef __GUI_h_