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
      void resetScore();
      int score;
      int score2;
      int highScore;

      virtual bool quit(const CEGUI::EventArgs &e);
      bool mShutDown;
      // GameState gameMode;
      bool stategui;
      bool stateplay;
      bool isGui();
      bool isServer;
      bool isClient;
      CEGUI::String address;
      void startServerGame();
      void startClientGame();

      bool startingSinglePlayer;
      bool startingMultiPlayer;
      bool playingSingle;
      bool playingServer;
      bool playingClient;

      private:
      CEGUI::OgreRenderer* mRenderer;
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