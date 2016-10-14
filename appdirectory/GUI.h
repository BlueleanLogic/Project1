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

	private:
    	CEGUI::OgreRenderer* mRenderer;
		int score;
		CEGUI::Window *scoreBox;
   		CEGUI::Window *sheet;
};

#endif // #ifndef __GUI_h_