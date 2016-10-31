#ifndef __GUI_h_
#define __GUI_h_

#include <CEGUI/CEGUI.h>
#include <CEGUI/RendererModules/Ogre/Renderer.h>

// enum GameState {GUI, PLAY};
//---------------------------------------------------------------------------
class GUI{

   public:
      GUI(void);
      ~GUI(void);
      void incrementScore(void);
      virtual bool quit(const CEGUI::EventArgs &e);
      bool mShutDown;
      // GameState gameMode;
      bool stategui;
      bool stateplay;
      bool isGui();
      bool isPlay();
      bool isServer;
      bool isClient;
      void setPlay();
      CEGUI::String address;
      void startServerGame();
      void startClientGame();

      private:
      CEGUI::OgreRenderer* mRenderer;
      int score;
      int score2;
      CEGUI::Window *scoreBox;
      CEGUI::Window *sheet;
      CEGUI::Window *menu;
      CEGUI::Window *multiMenu;
      CEGUI::Window *editBox;
      CEGUI::Window *hostIP;
      // CEGUI::Window *sound;	
      void player1Win(bool win);
      bool startSinglePlayer(const CEGUI::EventArgs &e);
      bool startMultiPlayer(const CEGUI::EventArgs &e);
      bool multiBack(const CEGUI::EventArgs &e);
      bool startServer(const CEGUI::EventArgs &e);
      bool clientBack(const CEGUI::EventArgs &e);
      bool clientStart(const CEGUI::EventArgs &e);
      bool searchIP(const CEGUI::EventArgs &e);


};

#endif // #ifndef __GUI_h_