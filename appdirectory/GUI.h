#ifndef __GUI_h_
#include "BaseApplication.h"
 
#include <CEGUI/CEGUI.h>								  //or this:
#include <CEGUI/RendererModules/Ogre/CEGUIOgreRenderer.h> //<Ogre/Renderer.h>
#include "CEGUI-0.8.7/cegui/include" // /GEGUI

class GUI 
{
	public:
		GUI(void);
		~GUI(void);
		void initObjects(void);

	protected:

	private:
};

#endif // #ifndef __GUI_h_